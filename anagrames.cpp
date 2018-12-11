#include "anagrames.hpp"
#include "word_toolkit.hpp"


anagrames::anagrames() throw(error) {
  /*Pre: Cert.
	Post: Construeix un anagrama buit.
	Cost: */
	M = 101;
	quants = 0;
    taula = new node_hash*[M];
    for(nat i = 0; i < M; i++){
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
	for(nat i = 0; i<M; i++){
		node_hash *aux = taula[i];
		while(aux->seg != NULL){
			node_hash *aux2 = aux->seg;
			delete aux;
			aux = aux2;
		}
		delete aux;
		taula[i] = NULL;
	}
	delete taula;
	M = 0;
	quants = 0;
}

nat anagrames::hash(string k){
	nat index = util::hash(k);
    index = index % M;
	return index;
}

void anagrames::insereix(const string& p) throw(error) {
  /*Pre: Cert
	Post: Afegeix la paraula p a l'anagrama; si la paraula p ja formava
    part de l'anagrama, l'operació no té cap efecte.
	Cost: */
	diccionari::insereix(p);
	string canonic = word_toolkit::anagrama_canonic(p);
	nat i = hash(canonic);
	node_hash *aux = taula[i];
	bool trobat = false;
	while(aux != NULL && !trobat){
		if(aux->k == canonic) trobat = true;
		else aux = aux->seg;
	}
	if(trobat) {
		aux->v.push_back(p);
		++quants;
	}
	else{
		list<string> va;
		va.push_back(p);
		taula[i] = new node_hash(canonic, va, taula[i]);
	}

}

void anagrames::mateix_anagrama_canonic(const string& a, list<string>& L) const throw(error) {
  /*Pre: Les llestre de a tenen que estar en ordre ascendent llença un error si no ho estan.
	Post: Retorna la llista de paraules p tals que anagrama_canonic(p)=a.
	Cost: */
	if(word_toolkit::es_canonic(a)){
		nat i = hash(a);
		node_hash *p = taula[i];
		bool trobat = false;
		while(p!= NULL && !trobat){
			if(p->k == a) {
				L = p->v;
				trobat = true;
			}
			else p = p->seg;
		}
	}
	else throw(NoEsCanonic);
    
}