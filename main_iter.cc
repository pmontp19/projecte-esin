#include <iostream>
#include <sstream>
#include <cstdio>
#include "iter_subset.cpp"
using namespace std;

int main()
{
    string linea, comanda;
    int valor1, valor2;
    while (getline(cin, linea))
    {
        // Obtenim elements de la llista
        istringstream ss1(linea);
        ss1 >> valor1;
        ss1 >> valor2;

        iter_subset C(valor1,valor2);
        iter_subset C2(valor1,valor2);

        // Processem comandes
        while (getline(cin, linea) and linea != "----------")
        {
            cout << linea << ": ";
            istringstream ss2(linea);
            ss2 >> comanda;

            if (comanda == "preincrement")
            {
                ++C;
            }
            else if (comanda == "postincrement")
            {
                C++;
            }
            else if (comanda == "igual")
            {
                if (C==C2) cout << "true";
                else cout << "false";
            }
            else if (comanda == "diferent")
            {
                if (C!=C2) cout << "true";
                else cout << "false";
            }
            else if (comanda == "print")
            {
                subset actual = *C;
                for(int i=0; i < actual.size(); i++) {
                    cout << actual[i] << ' ';
                }
                //c++98 no sho menja
                /*for(auto s: actual) {
                    cout << s << ' ';
                }*/
            }
            cout << endl;
        }
        if (linea == "----------")
            cout << linea << endl;
    }
}
