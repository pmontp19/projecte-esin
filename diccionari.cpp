#include "diccionari.hpp"


diccionari::diccionari() throw(error) {
	/** 
	 * Pre:  Cert
	 * Post: Construeix un diccionari que conté únicament una paraula: la paraula buida.
	 * Cost: O(1) constant
	*/
	arrel = new node;
	arrel->esq = NULL;
	arrel->cent = NULL;
	arrel->dret = NULL;
	arrel->valor = especial;
	n_paraules = 1;
}

typename diccionari::node* diccionari::copia_nodes(node *m) {
	/** 
	 * Pre: 
	 * Post: 
	 * Cost:
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
	 * Pre: 
	 * Post: Constructor per còpia
	 * Cost:
	*/
	n_paraules = D.n_paraules;
	arrel = copia_nodes(D.arrel);
}

diccionari &diccionari::operator=(const diccionari &D) throw(error) {
	/** 
	 * Pre: 
	 * Post: Operador d'assignació 
	 * Cost:
	*/
	if (this != &D) {
		n_paraules = D.n_paraules;
		node *aux;
		aux = copia_nodes(D.arrel);
		esborra_nodes(arrel);
		arrel = aux;
	}
	return (*this);
}

void diccionari::esborra_nodes(node *m) {
	/** 
	 * Pre: 
	 * Post: 
	 * Cost:
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
	 * Pre: 
	 * Post: destructor
	 * Cost:
	*/
	esborra_nodes(arrel);
}

typename diccionari::node* diccionari::insereix(node *n, nat posicio, string s, bool& repetit) {
	/** 
	 * Pre: 
	 * Post: 
	 * Cost:
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
	 * Pre: 
	 * Post: Afegeix la paraula p al diccionari; si la paraula p ja formava
 			 part del diccionari, l'operació no té cap efecte. 
	 * Cost:
	*/
	string s = p + especial;
	bool repetit = false;
	arrel = insereix(arrel, 0, s, repetit);
	if(!repetit) n_paraules++;
}

string diccionari::prefix(node *n, string s, nat i, nat &j) {
	/** 
	 * Pre: 
	 * Post: 
	 * Cost:
	*/
	string paraula = "";
	if (n != NULL) {
		if (n->valor == especial) {
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
	 * Pre: 
	 * Post: Retorna el prefix més llarg de p que és una paraula que pertany
 			 al diccionari, o dit d'una forma més precisa, retorna la
 			 paraula més llarga del diccionari que és prefix de p.
	 * Cost:
	*/
	nat j = 0;
	string s = prefix(arrel, p, 0, j);
	string par = "";
	for(nat i = 0; i< j; i++) {
		par+=s[i];
	}
	return par;
}

void diccionari::satisfan_patro(node *n, const vector<string>& q, list<string>& L, nat i, string par) {
	/** 
	 * Pre: 
	 * Post: 
	 * Cost:
	*/
	if (n != NULL) {
		string par2 = par + n->valor;
		satisfan_patro(n->esq, q , L, i, par);
		if (i == q.size() && n->valor == especial) {
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
	 * Pre: 
	 * Post: Retorna la llista de paraules del diccionari que satisfan el
   			 patró especificat en el vector d'strings q, en ordre alfabètic
   			 ascendent.
	 * Cost:
	*/
	satisfan_patro(arrel, q, L, 0, "");
	return;
}

void diccionari::llista_paraules(node *n, nat k, list<string>& L, nat profunditat, string par) {
	/** 
	 * Pre: 
	 * Post: 
	 * Cost:
	*/
	if ( n!= NULL ) {
		string par2 = par + n->valor;
		if (n->valor == especial) {
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
	 * Pre: 
	 * Post: Retorna una llista amb totes les paraules del diccionari 
     		 de longitud major o igual a k en ordre alfabètic ascendent.
	 * Cost:
	*/
	llista_paraules(arrel, k, L, 0, "");
	return;
}

nat diccionari::num_pal() const throw() {
	/** 
	 * Pre: 
	 * Post: Retorna el nombre de paraules en el diccionari. 
	 * Cost:
	*/
	return n_paraules;
}
