/*
===================================
Função principal.

Trabalho 1 ICC2


Leandro Satoshi - 10893103
Gabriel Fontes  - 10856803
===================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "funcoes.h"
#include "algoritmos.h"

int main(){
	int *a, alg, type, k, j;
	double size;
	
	contagem cont;
	cont.atr = 0;
	cont.com = 0;
	
	contagem media = cont;
	
	do{
		printf("Algoritmos de ordenação. \n");
		printf("Escolha o algoritmo: \n");
		printf("1 - Bubble Sort \n");
		printf("2 - Bubble Sort (Com sentinela) \n");
		printf("3 - Cocktail Sort \n");
		printf("4 - Insertion Sort \n");
		printf("5 - Selection Sort \n");
		printf("6 - Merge Sort \n");
		printf("7 - Heap Sort \n");
		printf("8 - Quick Sort \n");
		printf("> ");
		scanf("%d", &alg);
	} while (alg < 1 || alg > 8);
	
	do{
		printf("Escolha o tipo de vetor: \n");
		printf("1 - Aleatorio \n");
		printf("2 - Quase ordenado \n");
		printf("3 - Quase inversamente ordenado \n");
		printf("4 - Muitos valores repetidos \n");
		printf("> ");
		scanf("%d", &type);
	} while (type < 1 || type > 4);
	
	do{
		printf("Digite um K entre 2 e 6 para o tamanho do vetor: 10^K\n");
		printf("> ");
		scanf("%d", &k);
	} while (k < 2 || k > 6);
	size = pow(10, k);
	
	a = (int*) malloc(sizeof(int) * size);
	
	for (j = 1; j <= 5; j++) {
		switch (type){
			case 1:
				init (a, size, 0, 5*size);
				break;
			case 2:
				init (a, size, 10, 100);
				break;
			case 3:
				init (a, size, -1, 100);
				break;
			case 4:
				init (a, size, 0, size/10);
				break;
		}
	/*
		printf("\n");
		printf("Vetor inicial: \n");
		for (i = 0; i < size; i++) printf("%i ", a[i]);
		printf("\n\n");
	*/
		switch (alg){
			case 1:
				cont = bubble_sort (a, size);
				break;
			case 2:
				cont = 	bubble_sort_sent (a, size);
				break;
			case 3:
				cont = 	cocktail_sort (a, size);
				break;
			case 4:
				cont = 	insertion_sort (a, size);
				break;
			case 5:
				cont = 	selection_sort(a, size);
				break;
			case 6:
				cont = 	merge_sort(a, 0, size-1);
				break;
			case 7:
				cont = 	heap_sort(a, size);
				break;
			case 8:
				cont = 	quick_sort(a, 0, size-1);
				break;
		}
	/*	
		printf("Vetor final: \n");
		for (i = 0; i < size; i++) printf("%i ", a[i]);
		printf("\n\n\n");
	*/	
		printf("\n");
		printf("Número de comparações (%i): %lli\n", j, cont.com);
		printf("Número de atribuições (%i): %lli\n", j,  cont.atr);
		media = contagem_somar(cont, media);
	}
	media = contagem_dividir(media, 5);
	printf("\n--\n");
	printf("Número de comparações (Média): %lli\n", media.com);
	printf("Número de atribuições (Média): %lli\n", media.atr);
	return (0);
}
