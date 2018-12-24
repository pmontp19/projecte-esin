#include "iter_subset.hpp"

iter_subset::iter_subset(nat n, nat k) throw(error): _n(n), _k(k), _actual(k) {
  /** 
   * Pre:  k <= n.
   * Post: Construeix un iterador sobre els subconjunts de k elements 
   *       de {1, ..., n}; si k > n no hi ha res a recórrer. 
   * Cost: O(k) sent k el tamany del subset.
  */
  _final = false;
  _final = _k > _n;
  for (nat i = 0; i< _k; i++) {
    _actual[i] = i+1;
  }
}

iter_subset::iter_subset(const iter_subset& its) throw(error) {
  /** 
   * Pre:  Cert.
   * Post: Constructor per còpia.
   * Cost: constant O(1).
  */
  _n = its._n;
  _k = its._k;
  _actual = its._actual;
  _final = its._final;
}

iter_subset& iter_subset::operator=(const iter_subset& its) throw(error) {
  /** 
   * Pre:  Cert.
   * Post: Operador d'assignació.
   * Cost: Constant O(1).
  */
  _n = its._n;
  _k = its._k;
  _actual = its._actual;
  _final = its._final;
  return *this;
}

iter_subset::~iter_subset() throw() {
  /** 
   * Pre:  Cert.
   * Post: Destructor.
   * Cost: O(k) sent k el tamany del subset.
  */
  _k = 0;
  _n = 0;
  _actual.erase(_actual.begin(), _actual.end());
  _final = true;
}

bool iter_subset::end() const throw() {
  /** 
   * Pre:  Cert.
   * Post: Retorna cert si l'iterador ja ha visitat tots els subconjunts
   *       de k elements presos d'entre n; o dit d'una altra forma, retorna
   *       cert quan l'iterador apunta a un subconjunt sentinella fictici 
   *       que queda a continuació de l'últim subconjunt vàlid.
   * Cost: Constant O(1).
  */
  return _final;
}

subset iter_subset::operator*() const throw(error) {
  /** 
   * Pre:  Cert.
   * Post: Operador de desreferència. Retorna el subconjunt apuntat per
   *       l'iterador; llança un error si l'iterador apunta al sentinella.
   * Cost: Constant O(1).
  */
  if (_final) throw error(IterSubsetIncorr);
  return _actual;
}

iter_subset& iter_subset::operator++() throw() {
  /** 
   * Pre:  Cert.
   * Post: Operador de preincrement. 
   *       Avança l'iterador al següent subconjunt en la seqüència i el retorna; 
   *       no es produeix l'avançament si l'iterador ja apuntava al sentinella.
   * Cost: O(k) sent k el tamany del subset.
  */
  bool acabat = false, modificat = false;
  nat i, j, max;
  max = _n;

  if (_k > 0 && !_final) {
    for (i = _k - 1; !acabat && !modificat; i--) {
      if (_actual[i] < max - (_k - 1) + i) {  // calcula que no sigui el valor maxim
        _actual[i]++;
        if (i < _k - 1) {
          for (j = i + 1; j < _k; j++) {
          _actual[j] = _actual[j - 1] + 1;  // +1 de l'anterior fins al final
          }
        }
      modificat = true;
      }
      if (i == 0) acabat = true;
    }
    if (!modificat) {
      // si no s'ha modificat vol dir que estem al final
      _final = true;
    }
  } else {  // si k<=0 final
    _final = true;
  }
  return *this;
}
iter_subset iter_subset::operator++(int) throw() {
  /** 
   * Pre:  Cert.
   * Post: Operador de postincrement. 
   *       Avança l'iterador al següent subconjunt en la seqüència i retorna el seu valor
   *       previ; no es produeix l'avançament si l'iterador ja apuntava al sentinella. 
   * Cost: O(k) sent k el tamany del subset.
  */
  return ++*this;
}

bool iter_subset::operator==(const iter_subset& c) const throw() {
  /** 
   * Pre:  Cert.
   * Post: Operadors relacionals.
   *       Es compara totes les variables de iter_subset.
   * Cost: O(k) sent k el tamany del subset.
  */
  bool iguals = true;
  nat i = 0;

  if ( (_n != c._n || _k != c._k) && (_k != 0 && c._k != 0) ) iguals = false;
  if (c.end() != _final) iguals = false;
  while (i < _k && iguals) {
    if (c._actual[i] == _actual[i])
      i++;
    else
      iguals = false;
  }
  return iguals;
}
bool iter_subset::operator!=(const iter_subset& c) const throw() {
  /** 
   * Pre:  Cert.
   * Post: Operadors relacionals.
   * Cost: O(k) sent k el tamany del subset.
  */
  return !(*this == c);
}
