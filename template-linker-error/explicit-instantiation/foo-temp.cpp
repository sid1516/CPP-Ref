#include "foo-temp.h"

template <typename T>
T Foo<T>::getVar()
{
    return var_;
}

template struct Foo<int>;
template struct Foo<double>;