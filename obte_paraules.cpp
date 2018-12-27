#include "obte_paraules.hpp"
#include "word_toolkit.hpp"
#include "iter_subset.hpp"

void obte_paraules::obte_paraules(nat k, const string& s, const anagrames& A, list<string>& paraules) throw(error) {
  /** 
   * Pre:  k no es major que la longitud de l'string s o k >= 3 i string s almenys tres lletres.
   * Post: Retorna la llista de paraules que es poden formar usant k lletres
   *       de la paraula s. Llança error si k és major que la longitud de
   *    	 l'string s o k < 3.
   * Cost: O((n!/k!(n-k)) * O(l)) sent "n" el tamany del string s i sent "k" la longitud del subset
   *  		 i sent "l" el cost de mateix anagrama canonic.
   */
  if (k >= 3 && k <= s.size()) {
    string ord = word_toolkit::anagrama_canonic(s);
    iter_subset c(ord.size(), k);
    while (!c.end()) {
      vector<nat> act = *c;
      string paraula = "";
      for (nat i = 0; i < k; i++) {
        nat pos = act[i];
        paraula = paraula + ord[pos-1];
      }
      A.mateix_anagrama_canonic(paraula, paraules);
      c++;
    }
    paraules.sort();
    paraules.unique();
  } else {
    throw error(LongitudInvalida);
  }
}

void obte_paraules::obte_paraules(const string& s, const anagrames& A, list<string>& paraules) throw(error) {
  /** 
   * Pre:  String s almenys tres lletres.
   * Post: Retorna la llista de paraules que es poden formar usant 3 o més lletres
   *       de la paraula s. La llista estarà ordenada de menys a més longitud; 
   *       a igual longitud les paraules estan en ordre alfabètic creixent. 
   *       Llança un error si l'string s té menys de tres lletres.
   * Cost: O(((n!/k!(n-k))*(n-k)) * O(l)) sent "n" el tamany del string s i sent "k" la longitud del
   *       subset i sent "l" el cost de mateix anagrama canonic. 
  */
  if (s.size() > 2) {
    string ord = word_toolkit::anagrama_canonic(s);
    for (nat i = 3; i-1 < ord.size(); i++) {
      list<string> par;
      iter_subset c(ord.size(), i);
      while (!c.end()) {
        vector<nat> act = *c;
        string paraula = "";
        for (nat j = 0; j < i; j++) {
          nat pos = act[j];
          paraula = paraula + ord[pos-1];
				}
        A.mateix_anagrama_canonic(paraula, par);
        c++;
			}
      par.sort();
      for (list<string>::iterator it = par.begin(); it!= par.end(); it++) {
        paraules.push_back(*it);
			}
			par.erase(par.begin(), par.end());
		}
		paraules.unique();
    } else {
    	throw error(LongitudInvalida);
  }
}
