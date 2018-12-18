#include "anagrames.hpp"
#include "word_toolkit.hpp"

#define CAPACITAT 100
#define FACTOR_CARREGA .9

nat anagrames::hash(const string &k) const throw() {
	return util::hash(k) % M;
}

anagrames::node_hash::node_hash(const string &k, const list<string> &v, node_hash* seg) throw(error) : k(k), v(v), seg(seg) { }

void anagrames::rehash() {
    nat midaAbans = M;
    M = M * 2 + 1;
    node_hash** novaTaula = new node_hash*[M]();
    for (nat i = 0; i < midaAbans; ++i) {
        node_hash *n = taula[i];
        while (n != NULL) {
            node_hash *aux = n;
            n = n->seg;
            node_hash*& nou_punter = novaTaula[hash(aux->k)];
            aux->seg = nou_punter;
            nou_punter = aux;
        }
    }
    delete [] taula;
    taula = novaTaula;
}

void anagrames::prova_factor_carrega() {
    float a = static_cast<float>(quants) / static_cast<float>(M);
    if (a >= FACTOR_CARREGA) {
        rehash();
    }
}

anagrames::anagrames() throw(error) : quants(0) {
  /*Pre: Cert.
	Post: Construeix un anagrama buit.
	Cost: */
	M = CAPACITAT;
    taula = new node_hash*[M];
    for (nat i = 0; i < M; ++i) {
        taula[i] = NULL;
	}
}

anagrames::anagrames(const anagrames& A) throw(error) {
  /*Pre: Cert.
	Post: Constructor per còpia.
	Cost: */
	M = A.M;
	quants = A.quants;
	taula = new node_hash*[M];
	for (nat i = 0; i < M; ++i) {
		node_hash *p = A.taula[i];
		if (p == NULL) {
			taula[i] = NULL;
		} else {
			node_hash *q = new node_hash(p->k, p->v, taula[i]);
			taula[i] = q;
			p = p->seg;
			while (p != NULL) {
				node_hash *aux = new node_hash(p->k, p->v, taula[i]);
				q->seg = aux;
				p = p->seg;
			}
			q->seg = NULL;
		}
	}
}

anagrames& anagrames::operator=(const anagrames &A) throw(error) {
    /*Pre: Cert.
	Post: Operador d'assignació.
	Cost: */

    if (&A != this) {
       // copiar(A);
    }
    return *this;
}

anagrames::~anagrames() throw() {
  /*Pre: Cert.
	Post: Destructor.
	Cost: */
	if (quants > 0) {
	    node_hash* aux;
	    node_hash* auxSeg;
	    for (nat i = 0; i < M; ++i) {
	        aux = taula[i];
	        while (aux != NULL) {
	            auxSeg = aux->seg;
	            delete aux;
	            aux = auxSeg;
	        }
	        taula[i] = NULL;
	    }
	}
    delete [] taula;
}

void anagrames::insereix(const string& p) throw(error) {
  /*Pre: Cert
	Post: Afegeix la paraula p a l'anagrama; si la paraula p ja formava
    part de l'anagrama, l'operació no té cap efecte.
	Cost: */
	diccionari::insereix(p);
	string canonic = word_toolkit::anagrama_canonic(p);
	nat i = anagrames::hash(canonic);
	node_hash *punter = taula[i];
	bool trobat = false;
	while (punter != NULL && !trobat) {
		if (punter->k == canonic) trobat = true;
		else
			punter = punter->seg;
	}
	if(trobat) {
		list<string>::iterator it = punter->v.begin();
		bool acabat = false;
		while (it != punter->v.end() && !acabat) {
			if (*it == p) {
				acabat = true;
			} else if (*it > p) {
				acabat = true;
				punter->v.insert(it, p);
			} else {
				it++;
			}
		}
		if (!acabat) {
			punter->v.push_back(p);
		}
	} else {
		list<string> llista_paraules;
		llista_paraules.push_front(p);
		taula[i] = new node_hash(canonic, llista_paraules, taula[i]);
        quants++;
        prova_factor_carrega();
	}
}

void anagrames::mateix_anagrama_canonic(const string& a, list<string>& L) const throw(error) {
  /*Pre: Les lletres de a tenen que estar en ordre ascendent llença un error si no ho estan.
	Post: Retorna la llista de paraules p tals que anagrama_canonic(p)=a.
	Cost: O (n) sent n el cost promig de les paraules de les llistes que tenen el
	mateix anagrama canonic */
	if (word_toolkit::es_canonic(a)) {
		nat i = anagrames::hash(a);
		node_hash *p = taula[i];
		bool trobat = false;
		while (p!= NULL && !trobat) {
			if (p->k == a) {
				for (list<string>::iterator it = p->v.begin(); it!= p->v.end(); it++) {
					L.push_back(*it);
				}
				trobat = true;
			} else {
				p = p->seg;
			}
		}
	} else {
		throw error(NoEsCanonic);
	}
}
