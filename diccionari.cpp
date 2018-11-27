#include "diccionari.hpp"


char especial(){
	return '#';
}

diccionari::diccionari() throw(error) {
	/*Pre: Cert
	Post: Construeix un diccionari que conté únicament una paraula:
    la paraula buida.
	Cost: */
	arrel = new node;
	arrel->esq = NULL;
	arrel->cent = NULL;
	arrel->dret = NULL;
	arrel->valor = especial;
}

typename diccionari::node* diccionari::copia_nodes(node *m){
	node *n;
	if(m == NULL) n = NULL;
	else{
		n = new node;
		n->valor = m->valor;
		n->esq = copia_nodes(m->esq);
		n->dret = copia_nodes(m->dret);
		n->cent = copia_nodes(m->cent);
	}
	return n;
}

diccionari::diccionari(const diccionari& D) throw(error) {
	/*Pre:
	Post: Constructor per còpia
	Cost: */
	arrel = copia_nodes(D.arrel);

}

diccionari& diccionari::operator=(const diccionari& D) throw(error) {
	/*Pre:
	Post: operador d'assignació 
	Cost: */
	if (this != &D) {
    node* aux;
    aux = copia_nodes(D.arrel);
    esborra_nodes(arrel);
    arrel = aux;
  }
  return (*this);

}

void diccionari::esborra_nodes(node *m){
	if(m!= NULL){
		esborra_nodes(m->esq);
		esborra_nodes(m->dret);
		esborra_nodes(m->cent);
		delete m;
	}
}

diccionari::~diccionari() throw() {
	/*Pre:
	Post: destructor
	Cost: */
	esborra_nodes(arrel);

}

void diccionari::insereix(const string& p) throw(error) {
	/*Pre:
	Post: Afegeix la paraula p al diccionari; si la paraula p ja formava
    part del diccionari, l'operació no té cap efecte. 
	Cost: */

}

string diccionari::prefix(const string& p) const throw(error) {
	/*Pre:
	Post: Retorna el prefix més llarg de p que és una paraula que pertany
    al diccionari, o dit d'una forma més precisa, retorna la
    paraula més llarga del diccionari que és prefix de p.
	Cost: */

}

void diccionari::satisfan_patro(const vector<string>& q, list<string>& L) const throw(error) {
	/*Pre:
	Post: Retorna la llista de paraules del diccionari que satisfan el
    patró especificat en el vector d'strings q, en ordre alfabètic
    ascendent. 
	Cost: */

}

void diccionari::llista_paraules(nat k, list<string>& L) const throw(error) {
	/*Pre:
	Post: Retorna una llista amb totes les paraules del diccionari 
    de longitud major o igual a k en ordre alfabètic ascendent.
	Cost: */

}

nat diccionari::num_pal() const throw() {
	/*Pre:
	Post: Retorna el nombre de paraules en el diccionari. 
	Cost: */
    
}