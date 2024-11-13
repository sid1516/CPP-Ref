#include <memory>
#include <iostream>
#include <type_traits>
#include <stdexcept>

template <typename T>
class function;

template <typename Ret, typename... Params>
class function<Ret(Params...)> {
private:
    struct callable_interface {
        virtual ~callable_interface() = default;
        virtual Ret call(Params... params) const = 0;
        [[nodiscard]] virtual std::unique_ptr<callable_interface> clone() const = 0;
    };

    template <typename Callable>
    struct callable_impl : callable_interface {
        Callable callable;

        callable_impl(const Callable& callable) : callable(callable) {}
        callable_impl(Callable&& callable) : callable(std::move(callable)) {}

        Ret call(Params... params) const override {
            return callable(params...);
        }

        std::unique_ptr<callable_interface> clone() const override {
            return std::make_unique<callable_impl<Callable>>(callable);
        }
    };

    std::unique_ptr<callable_interface> pimpl_;

public:
    function() = default;

    template <typename FunctionObject>
    function(FunctionObject&& functionObject)
        : pimpl_(std::make_unique<callable_impl<std::decay_t<FunctionObject>>>(
            std::forward<FunctionObject>(functionObject))) {}

    function(const function& other) : pimpl_(other.pimpl_ ? other.pimpl_->clone() : nullptr) {}

    function(function&& other) noexcept : pimpl_(std::move(other.pimpl_)) {}

    function& operator=(const function& other) {
        if (this != &other && other.pimpl_ != nullptr) {
            pimpl_ = other.pimpl_->clone();
        }
        return *this;
    }

    function& operator=(function&& other) noexcept {
        if (this != &other) {
            pimpl_ = std::move(other.pimpl_);
        }
        return *this;
    }

    Ret operator()(Params... params) const {
        if (!pimpl_) {
            throw std::exception();
        }
        return pimpl_->call(params...);
    }
};

int add(int x, int y) {
    return x + y;
}

int main() {
    function<int(int, int)> f([](int x, int y) { return x + y; });
    std::cout << f(3, 6) << std::endl;
}
