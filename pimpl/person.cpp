#include "person.hpp"

struct Person::Impl {
    std::string forname_;
    std::string surname_;
    int yearOfBirth;
};

Person::Person(const std::string& forname, const std::string& surname, int yearOfBirth) {
    pimpl_ = std::make_unique<Person::Impl>(forname, surname, yearOfBirth);
}
Person::Person(const Person& rhs): pimpl_{std::make_unique<Person::Impl>(*rhs.pimpl_)} {

}
Person& Person::operator=(const Person& rhs) {
    *pimpl_ = *rhs.pimpl_;
    return *this;
}
Person::Person(Person&& rhs): pimpl_{std::make_unique<Person::Impl>(std::move(*rhs.pimpl_))} {

}
Person& Person::operator=(Person&& rhs) {
    *pimpl_ = std::move(*rhs.pimpl_);
    return *this;
}

Person::~Person() = default;