#include <iostream>

/*
    1. Template will have ellipsis before the type: template<typename First, typename ... Rest>
    2. Function argument will have ellipsis between type and argument name: void print(const First& first, const Rest& ... rest)
    3. The recursive call to the function will have the elipsis after the arg name: print(rest...)
*/

//The base case must be declared before the recursive function so that the compiler knows that it exists
template <typename T>
void print(const T& t) {
    std::cout << t << "\n";
}

//Parameter pack accepts zero or more template arguments
//Elipsis left of the type param means the parameters are packed, Elipsis to the right means the parameter is unpacked
template <typename First, typename ... Rest>
void print(const First& first, const Rest& ... rest) {
    std::cout << first << ", ";
    print(rest...);
}


int main() {
    print(1, 2.5, "hello", 'c');
}