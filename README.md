# projecte-esin
## in progress
- [x] word_toolkit
- [x] itersubset
- [ ] diccionari
- [ ] anagrames
- [ ] obte_paraules

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