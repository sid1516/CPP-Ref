#include "foo-temp.hpp"

//We provide the definitions within the header so the compiler can perform the instantiations
int main()
{
    Foo<int> f_int;
    std::cout << f_int.getVar() << "\n";

    Foo<double> f_dub;
    std::cout << f_dub.getVar() << "\n";
}