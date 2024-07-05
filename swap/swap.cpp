#include <type_traits>
#include <iostream>

//Uses SFINAE to call the appropriate swap function based on whether the type called is move constructible and move assignable
namespace OldImpl {
    // Enable for types that are both move constructible and move assignable
    template<typename T, typename = std::enable_if_t<std::is_move_constructible_v<T> && std::is_move_assignable_v<T>>>
    void swap(T& a, T& b) noexcept {
        std::cout << "Old Impl of swap called for move constructible and move assignable type\n";
        T temp = std::move(a);
        a = std::move(b);
        b = std::move(temp);
    }

    // Enable for types that are not move constructible or not move assignable
    template<typename T, typename = std::enable_if_t<!std::is_move_constructible_v<T> || !std::is_move_assignable_v<T>>, typename = void>
    void swap(T& a, T& b) {
        std::cout << "Old Impl of swap called for non move constructible or non move assignable type\n";
        T temp = a;
        a = b;
        b = temp;
    }
}

//Uses C++20 Concepts feature to call the appropriate swap function based on whether the type called is move constructible and move assignable
namespace NewImpl {
    template<typename T>
    concept MoveConstructibleAndAssignable = std::is_move_constructible_v<T> && std::is_move_assignable_v<T>;

    template<typename T>
    concept NotMoveConstructibleOrAssignable = !std::is_move_constructible_v<T> || !std::is_move_assignable_v<T>;

    template<MoveConstructibleAndAssignable T>
    void swap(T& a, T& b) noexcept { 
        std::cout << "New Impl of swap called for move constructible and move assignable type\n";
        T temp = std::move(a);
        a = std::move(b);
        b = std::move(temp);
    }
    template<NotMoveConstructibleOrAssignable T>
    void swap(T& a, T& b) {
        std::cout << "New Impl of swap called for non move constructible or non move assignable type\n";
        T temp = a;
        a = b;
        b = temp;
    }
};

struct A {

};

struct B {
    B() = default;
    B(B&) = default;
    B& operator=(B&) = default;
    B(B&&) = delete;
    B& operator=(B&&) = delete;
};

int main() {
    A a1, a2;
    B b1, b2;
    OldImpl::swap(a1, a2); //calls old impl of move constructible and assignable type
    OldImpl::swap(b1, b2); //calls old impl of non move constructible and assignable type
    NewImpl::swap(a1, a2); //calls new impl of move constructible and assignable type
    NewImpl::swap(b1, b2); //calls new impl of non move constructible and assignable type
}
