#include <string>
#include <memory>
class Person {
public:
    explicit Person(const std::string& forname, const std::string& surname, int yearOfBirth);
    Person(const Person&);
    Person& operator=(const Person&);
    Person(Person&&);
    Person& operator=(Person&&);
    ~Person();
private:
    struct Impl;
    std::unique_ptr<Impl> pimpl_;
};