#include <iostream>

// zadanie 1
template <typename T, typename U>
auto add1(T a, U b){
    return a + b;
}

template <typename T, typename U>
auto add1(T *a, U *b){
    return *a + *b;
}


// template <typename T, typename U, typename W>
// auto add2(T x, U y, W z){
//     return z(x, y);
// }

int main(){

    int num1, num2;
    int *ptr1, *ptr2;
    const char* str1;
    const char* str2;

    num1 = 4;
    num2 = 5;
    char first = 'C';
    char second = 'J';

    ptr1 = &num1;
    ptr2 = &num2;
    str1 = &first;
    str2 = &second;

    std::cout << add1(ptr1, ptr2) << '\n';
    std::cout << add1(str1, str2) << '\n';

    return 0;
}