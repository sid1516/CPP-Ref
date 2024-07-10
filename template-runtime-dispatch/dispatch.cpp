#include <iostream>
#include <set>

struct Foo {
    std::set<int, std::greater<int>> s1;
    std::set<int> s2;
};

//
template <bool b>
auto& getSet(const Foo& f) {
    if constexpr(b) {
        return f.s1;
    } else {
        return f.s2;
    }
}


//getting a common reference decreases branching and prevent code duplication
template <bool b>
void handleUpdate(const Foo& f) {
    auto& set_ref = getSet<b>(f);
    //do stuff
}

//explicitly calling the types for each template triggers the template instantiation
void updateSet(bool b, const Foo& f) {
    if(b) {
        handleUpdate<true>(f);
    } else {
        handleUpdate<false>(f);
    }
}


// https://cppinsights.io/s/0a40f61c

int main() {
    
}