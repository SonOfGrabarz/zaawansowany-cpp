#include <cstddef>
#include <iostream>

template <typename value_type, std::size_t s>
class Wektor{
private:
    value_type tab[s];

public: 
    Wektor(){
        for( std::size_t i = 0; i < s; i++ ){
            tab[i] = 0;
        }
    }

    std::size_t size() const{
        return s;
    }

    value_type& operator[]( std::size_t n ){
        return tab[n];
    }
};