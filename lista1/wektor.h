#include <cstddef>
#include <iostream>
#include <vector>

template <typename T, std::size_t s>
class Wektor{
private:
    T tab[s];

public: 
    typedef T value_type;

    Wektor(){
        for( std::size_t i = 0; i < s; i++ ){
            tab[i] = 0;
        }
    }

    std::size_t size() const{
        return s;
    }

    // do modyfikacji
    T& operator[](std::size_t N){
        return tab[N];
    }

    // do odczytu
    T const& operator[](std::size_t N) const{
        return tab[N];
    }
};

template <typename T, typename U>
auto operator* (T const& x, U const& y){
    if (x.size() != y.size() || x.size() == 0 || y.size() == 0){
        throw std::length_error("Wektor and vector aren't the same length");
    }
    else{
        auto result = x[0] * y[0];
        for(std::size_t i = 1; i < x.size(); i++){
            result += x[i] * y[i];
        }
        return result;
    }
}