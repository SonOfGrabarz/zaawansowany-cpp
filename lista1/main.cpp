#include "wektor.h"

// zadanie 1
void add1(int a, float b){
    std::cout << a + b << '\n';
}

int add1(int a, int b){
    return a + b;
}

std::string add1(std::string a, std::string b){
    return a + b;
}

// zadanie 2
template <typename T, typename U, typename W>
auto add2(T x, U y, W z){
    return z(x, y);
}

int main()
{
    std::cout << "ZADANIE1" << '\n';
    add1(314, 3.14f);
    std::cout << add1(3, 4) << '\n';
    std::cout << add1("Michal ", "Szul") << '\n';

    std::cout << "ZADANIE2" << '\n';
    std::cout << add2(3, 3.14, [](auto x, auto y){return x + y;}) << '\n';
    std::string a = "Michal ";
    std::string b = "Szul";
    std::cout << add2(a, b, [](auto a, auto b){return a + b;}) << '\n';

    std::cout << "ZADANIE3" << '\n';
    Wektor<float, 3> wektor;
    for ( int i = 0; i < 3; i++ ){
        std::cout << wektor[i] << '\n';
    }

    return 0;
}