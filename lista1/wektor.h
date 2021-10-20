// template <typename T, typename U>
template <typename T>
class Wektor{
public:
    typedef T value_type;
    // U size;
    Wektor(T argX, T argY, T argZ)
    : x(argX), y(argY), z(argZ)
    { }

    T x, y, z;
};