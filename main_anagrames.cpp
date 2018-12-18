#include <list>
#include <iterator>
#include <iostream>
#include "anagrames.hpp"
#include "diccionari.hpp"
using namespace std;

int main()
{

    anagrames a;
    string par1 = "CORRO";
    string par2 = "CORRO";
    string par3 = "CORRO";
    string par4 = "CACAA";
    string par5 = "CZCAA";
    a.insereix(par1);
    a.insereix(par2);
    a.insereix(par3);
    a.insereix(par4);
    a.insereix(par5);
    anagrames b(a);
    cout << "numero paraules " << a.num_pal() << endl;
    list<string> l;
    a.mateix_anagrama_canonic("COORR", l);
    while (!l.empty()) {
        cout << l.front() << endl;
        l.pop_front();
    }
    cout << "numero paraules " << b.num_pal() << endl;
    list<string> l2;
    b.mateix_anagrama_canonic("COORR", l2);
    while (!l2.empty()) {
        cout << l2.front() << endl;
        l.pop_front();
    }

   /* diccionari a;
    string par1 = "CORRO";
    string par2 = "CORRO";
    string par3 = "CORRO";
    string par4 = "CACAA";
    string par5 = "CZCAA";
    a.insereix(par1);
    a.insereix(par2);
    a.insereix(par3);
    a.insereix(par4);
    a.insereix(par5);
    diccionari b(a);
    cout << "numero paraules " << a.num_pal() << endl;
    cout << "numero paraules " << b.num_pal() << endl;
    list<string> l;
    a.llista_paraules(0, l);
    while (!l.empty()) {
        cout << l.front() << endl;
        l.pop_front();
    }
    b.llista_paraules(0, l);
    while (!l.empty()) {
        cout << l.front() << endl;
        l.pop_front();
    }
*/
    return 0;
}
