#include <iostream>

#include "foo-temp.h"

//By specifying the explicit instantiations of the types being used, the linker will be able to find them
//Compile: g++ -std=c++20 main.cpp foo-temp.cpp
int main()
{
    Foo<int> f_int;
    std::cout << f_int.getVar() << "\n";

    Foo<double> f_dub;
    std::cout << f_dub.getVar() << "\n";
}