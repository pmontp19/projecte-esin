#include "word_toolkit.hpp"
#include <algorithm>
#define ASCII = 256
// TODO: ens cal tot l'ASCII? Funció helper per transformar nomes 27 lletres

//cost lineal
bool word_toolkit::es_canonic(const string& s) throw() {
    bool ho_es = true;
    char car = s[0];
    if (s.size() != 0) {
        for (int i = 1; i < s.size() && ho_es; i++) {
            if (s[i] > car) ho_es = false;
            else car = s[i];
        }
    }
}

string word_toolkit::anagrama_canonic(const string& s) throw() {
    return sort(s.begin(), s.end());
}

char word_toolkit::mes_frequent(const string& excl, const list<string>& L) throw() {
    int comptador[ASCII] = {0};
    list<string>::iterator it;
    string str;
    for (it = L.begin(); i != L.end(); it++) {
        str = *it;
        for (int i = 0; i < str.length(); i++) {
            comptador[str[i]]++;
            if ()
        }
    }

}