###! Memoria general
#set_memory 100000 1000000000
###!----------------------------------------------
###!
###! JOCS DE PROVA DE LA CLASSE ANAGRAMES
###!
###!----------------------------------------------
###!
###!  1. Diccionari buit
###!     Errors: string no es canonic i 
###!     longitud(s) < 3, longitud(s) = 3, longitud(s) > 3
###!     string canonic i longitud(s) < 3, longitud(s) = 3, longitud(s) > 3
###!  2. Diccionari no buit
###!     Errors: string no es canonic i 
###!     string canonic i longitud(s) < 3, longitud(s) = 3, longitud(s) > 3
###!  3. longitud(string) = 3, sortida = cero, una, algunes 
###!  4. longitud(string) = 4, sortida = cero, una, algunes
###!  5. longitud(string) = 5, sortida = cero, una, algunes
###!  6. longitud(string) = 6, sortida = cero, una, algunes
###!  7. string = string canonic, sortida = una, dos, algunes
###!  8. string conte repeticions
###!  9. Diccionari 500 paraules
###!
###!------------------------------------------------------------------
###1 Diccionari buit
###!------------------------------------------------------------------
###!
#init a anagrames
###!
#mac COSA
Error::anagrames:21:L'string no es un anagrama.
##Error::anagrames:21:L'string no es un anagrama.
#mac CA
Error::anagrames:21:L'string no es un anagrama.
##Error::anagrames:21:L'string no es un anagrama.
#mac OCA
Error::anagrames:21:L'string no es un anagrama.
##Error::anagrames:21:L'string no es un anagrama.
#mac ACO
[]
##[]
#mac AAACDDILSU
[]
##[]
#mac AC
[]
##[]
###!
#a destroy
###!
###!
###!
###!------------------------------------------------------------------
###2 Diccionari no buit
###!------------------------------------------------------------------
###!
#init a anagrames
#a_ins RASO
#a_ins TOSCA
#a_ins OSA
#a_ins ROSA
#a_ins ORAS
#a_ins SOTA
#a_ins CORSA
#a_ins TACOS
#a_ins TROCAS
#a_ins TROCA
#a_ins CARO
#a_ins ASCO
#a_ins RAS
#a_ins TOS
#a_ins TAS
#a_ins ROTA
#a_ins TACO
#a_ins ATO
#a_ins ORA
#a_ins CATO
#a_ins COSTRA
#a_ins OTRAS
#a_ins ACTOS
#a_ins CASTO
#a_ins CAROS
#a_ins COSA
#a_ins COSTA
#a_ins TOSAS
#a_ins ACTO
#a_ins ARO
#a_ins TOCA
#a_ins TRAS
#a_ins TARO
#a_ins ROCAS
#a_ins RATOS
#a_ins OCAS
#a_ins TASO
#a_ins OSAR
#a_ins CASO
#a_ins OCA
#a_ins CORTAS
#a_ins TOSA
#a_ins ROTAS
#a_ins TOCAS
#a_ins CORTA
#a_ins ASO
#a_ins SACO
#a_ins RATO
#a_ins COTA
#a_ins COTAS
#a_ins OTRA
#a_ins LA
#a_ins DO
#a_ins A
#a_ins AMOS
#a_ins CORTES
#a_ins DEMOSTUX
#a_ins LUZOT
#a_ins TOZUL
#a_ins LOTUZ
#a_ins ZUTOL
#a_ins DEMOSTU
#a_ins DETOSMU
#a_ins TOLUZ
###!
#a_pre OCASO
OCAS
##OCAS
###!
#mac ACCSOCA
Error::anagrames:21:L'string no es un anagrama.
##Error::anagrames:21:L'string no es un anagrama.
#mac CA
Error::anagrames:21:L'string no es un anagrama.
##Error::anagrames:21:L'string no es un anagrama.
#mac ASO
Error::anagrames:21:L'string no es un anagrama.
##Error::anagrames:21:L'string no es un anagrama.
#mac ACS
[]
##[]
#mac AAACDDILSU
[]
##[]
#mac AC
[]
##[]
###!
###!
###!
###!------------------------------------------------------------------
###3 longitud(string) = 3
###!------------------------------------------------------------------
###!
#mac ORT
[]
##[]
#mac OST
[TOS]
##[TOS]
#mac AOS
[ASO, OSA]
##[ASO, OSA]
###!
###!
###!
###!------------------------------------------------------------------
###4 longitud(string) = 4
###!------------------------------------------------------------------
###!
#mac BOTU
[]
##[]
#mac ARST
[TRAS]
##[TRAS]
#mac ACOT
[ACTO, CATO, COTA, TACO, TOCA]
##[ACTO, CATO, COTA, TACO, TOCA]
###!
###!
###!
###!------------------------------------------------------------------
###5 longitud(string) = 5
###!------------------------------------------------------------------
###!
#mac CORST
[]
##[]
#mac ACORT
[CORTA, TROCA]
##[CORTA, TROCA]
#mac ACORS
[CAROS, CORSA, ROCAS]
##[CAROS, CORSA, ROCAS]
###!
###!
###!
###!------------------------------------------------------------------
###6 longitud(string) = 6
###!------------------------------------------------------------------
###!
#mac EMORST
[]
##[]
#mac CEORST
[CORTES]
##[CORTES]
#mac ACORST
[CORTAS, COSTRA, TROCAS]
##[CORTAS, COSTRA, TROCAS]
###!
###!
###!
###!------------------------------------------------------------------
###7 string = string canonic
###!------------------------------------------------------------------
###!
#mac DEMOSTUX
[DEMOSTUX]
##[DEMOSTUX]
#mac DEMOSTU
[DEMOSTU, DETOSMU]
##[DEMOSTU, DETOSMU]
#mac LOTUZ
[LOTUZ, LUZOT, TOLUZ, TOZUL, ZUTOL]
##[LOTUZ, LUZOT, TOLUZ, TOZUL, ZUTOL]
###!
###!
###!
###!------------------------------------------------------------------
###8 String conte repeticions
###!------------------------------------------------------------------
###!
###!------------------------------------------------------------------
###8.1 String conte una repeticio
###!------------------------------------------------------------------
###!
#a_ins PLAGA
#a_ins APAGO
#a_ins AGOLPA
#a_ins GALOPA
#a_ins ALAGO
#a_ins OLA
#a_ins GOL
#a_ins ALA
#a_ins LAGO
#a_ins LAPA
#a_ins ALGA
#a_ins PAGALO
#a_ins PAGA
#a_ins GALA
#a_ins PALO
#a_ins ALGO
#a_ins PAGO
#a_ins PALA
#a_ins CROAR
#a_ins CORO
#a_ins ORO
#a_ins ACORRO
#a_ins RARO
#a_ins ORAR
#a_ins OCA
#a_ins ARO
#a_ins CORROA
#a_ins CORRO
#a_ins ORCO
#a_ins CARO
#a_ins CARRO
#a_ins ORA
#a_ins ARCO
#a_ins ROCA
#a_ins ORCA
#a_ins CORRO
#a_ins ACORO
#a_ins COORRUUZ
#a_ins CORORUZU
#a_ins CURORUZO
#a_ins CURUROZO
###!
###!
#mac AAL
[ALA]
##[ALA]
#mac AAGL
[ALGA, GALA]
##[ALGA, GALA]
#mac AALP
[LAPA, PALA]
##[LAPA, PALA]
#mac AAGLP
[PLAGA]
##[PLAGA]
#mac AAGLOP
[AGOLPA, GALOPA, PAGALO]
##[AGOLPA, GALOPA, PAGALO]
###!
###!
#mac OOR
[ORO]
##[ORO]
#mac COOR
[CORO, ORCO]
##[CORO, ORCO]
#mac AORR
[ORAR, RARO]
##[ORAR, RARO]
#mac COORR
[CORRO]
##[CORRO]
#mac ACOORR
[ACORRO, CORROA]
##[ACORRO, CORROA]
###!
###!
#mac COORRUUZ
[COORRUUZ, CORORUZU, CURORUZO, CURUROZO]
##[COORRUUZ, CORORUZU, CURORUZO, CURUROZO]
###!
#a destroy
###!
###!
###!
[0/0]