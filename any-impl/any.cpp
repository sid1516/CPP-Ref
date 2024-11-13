#include <filesystem>
#include <iostream>
#include <type_traits>
#include <chrono>
#include <vector>
#include <string>

namespace my_impl
{
    class any
    {
    private:
        struct AnyBase {
            virtual ~AnyBase() = default;
            virtual std::unique_ptr<AnyBase> clone() const = 0;
            virtual void print() const = 0;
        };

        template <typename T>
        struct AnyConcrete : public AnyBase {
            AnyConcrete(const T& val) : val_(val) {}
            AnyConcrete(T&& val) : val_(std::move(val)) {}
            std::unique_ptr<AnyBase> clone() const override {
                return std::make_unique<AnyConcrete>(val_);
            }
            void print() const override {
                std::cout << val_ << std::endl;
            }

        private:
            T val_;
        };

        std::unique_ptr<AnyBase> pimpl_;

    public:
        constexpr any() noexcept = default;

        template <typename T>
        any(T&& val) : pimpl_(std::make_unique<AnyConcrete<std::decay_t<T>>>(std::forward<std::decay_t<T>>(val))) {}

        any(const any& other) : pimpl_(other.pimpl_ ? other.pimpl_->clone() : nullptr) {}

        any& operator=(const any& other) {
            if (this != &other) {
                pimpl_ = other.pimpl_ ? other.pimpl_->clone() : nullptr;
            }
            return *this;
        }

        any(any&& other) noexcept = default;

        any& operator=(any&& other) noexcept {
            pimpl_ = std::move(other.pimpl_);
            return *this;
        }

        bool has_value() const noexcept {
            return pimpl_ != nullptr;
        }

        void print() const {
            if (has_value()) {
                pimpl_->print();
            }
        }
    };
}

int main() {
    std::vector<my_impl::any> v{"hello", 1u, 2.4, std::string("yolo")};
    for (auto& val : v) {
        val.print();
    }
}