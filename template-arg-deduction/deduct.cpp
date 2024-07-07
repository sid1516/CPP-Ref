
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

