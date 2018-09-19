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
	int *a, size, i;
	printf("Digite o tamanho do vetor aleatorio: ");
	scanf("%d", &size);
	
	a = (int*)malloc(sizeof(int)*size);
	
	init(a, size, 0, 5 * size);
	selection_sort(a, size);
	
	for(i=0; i < size; i++){
		printf("%d ",a[i]);
	}
	printf("\n");
	return (0);
}
