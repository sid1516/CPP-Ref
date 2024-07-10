#include <iostream>


//allows for static polymorphism that removes the need for a virtual table
template <typename Derived>
struct Animal {
    void speak() const{
        const Derived& d = static_cast<const Derived&>(*this);
        d.speak();
    }
};

//provides its own implementation of 
struct Cat : public Animal<Cat> {
    void speak() const {
        std::cout << "Meow!" << "\n";
    }
};

struct Dog: public Animal<Dog> {
    void speak() const {
        std::cout << "Woof!" << "\n";
    }
};

//general interface that will work for all animals that use CRTP
template <typename T>
void recordSound(const Animal<T>& animal) {
    animal.speak();
}


int main() {
    Dog d;
    Cat c;
    recordSound(d);
    recordSound(c);
}