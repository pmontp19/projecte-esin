#include "diccionari.hpp"


diccionari::diccionari() throw(error) {
  /** 
   * Pre:  Cert
   * Post: Construeix un diccionari que conté únicament una paraula: la paraula buida.
   * Cost: O(1) constant
  */
  _arrel = new node;
  _arrel->esq = NULL;
  _arrel->cent = NULL;
  _arrel->dret = NULL;
  _arrel->valor = _especial;
  _n_paraules = 1;
}

typename diccionari::node* diccionari::copia_nodes(node *m) {
  /** 
   * Pre:  Cert.
   * Post: Copia el node i la resta de fills en un nou.
   * Cost: O(n) lineal, recorre tot l'arbre.
  */
  node *n;
  if (m == NULL) {
    n = NULL;
  } else {
    n = new node;
    n->valor = m->valor;
    n->esq = copia_nodes(m->esq);
    n->dret = copia_nodes(m->dret);
    n->cent = copia_nodes(m->cent);
  }
  return n;
}

diccionari::diccionari(const diccionari& D) throw(error) {
  /** 
   * Pre:  Cert.
   * Post: Constructor per còpia.
   * Cost: O(n) lineal.
  */
  _n_paraules = D._n_paraules;
  _arrel = copia_nodes(D._arrel);
}

diccionari &diccionari::operator=(const diccionari &D) throw(error) {
  /** 
   * Pre:  Cert.
   * Post: Operador d'assignació 
   * Cost: O(n) lineal.
  */
  if (this != &D) {
    _n_paraules = D._n_paraules;
    node *aux;
    aux = copia_nodes(D._arrel);
    esborra_nodes(_arrel);
    _arrel = aux;
  }
  return (*this);
}

void diccionari::esborra_nodes(node *m) {
  /** 
   * Pre:  Cert.
   * Post: Esborra el node i els seus fills.
   * Cost: O(n) lineal.
  */
  if (m!= NULL) {
    esborra_nodes(m->esq);
    esborra_nodes(m->dret);
    esborra_nodes(m->cent);
    delete m;
  }
}

diccionari::~diccionari() throw() {
  /** 
   * Pre:  Cert.
   * Post: Destructor.
   * Cost: O(n) lineal.
  */
  esborra_nodes(_arrel);
}

typename diccionari::node* diccionari::insereix(node *n, nat posicio, string s, bool& repetit) {
  /** 
   * Pre:  Cert.
   * Post: Afegeix la lletra del string s allotjada a la posicio del nat posicio.
   * Cost: O(l*log s) sent l el número de simbols que hem queden per visitar i s el número
        promig de simbols.
  */
  if (n == NULL) {
    if (posicio > s.length()-1) {
      repetit = true;
    } else {
      try {
        n = new node;
        n->esq = n->dret = n->cent = NULL;
        n->valor = s[posicio];
        if (posicio < s.length()-1) {
          n->cent = insereix(n->cent, posicio+1, s, repetit);
        }
      }
      catch (...) {
        delete n;
        throw;
      }
    }
  } else {
    if (n->valor > s[posicio]) {
        n->esq = insereix(n->esq, posicio, s, repetit);
      } else if (n->valor < s[posicio]) {
        n->dret = insereix(n->dret, posicio, s, repetit);
    } else {   // (n->valor == s[posicio])
      n->cent = insereix(n->cent, posicio+1, s, repetit);
    }
  }
  return n;
}

void diccionari::insereix(const string& p) throw(error) {
  /** 
   * Pre:  Cert.
   * Post: Afegeix la paraula p al diccionari; si la paraula p ja formava
        part del diccionari, l'operació no té cap efecte. 
   * Cost: O(l*log s) sent l la longitud mitja i s el numero promig de simbols.
  */
  string s = p + _especial;
  bool repetit = false;
  _arrel = insereix(_arrel, 0, s, repetit);
  if(!repetit) _n_paraules++;
}

string diccionari::prefix(node *n, string s, nat i, nat &j) {
  /** 
   * Pre:  Cert.
   * Post: Retorna el prefix més llarg de p que és una paraula que pertany
        al diccionari, o dit d'una forma més precisa, retorna la
        paraula més llarga del diccionari que és prefix de p.
   * Cost: O(l*log s) sent l el número de simbols que hem queden per visitar i s el número
        promig de simbols.
  */
  string paraula = "";
  if (n != NULL) {
    if (n->valor == _especial) {
      j = i;
    }
    if (n->valor == s[i]) {
      prefix(n->esq, s, i, j);
      paraula+= s[i] + prefix(n->cent, s, i+1, j);
    } else if (n->valor > s[i]) {
      paraula+=prefix(n->esq, s, i, j);
    } else if (n->valor < s[i]) {
      prefix(n->esq, s, i, j);
      paraula+=prefix(n->dret, s, i, j);
    }
  }
  return paraula;
}

string diccionari::prefix(const string& p) const throw(error) {
  /** 
   * Pre:  Cert.
   * Post: Retorna el prefix més llarg de p que és una paraula que pertany
        al diccionari, o dit d'una forma més precisa, retorna la
        paraula més llarga del diccionari que és prefix de p.
   * Cost: O(l*log s) sent l la longitud mitja i s el numero de simbols promig.
  */
  nat j = 0;
  string s = prefix(_arrel, p, 0, j);
  string par = "";
  for(nat i = 0; i< j; i++) {
    par+=s[i];
  }
  return par;
}

void diccionari::satisfan_patro(node *n, const vector<string>& q, list<string>& L, nat i, string par) {
  /** 
   * Pre:  Cert.
   * Post: Retorna la llista de paraules del diccionari que satisfan el
          patró especificat en el vector d'strings q, en ordre alfabètic
          ascendent.
   * Cost: O(l*n) l és l'altura promig i n el número total de nodes.
  */
  if (n != NULL) {
    string par2 = par + n->valor;
    satisfan_patro(n->esq, q , L, i, par);
    if (i == q.size() && n->valor == _especial) {
      L.push_back(par);
    } else if (i < q.size()) {
      string s = q[i];
      nat cont = 0;
      bool acabat = false;
      while (cont < s.size() && !acabat) {
        if (s[cont] == n->valor) {
          acabat = true;
          satisfan_patro(n->cent, q , L, i+1, par2);
        } else {
          cont++;
        }
      }
      satisfan_patro(n->dret, q , L, i, par);
    }
  }
  return;
}

void diccionari::satisfan_patro(const vector<string>& q, list<string>& L) const throw(error) {
  /** 
   * Pre:  Cert.
   * Post: Retorna la llista de paraules del diccionari que satisfan el
          patró especificat en el vector d'strings q, en ordre alfabètic
          ascendent.
   * Cost: O(l*n) l és l'altura promig i n el número total de nodes.
  */
  satisfan_patro(_arrel, q, L, 0, "");
  return;
}

void diccionari::llista_paraules(node *n, nat k, list<string>& L, nat profunditat, string par) {
  /** 
   * Pre:  Cert.
   * Post: Retorna una llista amb totes les paraules del diccionari 
        de longitud major o igual a k en ordre alfabètic ascendent.
   * Cost: O(l*n) l és l'altura promig i n el número total de nodes.
  */
  if ( n!= NULL ) {
    string par2 = par + n->valor;
    if (n->valor == _especial) {
      if (k <= profunditat) {
        L.push_back(par);
      }
    }
    llista_paraules(n->esq, k, L, profunditat, par);
    llista_paraules(n->cent, k, L, profunditat+1, par2);
    llista_paraules(n->dret, k, L, profunditat, par);
  }
  return;
}

void diccionari::llista_paraules(nat k, list<string>& L) const throw(error) {
  /** 
   * Pre:  Cert.
   * Post: Retorna una llista amb totes les paraules del diccionari 
        de longitud major o igual a k en ordre alfabètic ascendent.
   * Cost: O(l*n) l és l'altura promig i n el número total de nodes.
  */
  llista_paraules(_arrel, k, L, 0, "");
  return;
}

nat diccionari::num_pal() const throw() {
  /** 
   * Pre:  Cert.
   * Post: Retorna el nombre de paraules en el diccionari. 
   * Cost: O(1) constant.
  */
  return _n_paraules;
}
