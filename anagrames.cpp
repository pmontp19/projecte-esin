#include "anagrames.hpp"
#include "word_toolkit.hpp"

#define CAPACITAT 100
#define FACTOR_CARREGA .9

/*
	INSEREIX es cost lineal per que el recorrer la llista es lineal o 
	el pitjor cost d'insereix es el de rehash? amb el factor de carrega

	Cost rehash es n o 2n ja que amplia per 2 la taula (n)?

	Falta cost de - Insereix
*/

nat anagrames::hash(const string &k) const throw() {
	/** 
	 * Pre:  Cert.
	 * Post: Retorna la posició d'accés a la taula hash.
	 * Cost: O(n) lineal respeta el tamany del string donat.
	*/
	return util::hash(k) % _M;
}

anagrames::node_hash::node_hash(const string &k, const list<string> &v, node_hash *seg) throw(error) : k(k), v(v), seg(seg) {}
/** 
	 * Pre:  Cert.
	 * Post: Construeix un node hash per parametres.
	 * Cost: 0(1) constant.
	*/

void anagrames::rehash() {
	/** 
	 * Pre:  Cert.
	 * Post: Amplia la mida de la taula hash i dispersa els valors.
	 * Cost: 0(n) sent n el tamany de la taula.
	*/
	nat midaAbans = _M;
	_M = _M * 2 + 1;
	node_hash **novaTaula = new node_hash *[_M]();
	for (nat i = 0; i < midaAbans; ++i) {
		node_hash *n = _taula[i];
		while (n != NULL) {
			node_hash *aux = n;
			n = n->seg;
			node_hash *&nou_punter = novaTaula[hash(aux->k)];
			aux->seg = nou_punter;
			nou_punter = aux;
		}
	}
	delete[] _taula;
	_taula = novaTaula;
}

void anagrames::prova_factor_carrega() {
	/** 
	 * Pre:  Cert.
	 * Post: Comprova que el factor de carrega sigui el desitjat en cas contrari fa dispersio.
	 * Cost: O(1) constant.
	*/
	float a = static_cast<float>(_quants) / static_cast<float>(_M);
	if (a >= FACTOR_CARREGA) {
		rehash();
	}
}

anagrames::anagrames() throw(error) : _quants(0) {
	/** 
	 * Pre:  Cert.
	 * Post: Construeix un anagrama buit.
	 * Cost: 0(n) sent n el tamany de la taula.
	*/
	_M = CAPACITAT;
	_quants = 0;
	_taula = new node_hash *[_M];
	for (nat i = 0; i < _M; ++i) {
		_taula[i] = NULL;
	}
}

anagrames::anagrames(const anagrames &A) throw(error) : diccionari(A) {
	/** 
	 * Pre:  Cert.
	 * Post: Constructor per còpia.
	 * Cost: O(n) sent n el tamany de la taula.
	*/
	_M = A._M;
	_quants = A._quants;
	_taula = new node_hash *[_M];
	for (nat i = 0; i < _M; ++i) {
		node_hash *p = A._taula[i];
		if (p == NULL) {
			_taula[i] = NULL;
		} else {
			node_hash *q = new node_hash(p->k, p->v, _taula[i]);
			_taula[i] = q;
			p = p->seg;
			while (p != NULL) {
				node_hash *aux = new node_hash(p->k, p->v, _taula[i]);
				q->seg = aux;
				p = p->seg;
				q = aux;
			}
			q->seg = NULL;
		}
	}
}

anagrames &anagrames::operator=(const anagrames &A) throw(error) {
	/** 
	 * Pre:  Cert.
	 * Post: Operador d'assignació.
	 * Cost: O(n) sent n el tamay de la taula.
	*/
	if (&A != this) {
		diccionari::operator=(A);
		_M = A._M;
		_quants = A._quants;
		_taula = new node_hash *[_M];
		for (nat i = 0; i < _M; ++i) {
			node_hash *p = A._taula[i];
			if (p == NULL) {
				_taula[i] = NULL;
			} else {
				node_hash *q = new node_hash(p->k, p->v, _taula[i]);
				_taula[i] = q;
				p = p->seg;
				while (p != NULL) {
					node_hash *aux = new node_hash(p->k, p->v, _taula[i]);
					q->seg = aux;
					p = p->seg;
					q = aux;
				}
				q->seg = NULL;
			}
		}
	}
	return *this;
}

anagrames::~anagrames() throw() {
	/** 
	 * Pre:  Cert.
	 * Post: Destructor.
	 * Cost: O(n) sent n el tamany de la taula.
	*/
	if (_quants > 0) {
		node_hash *aux;
		node_hash *auxSeg;
		for (nat i = 0; i < _M; ++i) {
			aux = _taula[i];
			while (aux != NULL) {
				auxSeg = aux->seg;
				delete aux;
				aux = auxSeg;
			}
			_taula[i] = NULL;
		}
	}
	_quants = 0;
	delete[] _taula;
}

void anagrames::insereix(const string &p) throw(error) {
	/** 
	 * Pre:  Cert
	 * Post: Afegeix la paraula p a l'anagrama; si la paraula p ja formava
   			 part de l'anagrama, l'operació no té cap efecte.
	 * Cost:
	*/
	diccionari::insereix(p);
	string canonic = word_toolkit::anagrama_canonic(p);
	nat i = anagrames::hash(canonic);
	node_hash *punter = _taula[i];
	bool trobat = false;
	while (punter != NULL && !trobat) {
		if (punter->k == canonic)
			trobat = true;
		else
			punter = punter->seg;
	}
	if (trobat) {
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
		_taula[i] = new node_hash(canonic, llista_paraules, _taula[i]);
		_quants++;
		prova_factor_carrega();
	}
}

void anagrames::mateix_anagrama_canonic(const string &a, list<string> &L) const throw(error) {
	/** 
	 * Pre:  Les lletres de a tenen que estar en ordre ascendent llença un error si no ho estan.
	 * Post: Retorna la llista de paraules p ordenada tals que anagrama_canonic(p)=a.
	 * Cost: O(n) sent n el cost promig de les paraules de les llistes que tenen el
	 * mateix anagrama canonic .
	 */
	if (word_toolkit::es_canonic(a)) {
		nat i = anagrames::hash(a);
		node_hash *p = _taula[i];
		bool trobat = false;
		while (p != NULL && !trobat) {
			if (p->k == a) {
				for (list<string>::iterator it = p->v.begin(); it != p->v.end(); it++) {
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
