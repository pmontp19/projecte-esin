#include "diccionari.hpp"


/*

DUDAS

-char especial en private esta bien segun el pero me da un warning	SOLUCIONADO

- Dice que constructor esta correcto

-El prefix hay que probarlo el decia de hacerlo de otra manera de recorrer todo
y al final ir tirando hacia atras comprobando cual es el primero que tiene el caracter
especial pero yo no veo como hacerlo y lo he hecho de esta forma pero habria que hacrlo mejor

Satisfa patro correcto solo falla cuando hace un load diccionario en la linia 47503 que
no se ni qu es ese load.

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
/*
string diccionari::prefix(node *n, string s, nat i){
	string paraula = "";
	if(n == NULL){
		if(i == s.size() && n->valor == especial){
		}
	}
}*/


string diccionari::prefix(node *n, string s, nat i, nat &j){
	string paraula = "";
	if(n != NULL){
		if(n->valor == especial){
			j = i;
		}
		if(n->esq != NULL ){
			if(n->valor == especial){
				j = i;
			}
		}
		if(n->dret != NULL ){
			if(n->valor == especial){
				j = i;
			}
		}
		if(n->valor == s[i]){
			paraula+= s[i] + prefix(n->cent, s, i+1, j);
		}
		else if(n->valor > s[i]){
			paraula+=prefix(n->esq, s, i, j);
		}
		else if(n->valor < s[i]){
			paraula+=prefix(n->dret, s, i, j);
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
	nat j = 0;
	string s = prefix(arrel, p, 0, j);
	string par = "";
	for(int i = 0; i< j; i++){
		par+=s[i];
	}
	return par;

}

void diccionari::satisfan_patro(node *n, const vector<string>& q, list<string>& L, nat i, string par) {
	if(n != NULL){
		string par2 = par + n->valor;
		satisfan_patro(n->esq, q , L, i, par);
		if(i == q.size() and n->valor == especial){
			L.push_back(par);
		}
		else if (i < q.size()){
			string s = q[i];
			nat cont = 0;
			bool acabat = false;
			while (cont < s.size() && !acabat){
				if(s[cont] == n->valor){
					acabat = true;
					satisfan_patro(n->cent, q , L, i+1, par2);
				}
				else cont++;
			}
			satisfan_patro(n->dret, q , L, i, par);
		}
	}
}

void diccionari::satisfan_patro(const vector<string>& q, list<string>& L) const throw(error) {
	/*Pre:
	Post: Retorna la llista de paraules del diccionari que satisfan el
    patró especificat en el vector d'strings q, en ordre alfabètic
    ascendent. 
	Cost: */
	satisfan_patro(arrel, q, L, 0, "");

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