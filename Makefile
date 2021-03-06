all: build link
build: word_toolkit iter_subset anagrames diccionari obte_paraules  driver
driver: driver_joc_par.cpp
	g++ -c -std=c++98 -Wall -O0 -ansi -g driver_joc_par.cpp
anagrames: anagrames.cpp
	g++ -c -std=c++98 -Wall -O0 -ansi -g anagrames.cpp
diccionari: diccionari.cpp
	g++ -c -std=c++98 -Wall -O0 -ansi -g diccionari.cpp
iter_subset: iter_subset.cpp
	g++ -c -std=c++98 -Wall -O0 -ansi -g iter_subset.cpp
obte_paraules: obte_paraules.cpp
	g++ -c -std=c++98 -Wall -O0 -ansi -g obte_paraules.cpp
word_toolkit: word_toolkit.cpp
	g++ -c -std=c++98 -Wall -O0 -ansi -g word_toolkit.cpp
link: driver anagrames diccionari iter_subset obte_paraules word_toolkit
	g++ driver_joc_par.o anagrames.o diccionari.o iter_subset.o obte_paraules.o word_toolkit.o -o driver_joc_par.e -lesin
main_iter: main_iter.cc
	g++ main_iter.cc -std=c++98 -Wall -O0 -ansi -g -lesin -o main_iter.e
driver_custom: driver_custom.cpp
	g++ -std=c++98 -Wall -O0 -ansi -g -lesin -o driver_custom.e anagrames.cpp diccionari.cpp iter_subset.cpp obte_paraules.cpp word_toolkit.cpp driver_custom.cpp

clean:
	$(RM) $(ALL) *.o
	$(RM) $(ALL) *.e