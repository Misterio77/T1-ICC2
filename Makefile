all: T1-ICC2

T1-ICC2: main.o algoritmos.o
	gcc -o T1-ICC2 main.o algoritmos.o

algoritmos.o: src/algoritmos.c
	gcc -o algoritmos.o -c src/algoritmos.c -g -Wall

main.o: src/main.c src/algoritmos.h
	gcc -o main.o -c src/main.c -g -Wall

clean:
	rm -f *.o
mrproper: clean
	rm -f T1-ICC2
