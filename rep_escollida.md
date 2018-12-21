# Representacio escollida

## diccionari.rep

```cpp
struct node {
  char valor;
  node *esq;
  node *dret;
  node *cent;
};
node *_arrel;
nat _n_paraules;
...
```

L'estructura escollida per la representació de la classe `diccionari` és un arbre ternari de cerca (TST). Aquesta estructura semblant a un BST facilita la cerca incremental de strings per prefixos, que és l'objectiu que cercàvem.

Cada node conté tres punters: dos apunten als fills esquerre i dret d'un BST i un altre central que forma un sub BST i que conté els símbols de la següent posició de totes les claus que tenen el mateix prefix.

De mitjana el cost de les operacions d'inserir, esborrar i buscar (`satisfan_patro`) és de O(log(l·log(s))), sent s el nombre de símbols i l és la longitud mitjana dels símbols de les claus. Té uns costos millors que un trie de tipus vector punter o primer fill següent germà que serien O(l) o O(l·s) respectivaent.

## anagrames.rep

```cpp
struct node_hash {
  string k;
  list<string> v;
  node_hash* seg;
  ...
};
node_hash **_taula;
nat _quants;
nat _M;
...
```

Per la representació de la classe anagrames s'ha escollit una estructura de taula de dispersió per la velocitat d'accés a les dades quan tenim un conjunt de dades grans. El cost de les operacions s'inserir, buscar (`mateix_anagrama_canonic`) és constant O(1) un cop tenim l'índex i podria ser O(n) en el pitjor dels casos, en cas de colisions.

La resta d'estructures considerades (arbres binaris de cerca, arbres equilibrats) tenen un cost de mitjana O(log(n)) o O(n) en el pitjor 

## iter_subset.rep

```cpp
nat _n;
nat _k;
subset _actual;
...
```

L'estructura de iter_subset en sí mateix és un renombrament d'un vector de naturals, per tant, la definició de la classe es basa en aquest i ja ens ve donada. Els costos per les operacions d'incrementar o construir seran costos lineals en funció de la variable `k`.