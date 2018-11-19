#include "word_toolkit.cpp"
#include <iostream>

int main()
{
    string s = "HOLA";
    bool result = word_toolkit::es_canonic(s);
    
    if (result) {
        std::cout << "HOLA es canonic"  << endl;
    }
    else {
        std::cout << "HOLA no es canonic" << endl;
    }
    s = "AHLO";
    result = word_toolkit::es_canonic(s);
    
    if (result) {
        cout << "AHLO es canonic" << endl;
    }
    else {
        cout << "AHLO no es canonic"  << endl;
    }

    cout << "anagrama canonic de HOLA es ";
    s = "HOLA";
    cout << word_toolkit::anagrama_canonic(s);
    cout << endl;

    initializer_list<string> paraules = { "HOLA", "ADEU", "JARDINER", "CLASSE", "TAULA", "PARAULA", "ESTUDI"};
    string exclosos = "DA";
    cout << "mes frequent es ";
    cout << word_toolkit::mes_frequent(exclosos,paraules);
    cout << endl;

    return 0;
}
