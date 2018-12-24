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

Tením també un punter al primer node `node *_arrel` per facilitar l'accés i un natural `nat _n_paraules` per reduir els cost de calcular el nombre de paraules a constant.

De mitjana el cost de les operacions d'inserir, eliminar i consultar un node és de O(l·log(s))), sent s el nombre de símbols i l és la longitud mitjana dels símbols de les claus. Té uns costos millors que un trie de tipus primer fill següent germà que seria O(l·s) però no millors que un vector punter que tindria O(l).

Els arbres ternaris de cerca combinen l'eficiència en l'accés dels subarbres amb l'estalvi de memòria, ja que és semblant al BST. L'eficiència dels TST varia significantment depenent de les entrades, van millor quan s'afegeix strings similars, especialment quan aquests comparteixen prefix. Alternativament els TST són efectius també quan emmagatzemen un nombre gran de strings curts com en el cas d'un diccionari. Els costos són molt similars als del BST, normalment el temps mitjà és logarítmic però pot ser lineal en el pitjor dels casos.

Si comparem el tries amb les taules hash, les taules hash freqüentment usen més memòria que els tries i són més lents quan es tracta de comparar un string que no es troba dintre de l'estructura, perquè ha de comparar tot el string sencer en comptes de només uns caràcters com fa el tries. Així que no ho vam veure com una bona opció.

Per tant encara que no sigui la implementació més ràpida de tries, sent vector punter més rapida que aquesta, els TST són la millor opció per emmagatzemar grans quantitats de strings a causa de la seva eficiència emmagatzeman informació, i sent perfecte per guardar strings similars. Per tant considerem que és la millor estructura per un diccionari, ja que estalvia més memòria i quan parlem de grans quantitats de paraules similars com és el cas d'un diccionari, és molt important no consumir en excés tots els recursos.

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

Per la representació de la classe anagrames s'ha escollit una estructura de taula de dispersió per la velocitat d'accés a les dades quan tenim un conjunt de dades grans. El cost de les operacions d'inserir, buscar (`mateix_anagrama_canonic`) és constant O(1) un cop tenim l'índex, i podria ser O(n) en el pitjor dels casos, en cas de col·lisions. Per evitar les col·lisions es crea sempre una taula amb un número primer, ja que la possibilitat de col·lisions és menor, i quan s'arriba al 90% de càrrega practiquem la redispersió.

Hem escollit la taula d'encadenats indirectes, cada entrada apunta a la llista encadenada de sinònims. La taula no guarda els elements en si, sinó un punter al primer element de la llista.

La taula hash conté un `string k` que serà la clau amb què relacionarem la posició de la taula, una llista de sinònims `list<string>; v` que contindrà els sinònims relacionats amb aquella clau i un punter `node_hash* seg` que marcarà un punter al següent element de la llista en cas de col·lisió.

També tenim una variable amb la taula hash per poder accedir-hi `node_hash **_taula`, un natural amb el nombre d'elements inserits `nat _quants`, amb aixó podrem calcular el factor de càrrega i veure si necesitem practicar la redispersió i finalment un natural amb la mida de la taula `nat _M`.

En aquest cas hem escollit taules hash perquè les taules hash permeten l'accés a l'instant quan l'element es troba dintre de l'estructura. En el plantejament ens demanen una llista amb els elements que comparteixen el mateix canònic en `mateix_anagrama_canonic`, per tant aquests compartiran la mateixa clau `string k`. Com hem comentat en l'estructura anterior les taules hash són una molt bona opció quan la clau que busquem ja es troba inserida a l'estructura com és en aquest cas sent llavors una elecció molt més eficient que el tries.

Un cop trobada la clau a l'estructura, s'introduirà l'element en la llista de sinònims per tal que pugui ser accessible en la pròxima cerca. En cas que hi hagi col·lisió en el punter seg es crearà o s'actualitzara un altre punter amb la informació de la col·lisió. Si la funció de dispersió és correcta com és en aquest cas, les col·lisions seran mínimes.

Hem escollit les taules hash d'encadenats indirectes, aquestes faciliten l'ordenació per clau que ens era molt important en aquesta part del projecte. L'accés al primer element no és immediat, hi ha una taula per mig. Les taules d'encadenats indirectes ens permeten no tenir que comprovar si una posició està lliure o no i treballar sense necessitat de llistes auxiliar per tant ho hem vist una estructura molt més eficient que les taules d'encadenats directes o de direccionament obert.

## iter_subset.rep

```cpp
nat _n;
nat _k;
subset _actual;
bool _final;
...
```

L'estructura de iter_subset en sí mateix és un renombrament d'un vector de naturals, per tant, la definició de la classe es basa en aquest i ja ens ve donada. Els costos per les operacions d'incrementar o construir seran costos lineals en funció de la variable `k`.

L'estructura conté un natural `nat _n` que ens dóna la mida màxima del string donat i un natural `nat _k` que ens dóna la mida del nostre vector. L'estructura també conta d'un subset `subset _actual` que ens diu el subset que tenim en aquest mateix moment i un boolea `bool _final` que ens marca si ens trobem a l'última posició del vector o no.

Pensant en els temps de càlcul vam decidir que en comptes de calcular tots els subsets era molt millor calcular el subset on ens trobàvem en aquest precís moment `subset _actual` i en cas que volguéssim avançar l'estructura calculés el següent. Estalviàvem molt més temps, ja que si calculéssim tots els subsets d'un string molt gran podríem acabar trigant molt i només podria ser que en necessitéssim un o dos.

L'estructura amb el bool `bool _final` era per poder accedir rapidament a saber si estàvem en l'última posició, ja que només havíem de preguntar si era vertader. Això és essencial en un vector, ja que quan el recorres vols saber si estàs en l'última posició per acabar de recorre'l rapidament i afegint un bool amb la resposta fèiem que el temps de calcular d'això fos constant.

Per tant considerem que aquesta és la millor estructura quant a temps i eficiencia, ja que combina una càrrega petita de treball amb uns accessos ràpids.