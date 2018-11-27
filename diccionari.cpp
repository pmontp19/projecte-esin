#include "diccionari.hpp"


/*

DUDAS

-LA FUNCION CHAR ESPECIAL COMO SE HACE? DE MOMENTO TENGO UNA VARIABLE GLOBAL EN REP

- EL CONSTRUCTOR ENTONCES EL PRIMER VALOR QUE ESTA METIENDO EN EL NODO ARREL ES EL
CARACTER DE NULO ENTONCES AL HACER LA INSERCION SEGURO QUE LO ESTA HACIENDO BIEN?

-PREFIX DICE QUE TIENE QUE DEVOLVER EL CARACTER STRING BUIT QUE ES UNA PALABRA DEL
DICCIONARIO, YO LO HAGO CON UN STRING BUIT QUE LE VAMOS SUMANDO CARACTERES Y SI
NINGUNO COINCIDE LO DEVUELVE ENTONCES VACIO CUANDO NINGUNO COINCIDE YA ES QUE
NO HAY NADA MAS PARECIDO Y ESO ES LO QUE DEVUELVE.

El PREFIX COMO ESTA ECHO SI ENCUENTRA UNA PALABRA POR EJEMPLO PODARE Y LA RAIZ ES
PODARGOLFZ DEVUELVE PODAR NO SE SI ESTA BIEN ECHO O NO PREGUNTAR Y EN CASO QUE NO
COMO MIRARLO

*/

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

typename diccionari::node* diccionari::insereix(node *n, nat posicio, string s){
	if(n == NULL){
		n = new node;
		n->esq = n->dret = n->cent = NULL;
		n->valor = s[posicio];
		if(posicio < s.size()){
			n->cent = insereix(n->cent, posicio+1, s);
		}
	}
	else{
		if(n->valor > s[posicio]){
			n->esq = insereix(n->esq, posicio, s);
		}
		else if(n->valor < s[posicio]){
			n->dret = insereix(n->dret, posicio, s);
		}
		else{
			n->cent = insereix(n->cent, posicio+1, s);
		}
	}
	return n;
}

void diccionari::insereix(const string& p) throw(error) {
	/*Pre:
	Post: Afegeix la paraula p al diccionari; si la paraula p ja formava
    part del diccionari, l'operació no té cap efecte. 
	Cost: */
	string s = p + especial;
	arrel = insereix(arrel, 0, s);

}

string diccionari::prefix(node *n, string s, nat i){
	string paraula = "";
	if(n != NULL){
		if(n->valor == s[i]){
			paraula+= s[i] + prefix(n->cent, s, i+1);
		}
		else if(n->valor > s[i]){
			paraula+=prefix(n->esq, s, i);
		}
		else if(n->valor < s[i]){
			paraula+=prefix(n->dret, s, i);
		}
	}
	return paraula;

}

string diccionari::prefix(const string& p) const throw(error) {
	/*Pre:
	Post: Retorna el prefix més llarg de p que és una paraula que pertany
    al diccionari, o dit d'una forma més precisa, retorna la
    paraula més llarga del diccionari que és prefix de p.
	Cost: */
	string s = prefix(arrel, p, 0);
	return s;

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