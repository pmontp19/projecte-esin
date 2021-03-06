#include "word_toolkit.hpp"
#include <algorithm>

bool word_toolkit::es_canonic(const string& s) throw() {
  /** 
   * Pre:  Cert.
   * Post: Retorna cert si i només si les lletres de l'string s estan en 
   *       ordre lexicogràfic ascendent. 
   * Cost: lineal O(n).
   */
  bool t = true;
  uint i = 1;
  while (s.size() > i && t) {
    if (s[i] < s[i-1])
			t = false;
    else
      i++;
  }
  return t;
}

string word_toolkit::anagrama_canonic(const string& s) throw() {
  /** 
   * Pre:  Cert.
   * Post: Retorna l'anagrama canònic de l'string s.
   * Cost: quasi lineal O(n*log n).
  */
  string anagrama = s;
  if (!es_canonic(anagrama)) {
    sort(anagrama.begin(), anagrama.end());
  }
  return anagrama;
}

char word_toolkit::mes_frequent(const string& excl, const list<string>& L) throw() {
  /** 
   * Pre:  L es una llista no buida.
   * Post: Retorna el caràcter que no apareix a l'string excl i és el més
   *       freqüent en la llista de paraules L, sent L una llista no buida
   *       de paraules formades exclusivament amb lletres majúscules de
   *       la 'A' a la 'Z' (excloses la 'Ñ', 'Ç', majúscules accentuades, ...).
   *       En cas d'empat, es retornaria el caràcter alfabèticament menor.
   *       Si l'string excl inclou totes les lletres de la 'A' a la 'Z' es 
   *       retorna el caràcter '\0', és a dir, el caràcter de codi ASCII 0.
   * Cost: lineal respecte al numero de caracters de string de la llista O(n).
   */
  char resposta;
  int contadors[26] = {0};
  if (L.size() > 0) {
    for (list<string>::const_iterator it = L.begin(); it != L.end(); ++it) {
      string paraula = *it;
      for (uint j = 0; j < paraula.size(); j++) {
        int p = static_cast<int>(paraula[j]);
        p = p-'A';
        contadors[p]++;
      }
    }
  }
  for (uint i = 0; i < excl.size(); i++) {
    int p = static_cast<int>(excl[i]);
    p = p-'A';
    contadors[p] = -1;
  }
  int posicio = -1;
  int max = 0;
  for (uint j = 0; j < sizeof(contadors)/sizeof(contadors[0]); j++) {
    if (max < contadors[j]) {
      max = contadors[j];
      posicio = j;
    }
  }
  if (posicio == -1)
		resposta = '\0';
  else
    resposta = 'A' + posicio;

  return resposta;
}
