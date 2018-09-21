#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "algoritmos.h"

int comp=0, atrib=0;

void init(int a[], int n, int step, int range) {
        int i;
        for (i = 0; i < n; i++) {
                int base = i * step;
                int offset = rand() % range;
                a[i] = base + offset;
        }
}

int main(){
	int *a, alg, type, k, i;
	float size;
	do{
		printf("Algoritmos de ordenacao\nEscolha o algoritmo:\n1-Bubblue Sort\n2-Sentinel Bubble Sort\n3-Cocktail sort\n4-Insertion Sort\n5-Selection Sort\n6-Merge Sort\n7-Heap Sort\n8-Quick Sort\n");
		scanf("%d", &alg);
	}while(alg < 1 || alg > 8);
	do{
		printf("Escolha o tipo de vetor:\n1-Aleatorio\n2-Quase ordenado\n3-Quase inversamente ordenado\n4-Muitos valores repetidos\n");
		scanf("%d", &type);
	}while(type < 1 || type > 4);
	do{
		printf("Digite um K entre 2 e 6 para o tamanho do vetor: 10^K\n");
		scanf("%d", &k);
	}while(k < 2 || k > 6);
	
	//size=pow(10.0,k);
	size=100;
	for(i=2;i<k;i++)size*=10;
	a = (int*)malloc(sizeof(int)*size);
	
	switch(type){
		case 1:
			init(a, size, 0, 5*size);
			break;
		case 2:
			init(a, size, 10, 100);
			break;
		case 3:
			init(a, size, -1, 100);
			break;
		case 4:
			init(a, size, 0, size/10);
			break;
	}
	switch(alg){
		case 1:
			bubble_sort(a, size);
			break;
		case 2:
			bubble_sent(a, size);
			break;
		case 3:
			cocktail_sort(a, size);
			break;
		case 4:
			insert(a, size);
			break;
		case 5:
			selection_sort(a, size);
			break;
		case 6:
			merge_sort(a, 0, size-1);
			break;
		case 7:
			heap_sort(a, size);
			break;
		case 8:
			quick(a, 0, size-1);
			break;
	}
	printf("\nnumero de atribuicoes: %d\nnumero de comparacoes: %d", atrib, comp);
	return (0);
}
