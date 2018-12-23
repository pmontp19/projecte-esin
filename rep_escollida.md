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

L'estructura escollida per la representació de la classe `diccionari` és un arbre ternari de cerca (TST). Aquesta estructura semblant a un BST facilita la cerca incremental de strings per prefixos, que és l'objectiu que cercàvem, els arbres ternaris de cerca faciliten la descomposició de paraules.

Cada node conté tres punters: dos apunten als fills esquerre i dret d'un BST i un altre central que forma un sub BST i que conté els símbols de la següent posició de totes les claus que tenen el mateix prefix.

De mitjana el cost de les operacions d'inserir, eliminar i consultar un node és de O(l·log(s))), sent s el nombre de símbols i l és la longitud mitjana dels símbols de les claus. Té uns costos millors que un trie de tipus primer fill següent germà que seria O(l·s) però no millors que un vector punter que tindria O(l).

Els arbres ternaris de cerca combinen l'eficiència en l'accés dels subarbres amb l'estalvi de memòria ja que es semblant al BST. L'eficiencia dels TST varia significantment depenent de les entrades, van millor quan s'afegeix strings similars, especialment quant aquests comparteixen prefix. Alternativament els TST son efectius també quan enmgatzeman un nombre gran de strings curts com en el cas d'un diccionari. Els costos son molt similars als del BST, normalment el temps mig es logaritmic però pot ser lineal en el pitjor dels casos.

Si comparem el tries amb les taules hash, les taules hash frecuentment usen més memoria que els tries i són més lents quan es tracta de comparar un string que no es troba dintre de l'estructura, perque ha de comparar tot el string sencer en comptes de només uns caracters com fa el tries. Així que no ho vam veure com una bona opció.

Per tant encara que no sigui l'implementació més ràpida de tries, sent vector punter més rapida que aquesta, els TST són la millor opció per enmagatzemar grans quantitats de strings degut a la seva eficiencia enmagatzeman informació, i sent perfecte per guardar strings similars. Per tant considerem que és la millor estructura per un diccionari ja que estalvia més memoria i quan parlem de gran quantitats de paraules similars com és el cas d'un diccionari, és molt important no consumir en excés tots els recursos.

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

Per la representació de la classe anagrames s'ha escollit una estructura de taula de dispersió per la velocitat d'accés a les dades quan tenim un conjunt de dades grans. El cost de les operacions s'inserir, buscar (`mateix_anagrama_canonic`) és constant O(1) un cop tenim l'índex i podria ser O(n) en el pitjor dels casos, en cas de colisions. Per evitar les colisions es crea sempre una taula amb un numero prim ja que la possibilitat de colisions es menor, i quan s'arriba al 90% de carrega practiquen la redispersió.

La resta d'estructures considerades (arbres binaris de cerca, arbres equilibrats) tenen un cost de mitjana O(log(n)) o O(n) en el pitjor 

## iter_subset.rep

```cpp
nat _n;
nat _k;
subset _actual;
...
```

L'estructura de iter_subset en sí mateix és un renombrament d'un vector de naturals, per tant, la definició de la classe es basa en aquest i ja ens ve donada. Els costos per les operacions d'incrementar o construir seran costos lineals en funció de la variable `k`.