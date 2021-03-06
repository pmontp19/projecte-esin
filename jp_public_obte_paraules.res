###!----------------------------------------------
###!
###! JOCS DE PROVES DE LA CLASSE OBTE_PARAULES
###!
###!----------------------------------------------
###!
###!  1. Anagrama buit
###!     Errors: k < 3,  k > longitud(s) i longitud(s) < 3 
###!     k = 3 i k > 3
###!  2. Anagrama no buit
###!     Errors: k < 3,  k > longitud(string) i longitud(s) < 3 
###!     k = 3 i longitud(s) > 3
###!  3. k = 3 sortida = zero, una, cinc, totes les paraules
###!  4. k = 4 sortida = zero, una, algunes, totes
###!  5. k = 5 sortida = zero, totes, algunes amb diverses permutacions
###!     de la mateixa paraula
###!  6. k = 6 sortida = cero, totes, algunes amb diverses permutacions
###!  7. totes
###!  8. string conte repeticions
###!
###!------------------------------------------------------------------
###1 Anagrama buit
###!------------------------------------------------------------------
###!
#init a anagrames
###!
#spf 2 CASO a
Error::obte_paraules:41:Longitud invalida.
##Error::obte_paraules:41:Longitud invalida.
#spf 3 CA a
Error::obte_paraules:41:Longitud invalida.
##Error::obte_paraules:41:Longitud invalida.
#spf 5 CASO a
Error::obte_paraules:41:Longitud invalida.
##Error::obte_paraules:41:Longitud invalida.
#spf 3 CAS a
[]
##[]
#spf 10 CASUALIDAD a
[]
##[]
#spt CA a
Error::obte_paraules:41:Longitud invalida.
##Error::obte_paraules:41:Longitud invalida.
#spt CAS a
[]
##[]
#spt CASUALIDAD a
[]
##[]
###!
#a destroy
###!
###!
###!
###!------------------------------------------------------------------
###2 Anagrama no buit
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
###!
###!
#spf 2 CASO a
Error::obte_paraules:41:Longitud invalida.
##Error::obte_paraules:41:Longitud invalida.
#spf 3 CA a
Error::obte_paraules:41:Longitud invalida.
##Error::obte_paraules:41:Longitud invalida.
#spf 5 CASO a
Error::obte_paraules:41:Longitud invalida.
##Error::obte_paraules:41:Longitud invalida.
#spf 3 CAS a
[]
##[]
#spf 10 CASUALIDAD a
[]
##[]
#spt CA a
Error::obte_paraules:41:Longitud invalida.
##Error::obte_paraules:41:Longitud invalida.
#spt CAS a
[]
##[]
#spt CASUALIDAD a
[]
##[]
###!
###!
###!------------------------------------------------------------------
###3 k = 3
###!------------------------------------------------------------------
###!
#spf 3 TSRAOC a
[ARO, ASO, ATO, OCA, ORA, OSA, RAS, TAS, TOS]
##[ARO, ASO, ATO, OCA, ORA, OSA, RAS, TAS, TOS]
#spf 3 GMATO a
[ATO]
##[ATO]
#spf 3 GMARSO a
[ARO, ASO, ORA, OSA, RAS]
##[ARO, ASO, ORA, OSA, RAS]
#spf 3 GMARUTL a
[]
##[]
###!
###!
###!
###!------------------------------------------------------------------
###4 k = 4
###!------------------------------------------------------------------
###!
#spf 4 TSRAOC a
[ACTO, ASCO, CARO, CASO, CATO, COSA, COTA, OCAS, ORAS, OSAR, OTRA, RASO, RATO, ROSA, ROTA, SACO, SOTA, TACO, TARO, TASO, TOCA, TOSA, TRAS]
##[ACTO, ASCO, CARO, CASO, CATO, COSA, COTA, OCAS, ORAS, OSAR, OTRA, RASO, RATO, ROSA, ROTA, SACO, SOTA, TACO, TARO, TASO, TOCA, TOSA, TRAS]
#spf 4 CMAROG a
[CARO]
##[CARO]
#spf 4 GMARSO a
[ORAS, OSAR, RASO, ROSA]
##[ORAS, OSAR, RASO, ROSA]
#spf 4 GMARUTL a
[]
##[]
###!
###!
###!
###!------------------------------------------------------------------
###5 k = 5
###!------------------------------------------------------------------
###!
#spf 5 TSRAOC a
[ACTOS, CAROS, CASTO, CORSA, CORTA, COSTA, COTAS, OTRAS, RATOS, ROCAS, ROTAS, TACOS, TOCAS, TOSCA, TROCA]
##[ACTOS, CAROS, CASTO, CORSA, CORTA, COSTA, COTAS, OTRAS, RATOS, ROCAS, ROTAS, TACOS, TOCAS, TOSCA, TROCA]
#spf 5 CMAROS a
[CAROS, CORSA, ROCAS]
##[CAROS, CORSA, ROCAS]
#spf 5 SORAMC a
[CAROS, CORSA, ROCAS]
##[CAROS, CORSA, ROCAS]
#spf 5 GMARSOC a
[CAROS, CORSA, ROCAS]
##[CAROS, CORSA, ROCAS]
#spf 5 GMARUTL a
[]
##[]
###!
###!
###!
###!------------------------------------------------------------------
###6 k = 6
###!------------------------------------------------------------------
###!
#spf 6 TSRAOC a
[CORTAS, COSTRA, TROCAS]
##[CORTAS, COSTRA, TROCAS]
#spf 6 CAROST a
[CORTAS, COSTRA, TROCAS]
##[CORTAS, COSTRA, TROCAS]
#spf 6 SORAMCT a
[CORTAS, COSTRA, TROCAS]
##[CORTAS, COSTRA, TROCAS]
#spf 6 GMARSOCTG a
[CORTAS, COSTRA, TROCAS]
##[CORTAS, COSTRA, TROCAS]
#spf 6 GMARUTL a
[]
##[]
###!
###!
###!
###!------------------------------------------------------------------
###7 Totes
###!------------------------------------------------------------------
###!
#spt TSRAOC a
[ARO, ASO, ATO, OCA, ORA, OSA, RAS, TAS, TOS, ACTO, ASCO, CARO, CASO, CATO, COSA, COTA, OCAS, ORAS, OSAR, OTRA, RASO, RATO, ROSA, ROTA, SACO, SOTA, TACO, TARO, TASO, TOCA, TOSA, TRAS, ACTOS, CAROS, CASTO, CORSA, CORTA, COSTA, COTAS, OTRAS, RATOS, ROCAS, ROTAS, TACOS, TOCAS, TOSCA, TROCA, CORTAS, COSTRA, TROCAS]
##[ARO, ASO, ATO, OCA, ORA, OSA, RAS, TAS, TOS, ACTO, ASCO, CARO, CASO, CATO, COSA, COTA, OCAS, ORAS, OSAR, OTRA, RASO, RATO, ROSA, ROTA, SACO, SOTA, TACO, TARO, TASO, TOCA, TOSA, TRAS, ACTOS, CAROS, CASTO, CORSA, CORTA, COSTA, COTAS, OTRAS, RATOS, ROCAS, ROTAS, TACOS, TOCAS, TOSCA, TROCA, CORTAS, COSTRA, TROCAS]
#spt CAROST a
[ARO, ASO, ATO, OCA, ORA, OSA, RAS, TAS, TOS, ACTO, ASCO, CARO, CASO, CATO, COSA, COTA, OCAS, ORAS, OSAR, OTRA, RASO, RATO, ROSA, ROTA, SACO, SOTA, TACO, TARO, TASO, TOCA, TOSA, TRAS, ACTOS, CAROS, CASTO, CORSA, CORTA, COSTA, COTAS, OTRAS, RATOS, ROCAS, ROTAS, TACOS, TOCAS, TOSCA, TROCA, CORTAS, COSTRA, TROCAS]
##[ARO, ASO, ATO, OCA, ORA, OSA, RAS, TAS, TOS, ACTO, ASCO, CARO, CASO, CATO, COSA, COTA, OCAS, ORAS, OSAR, OTRA, RASO, RATO, ROSA, ROTA, SACO, SOTA, TACO, TARO, TASO, TOCA, TOSA, TRAS, ACTOS, CAROS, CASTO, CORSA, CORTA, COSTA, COTAS, OTRAS, RATOS, ROCAS, ROTAS, TACOS, TOCAS, TOSCA, TROCA, CORTAS, COSTRA, TROCAS]
#spt SORAMCT a
[ARO, ASO, ATO, OCA, ORA, OSA, RAS, TAS, TOS, ACTO, ASCO, CARO, CASO, CATO, COSA, COTA, OCAS, ORAS, OSAR, OTRA, RASO, RATO, ROSA, ROTA, SACO, SOTA, TACO, TARO, TASO, TOCA, TOSA, TRAS, ACTOS, CAROS, CASTO, CORSA, CORTA, COSTA, COTAS, OTRAS, RATOS, ROCAS, ROTAS, TACOS, TOCAS, TOSCA, TROCA, CORTAS, COSTRA, TROCAS]
##[ARO, ASO, ATO, OCA, ORA, OSA, RAS, TAS, TOS, ACTO, ASCO, CARO, CASO, CATO, COSA, COTA, OCAS, ORAS, OSAR, OTRA, RASO, RATO, ROSA, ROTA, SACO, SOTA, TACO, TARO, TASO, TOCA, TOSA, TRAS, ACTOS, CAROS, CASTO, CORSA, CORTA, COSTA, COTAS, OTRAS, RATOS, ROCAS, ROTAS, TACOS, TOCAS, TOSCA, TROCA, CORTAS, COSTRA, TROCAS]
#spt GMARSOCTG a
[ARO, ASO, ATO, OCA, ORA, OSA, RAS, TAS, TOS, ACTO, ASCO, CARO, CASO, CATO, COSA, COTA, OCAS, ORAS, OSAR, OTRA, RASO, RATO, ROSA, ROTA, SACO, SOTA, TACO, TARO, TASO, TOCA, TOSA, TRAS, ACTOS, CAROS, CASTO, CORSA, CORTA, COSTA, COTAS, OTRAS, RATOS, ROCAS, ROTAS, TACOS, TOCAS, TOSCA, TROCA, CORTAS, COSTRA, TROCAS]
##[ARO, ASO, ATO, OCA, ORA, OSA, RAS, TAS, TOS, ACTO, ASCO, CARO, CASO, CATO, COSA, COTA, OCAS, ORAS, OSAR, OTRA, RASO, RATO, ROSA, ROTA, SACO, SOTA, TACO, TARO, TASO, TOCA, TOSA, TRAS, ACTOS, CAROS, CASTO, CORSA, CORTA, COSTA, COTAS, OTRAS, RATOS, ROCAS, ROTAS, TACOS, TOCAS, TOSCA, TROCA, CORTAS, COSTRA, TROCAS]
#spt GMARUTL a
[]
##[]
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
###!
###!
#spf 6 OAAGLP a
[AGOLPA, GALOPA, PAGALO]
##[AGOLPA, GALOPA, PAGALO]
#spf 6 LPOAGA a
[AGOLPA, GALOPA, PAGALO]
##[AGOLPA, GALOPA, PAGALO]
#spf 5 LPOAGA a
[ALAGO, APAGO, PLAGA]
##[ALAGO, APAGO, PLAGA]
#spf 5 OAAGLP a
[ALAGO, APAGO, PLAGA]
##[ALAGO, APAGO, PLAGA]
#spf 4 LPOAGA a
[ALGA, ALGO, GALA, LAGO, LAPA, PAGA, PAGO, PALA, PALO]
##[ALGA, ALGO, GALA, LAGO, LAPA, PAGA, PAGO, PALA, PALO]
#spf 4 OAAGLP a
[ALGA, ALGO, GALA, LAGO, LAPA, PAGA, PAGO, PALA, PALO]
##[ALGA, ALGO, GALA, LAGO, LAPA, PAGA, PAGO, PALA, PALO]
#spf 3 LPOAGA a
[ALA, GOL, OLA]
##[ALA, GOL, OLA]
#spf 3 OAAGLP a
[ALA, GOL, OLA]
##[ALA, GOL, OLA]
#spt OAAGLP a
[ALA, GOL, OLA, ALGA, ALGO, GALA, LAGO, LAPA, PAGA, PAGO, PALA, PALO, ALAGO, APAGO, PLAGA, AGOLPA, GALOPA, PAGALO]
##[ALA, GOL, OLA, ALGA, ALGO, GALA, LAGO, LAPA, PAGA, PAGO, PALA, PALO, ALAGO, APAGO, PLAGA, AGOLPA, GALOPA, PAGALO]
#spt LPOAGA a
[ALA, GOL, OLA, ALGA, ALGO, GALA, LAGO, LAPA, PAGA, PAGO, PALA, PALO, ALAGO, APAGO, PLAGA, AGOLPA, GALOPA, PAGALO]
##[ALA, GOL, OLA, ALGA, ALGO, GALA, LAGO, LAPA, PAGA, PAGO, PALA, PALO, ALAGO, APAGO, PLAGA, AGOLPA, GALOPA, PAGALO]
###!
###!
###!
#spf 3 OARORC a
[ARO, OCA, ORA, ORO]
##[ARO, OCA, ORA, ORO]
#spf 5 OARORC a
[ACORO, CARRO, CORRO, CROAR]
##[ACORO, CARRO, CORRO, CROAR]
#spf 4 OARORC a
[ARCO, CARO, CORO, ORAR, ORCA, ORCO, RARO, ROCA]
##[ARCO, CARO, CORO, ORAR, ORCA, ORCO, RARO, ROCA]
#spf 6 OARORC a
[ACORRO, CORROA]
##[ACORRO, CORROA]
#spt OARORC a
[ARO, OCA, ORA, ORO, ARCO, CARO, CORO, ORAR, ORCA, ORCO, RARO, ROCA, ACORO, CARRO, CORRO, CROAR, ACORRO, CORROA]
##[ARO, OCA, ORA, ORO, ARCO, CARO, CORO, ORAR, ORCA, ORCO, RARO, ROCA, ACORO, CARRO, CORRO, CROAR, ACORRO, CORROA]
###!
#a destroy
###!
###!
[0/0]
