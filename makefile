all: lab2

lab2: lab2.c funciones.o
	gcc lab2.c funciones.o -o lab2 -lm -lpthread

funciones.o: funciones.c funciones.h
	gcc -c funciones.c -lm

clean:
	rm -f *.o lab1 vis propiedades.txt

run:
	./lab2 -i test100.csv -o propiedades.txt -n 4 -d 100 -b