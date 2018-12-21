#include <list>
#include <iterator>
#include <iostream>
#include "anagrames.hpp"
#include "diccionari.hpp"
using namespace std;

int main() {
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
    //anagrames b;
    
    b.insereix("CORRRR");
    b.insereix(par1);
    b.insereix(par3);
    b.insereix(par4);

    anagrames c = a;
    cout << "anagrames a numero paraules " << a.num_pal() << endl;
    cout << "anagrames b numero paraules " << b.num_pal() << endl;
    cout << "anagrames c numero paraules " << c.num_pal() << endl;
    if (a == b) {
      cout << "true" << endl;
    } else {
      cout << "false" << endl;
    }
    if (a == c) {
      cout << "true" << endl;
    } else {
      cout << "false" << endl;
    }
    
    /*cout << "anagrames a numero paraules " << a.num_pal() << endl;
    list<string> l;
    a.mateix_anagrama_canonic("COORR", l);
    while (!l.empty()) {
        cout << l.front() << endl;
        l.pop_front();
    }
    cout << "anagrames b numero paraules " << b.num_pal() << endl;
    list<string> l2;
    b.mateix_anagrama_canonic("COORR", l2);
    while (!l2.empty()) {
        cout << l2.front() << endl;
        l2.pop_front();
    }

    diccionari d;
    d.insereix(par1);
    d.insereix(par2);
    d.insereix(par3);
    d.insereix(par4);
    d.insereix(par5);
    diccionari e(d);
    cout << "diccionari d numero paraules " << d.num_pal() << endl;
    list<string> l3;
    d.llista_paraules(0, l3);
    while (!l3.empty()) {
        cout << l3.front() << endl;
        l3.pop_front();
    }
    cout << "diccionari e numero paraules " << e.num_pal() << endl;
    e.llista_paraules(0, l3);
    while (!l3.empty()) {
        cout << l3.front() << endl;
        l3.pop_front();
    }

    return 0;*/
}
