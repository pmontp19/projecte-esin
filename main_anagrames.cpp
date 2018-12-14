#include <list>
#include <iterator>
#include <iostream>
#include "anagrames.hpp"
#include "diccionari.hpp"
using namespace std;

int main()
{
    diccionari a;
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
    int b = a.num_pal();
    cout<<"numero paraules "<<b<<endl;
    list<string> l;
    a.llista_paraules(5,l);
    cout<<l.front()<<endl;
    cout<<l.back()<<endl;
    cout<<"lista :"<<l.size()<<endl;
    /*anagrames a;
    string par1 = "CORRO";
    string par2 = "CORRO";
    string par3 = "CORRO";
    list<string> L;
    a.anagrames::insereix(par1);
    a.anagrames::mateix_anagrama_canonic("COORR", L);
    a.insereix(par2);
    a.anagrames::mateix_anagrama_canonic("COORR", L);
    a.anagrames::insereix(par3);
    a.anagrames::mateix_anagrama_canonic("COORR", L);
    copy(L.begin(),L.end(),ostream_iterator<string>(cout, " "));*/
    return 0;
}
