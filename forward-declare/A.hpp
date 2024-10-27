#pragma once

class B;

//https://stackoverflow.com/questions/9906402/should-one-use-forward-declarations-instead-of-includes-wherever-possible
//can forward declare classes in method declarations that use the incomplete type as a return type, function arg, or ref/ptr as a member
class A {
public:
    B foo();
    void doWork(B copy, B& ref, B* ptr);

private:
    B* m_ptr;
    B& m_ref;
};