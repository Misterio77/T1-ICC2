all: T1-ICC2

T1-ICC2: main.o algoritmos.o funcoes.o
	gcc -o T1-ICC2 main.o algoritmos.o funcoes.o -lm

funcoes.o: src/funcoes.c
	gcc -o funcoes.o -c src/funcoes.c -g -Wall

algoritmos.o: src/algoritmos.c
	gcc -o algoritmos.o -c src/algoritmos.c -g -Wall

main.o: src/main.c src/algoritmos.h src/funcoes.h
	gcc -o main.o -c src/main.c -g -Wall

clean:
	rm -f *.o T1-ICC2
