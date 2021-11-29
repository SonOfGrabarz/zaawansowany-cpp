#include <iostream>
#include <math.h>

// zadanie 5
template <typename T, typename U>
auto add1(T *a, U *b) {
    // przekazanie przez wskazniki
    std::cout << "przez wskazniki: ";
    return *a + *b;
}

template <>
auto add1<const char>(const char* x, const char* y) {
    // laczenie tekstow przekazanych jako const char*
    std::cout << "przez const char*: ";
    std::string a = x;
    std::string b = y;
    return a + b;
}

// zadanie 6
template <typename T, typename U>
constexpr auto hiperszescian(T a, U b) -> decltype (pow(a, b)){
    // przypadek kiedy podamy ujemna dlugosc boku lub ilosc wymiaru
    if (a < 0 || b < 0){
        return -1;
    }

    // obliczenie objetosci hiperszescianu
    else{
        return pow(a, b);
    }
}

// zadanie 7 (z wykladu)
template <typename T, typename ... Args>
T add(T first, Args ... args) {
    if constexpr(sizeof...(args) == 0) {
        return first;
    } 

    else {
        return first + add(args...);
    }
}


int main(){

    // zadanie 5
    std::cout << "ZADANIE5" << '\n';
    int num1;
    float num2;
    int *num_ptr1;
    float *num_ptr2;

    num1 = 21;
    num2 = 1.1;

    const char* first = "M";
    const char* second = "S";

    num_ptr1 = &num1;
    num_ptr2 = &num2;

    std::cout << add1(num_ptr1, num_ptr2) << '\n';
    std::cout << add1(first, second) << "\n\n";

    // zadanie 6
    std::cout << "ZADANIE6" << '\n';
    std::cout << "HIPERSZESCIAN(6 BOKOW, 7 WYMIAROW): " << hiperszescian(6, 7) << "\n\n";

    // zadanie 7
    std::cout << "ZADANIE7" << '\n';
    int i = 1;
    double j = 1.0;
    float k = 1.0f;
    std::cout << add(i, j, k) << '\n';


    return 0;
}