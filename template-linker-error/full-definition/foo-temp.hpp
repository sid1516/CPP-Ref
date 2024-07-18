#include <iostream>

template<typename T>
class Foo
{
public:
    T getVar();
private:
    T var_{};
};

template <typename T>
T Foo<T>::getVar()
{
    return var_;
}