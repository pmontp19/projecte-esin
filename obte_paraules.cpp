#include "obte_paraules.hpp"
#include "word_toolkit.hpp"
#include "iter_subset.hpp"

/*
	comentari:
	throw error em genera 16 punters nous que no elimina, obte paraules funciona 100% però
	s'hauria de mirar el sort i el unique ya que te aixó cost n cuadratic
*/
  
void obte_paraules::obte_paraules(nat k, const string& s, const anagrames& A, list<string>& paraules) throw(error) {
	/*Pre: k no es major que la longitud de l'string s o k >= 3.
	Post: Retorna la llista de paraules que es poden formar usant k lletres
    de la paraula s. Llança error si k és major que la longitud de
    l'string s o k < 3.
	Cost: */
	if( k >= 3 and k <= s.size()){
		string ord = word_toolkit::anagrama_canonic(s);
		iter_subset c(ord.size(), k);
		while( !c.end()){
			vector<nat> act = *c;
			string paraula = "";
			for(nat i = 0; i<k; i++){
				nat pos = act[i];
				//cout<<pos<<endl;
				paraula = paraula + ord[pos-1];
			}
			//cout<<"paraula "<<paraula<<endl;
			A.mateix_anagrama_canonic(paraula,paraules);
			c++;
		}
		paraules.sort();
		paraules.unique();
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
	if(s.size() > 2){
		string ord = word_toolkit::anagrama_canonic(s);
		for(nat i = 3; i-1 < ord.size(); i++){
			list<string> par;
			iter_subset c(ord.size(), i);
			while( !c.end()){
				vector<nat> act = *c;
				string paraula = "";
				for(nat j = 0; j<i; j++){
					nat pos = act[j];
					paraula = paraula + ord[pos-1];
					}
					//cout<<"paraula "<<paraula<<endl;
				A.mateix_anagrama_canonic(paraula,par);
				c++;
				}
			par.sort();
			for (list<string>::iterator it = par.begin(); it!= par.end(); it++){
				paraules.push_back(*it);
				}
				par.erase(par.begin(),par.end());
			}
			paraules.unique();
		}
	else throw error(LongitudInvalida);
}