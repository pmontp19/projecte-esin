#include "iter_subset.hpp"

  iter_subset::iter_subset(nat n, nat k) throw(error): n(n), k(k), actual(k){
  //PRE: Cert
  /* Construeix un iterador sobre els subconjunts de k elements 
    de {1, ..., n}; si k > n no hi ha res a recórrer. 
    Cost: */
    contador = 1;
    final = false;
  for(nat i = 0; i< k; i++){
    actual[i] = i+1;
      }
    if(k == 0 or n == 0 or k-n == 0) final = true;
    }

  iter_subset::iter_subset(const iter_subset& its) throw(error){
    /*Pre:
    Post: Constructor per còpia
    Cost: constant O(1)*/
    n = its.n;
    k = its.k;
    contador = its.contador;
    actual = its.actual;
    final = its.final;

  }

  iter_subset& iter_subset::operator=(const iter_subset& its) throw(error){
    /*Pre: Cert
    Post: operador d'assignació
    Cost: constant O(1)*/
    n = its.n;
    k = its.k;
    contador = its.contador;
    actual = its.actual;
    final = its.final;

  }
  iter_subset::~iter_subset() throw(){
    /*Pre: Cert
    Post: destructor
    Cost: */
  }
  bool iter_subset::end() throw(){
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
    //if (final) throw error;
    return actual;

  }
  iter_subset& iter_subset::operator++() throw(){
    /*Pre: Cert
    Post: Operador de preincrement. 
    Avança l'iterador al següent subconjunt en la seqüència i el retorna; 
    no es produeix l'avançament si l'iterador ja apuntava al sentinella.
    Cost: */
    int tam = n-1;
    nat num = n;
    bool acabat = false;
    if(!final){
      while(num != 0 && !acabat){
        if(actual[tam] != num ) {
          actual[tam]++;
          acabat = true;
          }
        else{
          tam--;
          num--;
        }
      }
    }
    tam = k-1;
    nat j = 0;
    final = true;
    while(j < actual.size() && final){
      if(actual[j] == n - tam){
        tam--;
        j++;
      }
      else final = false;
    }
    contador++;
    return *this;
  }
  iter_subset iter_subset::operator++(int) throw(){
    /*Pre: Cert
    Post: Operador de postincrement. 
    Avança l'iterador al següent subconjunt en la seqüència i retorna el seu valor
    previ; no es produeix l'avançament si l'iterador ja apuntava al sentinella.
    Cost: */
    int tam = n-1;
    nat num = n;
    bool acabat = false;
    if(!final){
      while(num != 0 && !acabat){
        if(actual[tam] != num ) {
          actual[tam]++;
          acabat = true;
          }
        else{
          tam--;
          num--;
        }
      }
    }
    tam = k-1;
    nat j = 0;
    final = true;
    while(j < actual.size() && final){
      if(actual[j] == n - tam){
        tam--;
        j++;
      }
      else final = false;
    }
    contador++;
    return *this;
  }
  bool iter_subset::operator==(const iter_subset& c) const throw(){
    /*Pre: Cert
    Post: Operadors relacionals.
    Cost: */
    bool t = true;
    nat i = 0;
    if(k != c.k) t = false;
    while (i < k && t){
      if( c.actual[i] == actual[i]) i++;
      else t = false;
      }
    return t;
  }
  bool iter_subset::operator!=(const iter_subset& c) const throw(){
    /*Pre: Cert
    Post: Operadors relacionals.
    Cost: */
    return !(actual==c.actual);

  }

