#include <iostream>

template <typename T>
class Base{
public:
  void func1() const {
    std::cout << "func1()" << std::endl;
  }
  void func2() const {
    std::cout << "func2()" << std::endl;
  }
  void func3() const {
    std::cout << "func3()" << std::endl;
  }
};

template <typename T>
class Derived: public Base<T>{
public:
  using Base<T>::func2;
  
  void callAllBaseFunctions(){
    this->func1();
    func2();
    Base<T>::func3();
  }
};
//Three Ways to call a Base template method from the derived class
//1. Use qualification via pointer.
//2. Use a using declaration.
//3. Explicitly qualifiying the call.
int main(){
  std::cout << std::endl;

  Derived<int> derived;
  derived.callAllBaseFunctions();

  std::cout << std::endl;
}