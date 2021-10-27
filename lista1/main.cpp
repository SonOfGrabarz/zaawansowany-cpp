#include "wektor.h"

// zadanie 1
template <typename T, typename U>
auto add1(T a, U b){
    return a + b;
}

// zadanie 2
template <typename T, typename U, typename W>
auto add2(T x, U y, W z){
    return z(x, y);
}

int main()
{
    std::string text1 = "Michał ";
    std::string text2 = "Szul";

    std::cout << "ZADANIE1" << '\n';
    std::cout << add1(3, 4) << '\n';
    std::cout << add1(text1, text2) << "\n\n";

    std::cout << "ZADANIE2" << '\n';
    std::cout << add2(3, 3.14, [](auto x, auto y){return x + y;}) << '\n';
    std::cout << add2(text1, text2, [](auto a, auto b){return a + b;}) << "\n\n";

    std::cout << "ZADANIE3" << '\n';
    Wektor<int, 3> wektorInt;
    for ( int i = 0; i < 3; i++ ){
        std::cout << wektorInt[i] << '\n';
    }

    Wektor<float, 3> wektorFloat;
    for (int i = 0; i < 5; i++){
        std::cout << wektorFloat[i] << '\n';
    }

    std::cout << '\n' << "ZADANIE4" << '\n';
    const std::vector<float> m = {1.0f, 2.0f, 3.0f};
    const std::vector<float> n = {1.0f, 1.0f};

    std::cout << m * wektorInt << '\n';

    return 0;
}