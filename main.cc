#include <iostream>
#include <sstream>
#include <list>
#include "word_toolkit.cpp"
using namespace std;

int main()
{
    string linea, comanda, word, excl;
    while (getline(cin, linea))
    {
        list<string> paraules;

        // Obtenim elements de excl
        istringstream ss1(linea);
        ss1 >> excl;

        // Obtenim elements de la llista
        while (ss1 >> word)
        {
            paraules.push_back(word);
        }

        // Processem comandes
        while (getline(cin, linea) and linea != "----------")
        {
            cout << linea << ": ";
            istringstream ss2(linea);
            ss2 >> comanda;

            if (comanda == "insereix")
            {
                ss2 >> word;
                paraules.push_back(word);
                cout << paraules.size();
            }
            else if (comanda == "elimina")
            {
                ss2 >> word;
                paraules.remove(word);
                cout << paraules.size();
            }
            else if (comanda == "quants")
            {
                cout << paraules.size();
            }
            else if (comanda == "print")
            {
                for (auto w : paraules)
                {
                    cout << w << ' ';
                }
            }
            else if (comanda == "es_canonic")
            {
                ss2 >> word;
                cout << word_toolkit::es_canonic(word);
            }
            else if (comanda == "anagrama_canonic")
            {
                ss2 >> word;
                cout << word_toolkit::anagrama_canonic(word);
            }
            else if (comanda == "mes_frequent")
            {
                //cout << "mes frequent es ";
                cout << word_toolkit::mes_frequent(excl, paraules);
            }
            cout << endl;
        }
        if (linea == "----------")
            cout << linea << endl;
    }
}
