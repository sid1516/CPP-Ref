template<typename T>
struct Foo
{
public:
    T getVar();
private:
    T var_{};
};