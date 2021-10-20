#include <cstddef>
#include <iostream>

template <typename T, std::size_t N>
class Wektor{
public:
    T &operator[]( std::size_t i ){
        return tab1[i];
    }

    T tab1[N];
};