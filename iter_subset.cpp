#include "iter_subset.hpp"

iter_subset::iter_subset(nat n, nat k) throw(error): n(n), k(k), actual(k){
  /*Pre: Cert
  Construeix un iterador sobre els subconjunts de k elements 
  de {1, ..., n}; si k > n no hi ha res a recórrer. 
  Cost: O(k) */
  final = false;
  final = k > n;
  for(nat i = 0; i< k; i++){
      actual[i] = i+1;
    }
  }

iter_subset::iter_subset(const iter_subset& its) throw(error){
  /*Pre: Cert
  Post: Constructor per còpia
  Cost: constant O(1)*/
  n = its.n;
  k = its.k;
  actual = its.actual;
  final = its.final;
}

iter_subset& iter_subset::operator=(const iter_subset& its) throw(error){
  /*Pre: Cert
  Post: operador d'assignació
  Cost: constant O(1)*/
  n = its.n;
  k = its.k;
  actual = its.actual;
  final = its.final;
  return *this;

}
iter_subset::~iter_subset() throw(){
  /*Pre: Cert
  Post: destructor
  Cost: */
  k = 0;
  n = 0;
  actual.erase(actual.begin(),actual.end());
  final = true;
}
bool iter_subset::end() const throw(){
  /*Pre: Cert
  Post: Retorna cert si l'iterador ja ha visitat tots els subconjunts
  de k elements presos d'entre n; o dit d'una altra forma, retorna
  cert quan l'iterador apunta a un subconjunt sentinella fictici 
  que queda a continuació de l'últim subconjunt vàlid.
  Cost: constant O(1)*/
  return final;
}
subset iter_subset::operator*() const throw(error){
  /*Pre: Cert
  Post: Operador de desreferència. Retorna el subconjunt apuntat per
  l'iterador; llança un error si l'iterador apunta al sentinella.
  Cost: constant O(1)*/
  if (final) throw error(IterSubsetIncorr);
  return actual;

}

iter_subset& iter_subset::operator++() throw(){
  /*Pre: Cert
  Post: Operador de preincrement. 
  Avança l'iterador al següent subconjunt en la seqüència i el retorna; 
  no es produeix l'avançament si l'iterador ja apuntava al sentinella.
  Cost: O(k) */
  bool acabat = false, modificat = false;
  nat i, j, max;
  max = n;

  if (k > 0 && !final) {
    for (i = k - 1; !acabat && !modificat; i--) {
      if (actual[i] < max - (k - 1) + i) {  //calcula que no sigui el valor maxim
        actual[i]++;
        if (i < k - 1) {
          for (j = i + 1; j < k; j++) {
            actual[j] = actual[j - 1] + 1;  //+1 de l'anterior fins al final
          }
        }
        modificat = true;
      }
      if (i==0) acabat = true;
    }
    if (!modificat) {
      //si no s'ha modificat vol dir que estem al final
      final = true;
    }
  }
  //si k<=0 final
  else final = true;

  return *this;
}
iter_subset iter_subset::operator++(int) throw(){
  /*Pre: Cert
  Post: Operador de postincrement. 
  Avança l'iterador al següent subconjunt en la seqüència i retorna el seu valor
  previ; no es produeix l'avançament si l'iterador ja apuntava al sentinella.
  Cost: O(k) */
  return ++*this;
}
bool iter_subset::operator==(const iter_subset& c) const throw(){
  /*Pre: Cert
  Post: Operadors relacionals.
  Cost: O(k) */
  bool iguals = true;
  nat i = 0;
  if(n != c.n) iguals = false;
  if(c.end() != final) iguals = false;
  while (i < k && iguals){
    if( c.actual[i] == actual[i]) i++;
    else iguals = false;
    }
  return iguals;
}
bool iter_subset::operator!=(const iter_subset& c) const throw(){
  /*Pre: Cert
  Post: Operadors relacionals.
  Cost: o(k) */
  return !(actual==c.actual);

}