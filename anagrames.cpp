#include "anagrames.hpp"
#include "word_toolkit.hpp"

nat anagrames::hash(const string &k) const throw() {
	return util::hash(k) % M;
}

anagrames::node_hash::node_hash(const string &k, const list<string> &v, node_hash* seg) throw(error) : k(k), v(v), seg(seg) { }

anagrames::anagrames() throw(error) : quants(0) {
  /*Pre: Cert.
	Post: Construeix un anagrama buit.
	Cost: */
	M = 601;
    taula = new node_hash*[M];
    for(nat i = 0; i < M; ++i){
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
	for(nat i = 0; i < M; i++){
		node_hash *m = A.taula[i];
		taula[i] = new node_hash(m->k, m->v, taula[i]);
	}
}

anagrames& anagrames::operator=(const anagrames& A) throw(error) {
  /*Pre: Cert.
	Post: Operador d'assignació.
	Cost: */
	/*M = A.M;
	quants = A.quants;
	taula = new node_hash*[M];
	for(nat i = 0; i < M; i++){
		node_hash *m = A.taula[i];
		node_hash *p = taula[i];
		taula[i] = new node_hash;
		p->k = m->k;
		p->seg = NULL;
		while(m->seg != NULL){
			node_hash *s = new node_hash;
			s->k = m->seg->k;
			p->seg = s;
			s->seg = NULL;
			m = m->seg;
		}
	}*/
	M = A.M;
	quants = A.quants;
	taula = new node_hash*[M];
	for(nat i = 0; i < M; i++){
		node_hash *m = A.taula[i];
		taula[i] = new node_hash(m->k, m->v, taula[i]);
	}
	return (*this);
}

anagrames::~anagrames() throw() {
  /*Pre: Cert.
	Post: Destructor.
	Cost: */
	if(quants > 0){
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
	quants = 0;
	M = 0;
}

void anagrames::insereix(const string& p) throw(error) {
  /*Pre: Cert
	Post: Afegeix la paraula p a l'anagrama; si la paraula p ja formava
    part de l'anagrama, l'operació no té cap efecte.
	Cost: */
	diccionari::insereix(p);
	string p_canonic = word_toolkit::anagrama_canonic(p);
	nat i = anagrames::hash(p_canonic);
	node_hash *punter = taula[i];
	bool trobat = false;
	while(punter != NULL && !trobat){
		if(punter->k == p_canonic) trobat = true;
		else punter = punter->seg;
	}
	if(trobat) {
		punter->v.push_front(p);
	}
	else{
		list<string> llista_paraules;
		llista_paraules.push_front(p);
		taula[i] = new node_hash(p_canonic, llista_paraules, taula[i]);
        ++quants;
	}

}

void anagrames::mateix_anagrama_canonic(const string& a, list<string>& L) const throw(error) {
  /*Pre: Les llestre de a tenen que estar en ordre ascendent llença un error si no ho estan.
	Post: Retorna la llista de paraules p tals que anagrama_canonic(p)=a i la retorna ordenada
	alfabeticament en ordre ascendent.
	Cost: */
	if(word_toolkit::es_canonic(a)){
		nat i = anagrames::hash(a);
		node_hash *p = taula[i];
		bool hi_es = false;
		while(p!= NULL && !hi_es){
			if(p->k == a) {
				L = p->v;
				hi_es = true;
			}
			else p = p->seg;
		}
	}
	else throw error(NoEsCanonic);
    
}