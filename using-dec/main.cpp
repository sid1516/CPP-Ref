#include <iostream>

class A
{
private:
    using B = int;
    using C = double;
public:
    B foo();
    C bar();
};

//trailing return type
auto A::foo() -> B
{
    return 1;
}

//qualified name
A::C A::bar()
{
    return 1.0;
}

int main()
{
    A a;
    a.foo();
    a.bar();
}