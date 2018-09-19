#include <stdio.h>
#include <stdlib.h>

#include "algoritmos.h"

void init(int a[], int n, int step, int range) {
        int i;
        for (i = 0; i < n; i++) {
                int base = i * step;
                int offset = rand() % range;
                a[i] = base + offset;
        }
}

int main(){
	int *a, alg, type, size, i;
	printf("Algoritmos de ordenacao\nEscolha o algoritmo:\n1-Bubblue Sort\n2-Sentinel Bubble Sort\n3-Cocktail sort\n4-Insertion Sort\n5-Selection Sort\n6-Merge Sort\n7-Heap Sort\n8-Quick Sort\n");
	scanf("%d", &alg);
	printf("Escolha o tipo de vetor:\n1-Aleatorio\n2-Quase ordenado\n3-Quase inversamente ordenado\n4-Muitos valores repetidos\n");
	scanf("%d", &type);
	printf("Digite um K entre 2 e 6 para o tamanho do vetor: 10^K\n");
	scanf("%d", &size);
	
	a = (int*)malloc(sizeof(int)*size);
	
	init(a, size, 0, 5 * size);
	//selection_sort(a, size);
	
	for(i=0; i < size; i++){
		printf("%d ",a[i]);
	}
	printf("\n");
	return (0);
}
