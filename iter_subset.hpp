#ifndef _ITER_SUBSET_HPP
#define _ITER_SUBSET_HPP
//#include <esin/error>
//#include <esin/util>
#include <vector>

using namespace std;
using util::nat;

typedef vector<nat> subset;

class iter_subset {
public:

  /* Construeix un iterador sobre els subconjunts de k elements 
     de {1, ..., n}; si k > n no hi ha res a recórrer. */
  iter_subset(nat n, nat k) throw(error);

  /* Tres grans. Constructor per còpia, operador d'assignació i destructor. */
  iter_subset(const iter_subset& its) throw(error);
  iter_subset& operator=(const iter_subset& its) throw(error);
  ~iter_subset() throw();

  /* Retorna cert si l'iterador ja ha visitat tots els subconjunts
     de k elements presos d'entre n; o dit d'una altra forma, retorna
     cert quan l'iterador apunta a un subconjunt sentinella fictici 
     que queda a continuació de l'últim subconjunt vàlid. */
  bool end() throw();

  /* Operador de desreferència. Retorna el subconjunt apuntat per
     l'iterador; llança un error si l'iterador apunta al sentinella. */
  subset operator*() const throw(error);       

  /* Operador de preincrement. 
     Avança l'iterador al següent subconjunt en la seqüència i el retorna; 
     no es produeix l'avançament si l'iterador ja apuntava al sentinella. */
  iter_subset& operator++() throw();

  /* Operador de postincrement. 
     Avança l'iterador al següent subconjunt en la seqüència i retorna el seu valor
     previ; no es produeix l'avançament si l'iterador ja apuntava al sentinella. */
  iter_subset operator++(int) throw();

  /* Operadors relacionals. */
  bool operator==(const iter_subset& c) const throw(); 
  bool operator!=(const iter_subset& c) const throw(); 

  /* Gestió d'errors. */
  static const int IterSubsetIncorr = 31;

private: 
    #include "iter_subset.rep"
};
#endif
