#include "a.h"
#include <string>
#include <type_traits>

A copy(A& org) {
    return A(org);
}

A copy (A&& org) {
    return A(std::move(org));
}

template <typename T>
A copy_template(T&& org) {
    return A(std::forward<T>(org));
}

int main() {
    std::string text = "test";

    // ZAD 8
    A obj1(text);
    std::cout << "OBJ1: " << obj1.get() << '\n';

    A obj2(obj1);
    std::cout << "OBJ2: " << obj2.get() << '\n';

    A obj3(std::move(obj2));
    std::cout << "OBJ3: " << obj3.get() << "\n \n";

    // ZAD 9
    A obj4(text);
    std::cout << "OBJ4: " << obj4.get() << '\n';

    A obj5(copy(obj4));
    std::cout << "OBJ5: " << obj5.get() << '\n';

    A obj6(copy(std::move(obj5)));
    std::cout << "OBJ6: " << obj6.get() << "\n \n";

    // ZAD 10
    A obj7(text);
    std::cout << "OBJ7: " << obj7.get() << '\n';

    A obj8(copy_template(obj7));
    std::cout << "OBJ8: " << obj8.get() << '\n';

    A obj9(copy_template(std::move(obj8)));
    std::cout << "OBJ9: " << obj9.get() << "\n \n";

    return 0;
}