#include <iostream>

// zadanie 5
template <typename T, typename U>
auto add1(T *a, U *b){
    return *a + *b;
}

template <typename T, typename U>
auto add2(const T x, const U y){
    std::string a = x;
    std::string b = y;
    return a + b;
}

// zadnie 6

int main(){

    // zadanie 5
    std::cout << "ZADANIE5" << '\n';
    int num1, num2;
    int *num_ptr1, *num_ptr2;

    num1 = 21;
    num2 = 11;

    const char* first = "M";
    const char* second = "S";

    num_ptr1 = &num1;
    num_ptr2 = &num2;

    std::cout << add1(num_ptr1, num_ptr2) << '\n';
    std::cout << add2(first, second) << "\n\n";

    return 0;
}