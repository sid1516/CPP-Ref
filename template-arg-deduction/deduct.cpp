
//By Value: references and cv-qualifiers from expr are ignored, pattern match expr with T
/*  template <typename T>
    void func(T param);
    func(expr);
*/

//By Reference/Pointer: Ignore reference and pattern match expr type against parameter to determine T
/*
    template <typename T>
    void func(T& param);
    func(expr);
*/

//By Universal Reference: If expr is l-value, then T is l-value ref and through reference decaying so is argument, if expr is r-value ref then T is just the type, and the argument is T&&
/*
    template <typename T>
    void func(T&& param);
    func(expr);
*/

/*
    decltype(auto) type deduction
    decltype(name): doesn’t strip cv qualifiers, or reference, deduces the exact type of the name
    decltype(lvalue expression of type T) = T&
    int a; decltype(a) deduces int and not int& as a isn’t an expression
    decltype(prvalue expression of type T) = T
    decltype(xvalue expression of type T) = T&& 
    Uses std::move 
*/
