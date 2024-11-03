#include <memory>
#include <iostream>
#include <array>
struct Animal {
    virtual ~Animal() = default;
    virtual void speak() const = 0;
    virtual std::unique_ptr<Animal> clone() const = 0;
};

struct Dog : public Animal {
    void speak() const override {
        std::cout << "Woof!" << std::endl;
    }
    std::unique_ptr<Animal> clone() const override {
        return std::make_unique<Dog>(*this);
    }
};

struct Cat : public Animal {
    void speak() const override {
        std::cout << "Meow!" << std::endl;
    }
    std::unique_ptr<Animal> clone() const override {
        return std::make_unique<Cat>(*this);
    }
};

int main() {
    std::array<std::unique_ptr<Animal>, 2> arr = {std::make_unique<Dog>(), std::make_unique<Cat>()};
    for(const auto& animal : arr) {
        auto clonedAnimal = animal -> clone();
    }
}
