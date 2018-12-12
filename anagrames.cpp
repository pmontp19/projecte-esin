#include "anagrames.hpp"
#include "word_toolkit.hpp"

#define CAPACITAT 100

nat anagrames::hash(const string &k) const throw() {
	return util::hash(k) % M;
}

anagrames::node_hash::node_hash(const string &k, const list<string> &v, node_hash* seg) throw(error) : k(k), v(v), seg(seg) { }

void anagrames::rehash() {
    nat midaAbans = M;
    M = M * 2 + 1;
    node_hash** novaTaula = new node_hash*[M]();
    /*for (nat i = 0; i < M; i++) {
        novaTaula[i] = NULL;
    }*/ 

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
    //cout << "fent rehash " << M << endl;
}

void anagrames::prova_factor_carrega() {
    float a = (float)quants / (float)M;
    if (a >= 0.9) {
        rehash();
    }
}

anagrames::anagrames() throw(error) : quants(0) {
  /*Pre: Cert.
	Post: Construeix un anagrama buit.
	Cost: */
	M = CAPACITAT;
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
	for (nat i = 0; i < M; i++){
		node_hash *orig = A.taula[i];
        if (orig == NULL) {
            taula[i] = NULL;
        }
        else {
            node_hash* dest;
            dest->k = orig->k;
            dest->v = orig->v;

            taula[i] = dest;
            orig = orig->seg;
            while (orig != NULL) {
                node_hash* dest2;
                dest->seg = dest2;
                dest2->k = orig->k;
                dest2->v = orig->v;

                orig = orig->seg;
            }
            dest->seg = NULL;
        }
	}
}

anagrames& anagrames::operator=(const anagrames &A) throw(error)
{
    /*Pre: Cert.
	Post: Operador d'assignació.
	Cost: */
    //copiat del constructor per copia, s'ha de provar
    if (&A != this)
    {
        M = A.M;
        quants = A.quants;
        taula = new node_hash *[M];
        for (nat i = 0; i < M; i++)
        {
            node_hash *orig = A.taula[i];
            if (orig == NULL)
            {
                taula[i] = NULL;
            }
            else
            {
                node_hash *dest;
                dest->k = orig->k;
                dest->v = orig->v;

                taula[i] = dest;
                orig = orig->seg;
                while (orig != NULL)
                {
                    node_hash *dest2;
                    dest->seg = dest2;
                    dest2->k = orig->k;
                    dest2->v = orig->v;

                    orig = orig->seg;
                }
                dest->seg = NULL;
            }
        }
    }
    return (*this);
}

anagrames::~anagrames() throw() {
  /*Pre: Cert.
	Post: Destructor.
	Cost: */
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
    delete [] taula;
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
        punter->v.sort();
	}
	else{
		list<string> llista_paraules;
		llista_paraules.push_front(p);
		taula[i] = new node_hash(p_canonic, llista_paraules, taula[i]);
        ++quants;
        prova_factor_carrega();
	}

}

void anagrames::mateix_anagrama_canonic(const string& a, list<string>& L) const throw(error) {
  /*Pre: Les llestre de a tenen que estar en ordre ascendent llença un error si no ho estan.
	Post: Retorna la llista de paraules p tals que anagrama_canonic(p)=a.
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