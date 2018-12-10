#include "anagrames.hpp"
#include "word_toolkit.hpp"

anagrames::anagrames() throw(error) : _quants(0) {
    _M = 101;   //podria ser dinamic
    _taula = new node_hash*[_M];
    
    for(size_t i = 0; i < _M; i++)
    {
        _taula[i] = NULL;
    }   
}

anagrames::node_hash::node_hash(const string &k, const list<string> &v, node_hash* seg) throw(error) : _k(k), _v(v), _seg(seg) {

}

anagrames::anagrames(const anagrames& A) throw(error) {

}

anagrames& anagrames::operator=(const anagrames& A) throw(error) {

}

anagrames::~anagrames() throw() {

}

void anagrames::insereix(const string& p) throw(error) {
    diccionari::insereix(p);

    string p_canonic = word_toolkit::anagrama_canonic(p);
    int i = hash(p_canonic);
    node_hash *punter = _taula[i];
    bool trobat = false;
    while (punter != NULL && !trobat)
    {
        if (punter->_k == p_canonic)
        {
            trobat = true;
        }
        else
        {
            punter = punter->_seg;
        }
    }
    if (trobat)
    {
        // Només canviem el valor associat
        punter->_v.push_front(p);
    }
    else
    {
        // Cal crear un nou node i l'afegim al principi
        list<string> llista_valors;
        llista_valors.push_front(p);
        _taula[i] = new node_hash(p_canonic, llista_valors, _taula[i]);
        ++_quants;
    }
}

void anagrames::mateix_anagrama_canonic(const string& a, list<string>& L) const throw(error)
{
    //string p_canonic = word_toolkit::anagrama_canonic(a); 
    if (!word_toolkit::es_canonic(a)) throw (NoEsCanonic);
    int i = hash(a);
    node_hash *punter = _taula[i];
    bool hi_es = false;
    while (punter != NULL && !hi_es)
    {
        if (punter->_k == a)
        {
            hi_es = true;
            L = punter->_v;
        }
        else
        {
            punter = punter->_seg;
        }
    }
}