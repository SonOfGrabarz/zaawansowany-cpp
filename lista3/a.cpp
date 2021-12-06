#include "a.h"

// konstruktor przyjmujacy stala ref do obj typ string
A::A(const std::string& text) {
    // zalokowanie pamieci
    char* tmp = new char[text.size() + 1];
    // kopiowanie do pamieci zawartosci przekazanego tekstu
    std::copy(text.begin(), text.end(), tmp);
    tmp[text.size()] = '\0';
    content = tmp;
}

// konstruktor kopiujacy z arg typ const l-value ref
A::A(const A& org) {
    std::cout << "copy constructor -> ";
    std::string text = org.content;
    char* tmp = new char[text.size() + 1];
    std::copy(text.begin(), text.end(), tmp);
    tmp[text.size()] = '\0';
    content = tmp;
}

// konstruktor przenoszacy z arg typ r-value ref
A::A(A&& org) noexcept {
    std::cout << "move constructor -> ";
    this->content = org.content;
    org.content = nullptr;
}

// metoda zwracajaca wskaznik do przechowywanego tekstu
const char* A::get() {
    return content;
}

// destruktor
A::~A() {
    std::cout << "destructor \n";
    delete[] content;
}
