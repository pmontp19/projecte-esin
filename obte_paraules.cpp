#include "obte_paraules.hpp"
#include "word_toolkit.hpp"
#include "iter_subset.hpp"
  
void obte_paraules::obte_paraules(nat k, const string& s, const anagrames& A, list<string>& paraules) throw(error) {
	/*Pre: k no es major que la longitud de l'string s o k >= 3.
	Post: Retorna la llista de paraules que es poden formar usant k lletres
    de la paraula s. Llança error si k és major que la longitud de
    l'string s o k < 3.
	Cost: */
	if( k >= 3 and k <= s.size()){
		string ord = word_toolkit::anagrama_canonic(s);
		iter_subset c(s.size(), k);
		while( !c.end()){
			vector<nat> act = *c;
			string paraula = "";
			for(nat i = 0; i<k; i++){
				paraula = paraula + s[act[i]];
			}
			A.mateix_anagrama_canonic(paraula,paraules);
			c++;
		}
	}
	else throw error(LongitudInvalida);
}

void obte_paraules::obte_paraules(const string& s, const anagrames& A, list<string>& paraules) throw(error) {
	/*Pre: String s almenys tres lletres.
	Post: Retorna la llista de paraules que es poden formar usant 3 o més lletres
    de la paraula s. La llista estarà ordenada de menys a més longitud; 
    a igual longitud les paraules estan en ordre alfabètic creixent. 
    Llança un error si l'string s té menys de tres lletres.
	Cost: */
	if(s.size() >= 3){
		string ord = word_toolkit::anagrama_canonic(s);
		for(nat i = 3; i == ord.size(); i++){
			iter_subset c(s.size(), i);
			while( !c.end()){
			vector<nat> act = *c;
			string paraula = "";
			for(nat j = 0; j<i; j++){
				paraula = paraula + s[act[j]];
			}
			A.mateix_anagrama_canonic(paraula,paraules);
			c++;
			}
		}
	}
	else throw error(LongitudInvalida);
}