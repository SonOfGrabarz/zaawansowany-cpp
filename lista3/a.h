#include <iostream>

class A {
    private:
        char* content;

    public:
        // konstruktory:
        // przyjmujacy stala referencje 
        A(const std::string& text);
        // kopiujacy ( const l-value reference )
        A(const A& org);
        // przenoszacy ( r-value reference )
        A(A&& org) noexcept;
        // metoda zwracajaca wskaznik do przechowywanego obiektu
        const char* get();
        ~A();
};