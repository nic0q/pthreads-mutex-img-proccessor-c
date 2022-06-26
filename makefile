all: lab2

lab2: lab2.c funciones.o
	gcc lab2.c funciones.o -o lab2 -lm -pthread

funciones.o: funciones.c funciones.h
	gcc -c funciones.c -lm

clean:	# Elimina ejecutable, archivo de salida y .o's
	rm -f *.o lab2 propiedades.txt

run:		# Test de Ejemplo
	./lab2 -i test10000.csv -o propiedades.txt -n 4 -d 100 -h 5 -c 3 -b

runSilent:	# Test de Ejemplo sin vista por consola
	./lab2 -i test10000.csv -o propiedades.txt -n 4 -d 100 -h 5 -c 3

run100:	# Test de Ejemplo con 100 visibilidades
	./lab2 -i test100.csv -o propiedades.txt -n 4 -d 100 -h 5 -c 3 -b

