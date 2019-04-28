# projecte-esin

![diagrama](https://i.imgur.com/Hi0SuP0.png)

## Makefile

`make build` per compilar tots els fitxers del projecte i `make link` per linkar l'executable o `make all` per fer-ho d'una vegada.

Si es vol comprovar les comandes abans de fer-les, dry-run amb `make clean -n`.

## Executar el programa amb jp_public

Exemple amb mòdul iter_subset

```bash
./driver.e < jp_public/jp_public_iter_subset.in
```

Per passar els jocs de prova manualment, per mòduls (resultat correcte no hauria de donar cap sortida)

```bash
./driver.e < jp_public/jp_public_iter_subset.in | diff - jp_public/jp_public_iter_subset.res
```

## Depurar amb gdb

Estem fent servir [gdbgui](https://github.com/cs01/gdbgui) per depurar el programa. Seguint l'enllaç es troben instruccions d'instal·lació per Ubuntu, Windows i OS X.

Per instal·lar sobre un entorn virtual de Python, primer cal crear-lo, activar-lo i instal·lar `gdbgui`.

```python
python3 -m virtualenv env
source env/bin/activate
pip install gdbgui
gdbgui
```

S'obrirà el navegador per defecte. Ara a l'input superior cal introduir-hi l'executable, en aquest cas l'adreça absoluta i clicar `Load Binary`

```
/home/pere/projecte-esin/driver.e
```

Per sortir de gdbgui al terminal `CTRL+C` i per desactivar l'entorn virtual de Python `deactivate`

Amb el fitxer carregat es poden per exemple marcar els breakpoints. Per començar la depuració d'un mòdul cal entrar el fitxer .in a la l'input inferior tal com segueix, amb l'adreça relativa del fitxer .in.

```
run < jp_public/jp_public_iter_subset.in
```

## Funcions esin::util

typedef's convenientes

- nat   sirve para representar numeros enteros positivos
- byte  es un sinonimo de char; ocupa el minimo espacio posible

```cpp
typedef unsigned int nat;
typedef unsigned char byte;
```

funciones para activar/desactivar el cronometro
 `stop_time()` devuelve el tiempo en segundos transcurrido desde la ultima invocacion de `start_time()`

 ```cpp
void start_time() throw();
double stop_time() throw();
```

funciones de conversion de tipos numericos a string, e.g.  `util::tostring(-1.245) = "-1.245"`

```cpp
string tostring(long int n) throw();
string tostring(int n) throw();
string tostring(double x) throw();
```

funciones de conversion de un string a un tipo numerico, e.g. `util::toint("+39701") = 39701` lanzan excepciones de la clase 'error' si el string no representa un valor correcto del tipo correspondiente las funciones is_-tipo-(s) devuelven cierto si y solo si el string s representa a un valor del -tipo-

```cpp
int toint(const string& s) throw (error);
double todouble(const string& s) throw (error);

bool is_nat(const string& s) throw();
bool is_int(const string& s) throw();
bool is_double(const string& s) throw();
```

`pack(s)` convierte un string de 8 0's o 1's en el correspondiente byte; `unpack(b)` devuelve el string de 0's y 1's que corresponde al byte b

```cpp
byte pack(const string& s) throw(error);
string unpack(byte c) throw();
```

dado un string que contiene una secuencia de palabras w_1 ... w_n separadas por blancos, devuelve un vector x con las palabras, es decir, `x[0] = w_1`, `x[1] = w_2`, `x[2] = w_3`, ..., `x[n-1] = w_n` el argumento puede ser de tipo string (C++) o char* (C); si la cadena de caracteres se da como `char*` entonces debe estar acabada con '\0'

```cpp
void split(const string& s, vector<string>& x) throw();
void split(char* line, vector<string>& x) throw();
```

Generacion de numeros aleatorios
Uso:

```cpp
Random R; // creamos un generador de numeros aleatorios (GNA)
int m = R(a,b); // devuelve un entero en el rango [a..b]
int u = R(n);   // devuelve un entero en el rango [0..n-1]
double x = R(); // devuelve un numero real entre 0 y 1
Random R2(314159); // creamos un GNA inicializado con la
                    // 'semilla' 314159
```

Fijada una semilla el GNA siempre produce los mismos numeros aleatorios; esto es ventajoso si queremos reproducir la ejecucion de un algoritmo que usa un GNA todas las veces que queremos; cuando la semilla no se da al crear el GNA, se toma como semilla el tiempo que lleva el computador encendido lo que nos da una impresion de aletoriedad: diferentes ejecuciones, usaran semillas distintas (= tiempos distintos) y los numeros aleatorios generados en cada caso seran diferentes.

Se implementa mediante el metodo desarrollado por D. E. Knuth para la Stanford GraphBase

"Funciones" de hash genericas; se basan en la implementacion de SGI
Un 'Hash' es en realidad un objeto sobre el que se puede aplicar el operador (), y en consecuencia se puede usar igual que una funcion, e.g.

```cpp
util::Hash<string> h;
string s;
unsigned long i = h(s);
```

Alternativamente se puede usar la siguiente sintaxis:

```cpp
string s;
unsigned long i = util::hash(s);
```

`Hash<T>` esta definido (mediante especializacion parcial de
templates) para los tipos T siguientes: `string`, const `char*`, `char*`, `char`, `unsigned char`, `signed char`, `short`, `unsigned short`, `int`, `unsigned int (= nat)`, `long`, `unsigned long`, `double` y `float`.

Adicionalmente si `Hash<T>` esta definido para `T` entonces
`Hash<T*>`, `Hash<const T*>`, `Hash<vector<T> >` y `Hash<list<T> >` tambien lo estan; y si `Hash<T1>` y `Hash<T2>` estan definidos para `T1` y `T2`, entonces `Hash<pair<T1,T2> >` tambien lo esta.

## cpplint

La guia d'estil que estem seguint és la [guia de C++ de Google](https://google.github.io/styleguide/cppguide.html)
