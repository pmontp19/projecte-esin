#include "word_toolkit.hpp"
#include <iostream>

int main()
{
    string s = "hola";
    bool result = word_toolkit::es_canonic(s);
    
    if (result) {
        std::cout << "hola es canonic";
    }
    else {
        std::cout << "hola no es canonic";
    }
    s = "ahlo";
    result = word_toolkit::es_canonic(s);
    
    if (result) {
        cout << "ahlo es canonic";
    }
    else {
        cout << "ahlo no es canonic";
    }
    

    return 0;
}
