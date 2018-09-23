#include <stdio.h>
#include <stdlib.h>
#include <math.h>

unsigned long long int comp=0, atrib=0;

void troca(int *a, int *b){
	int tmp;
	tmp=*a;
	*a=*b;
	*b=tmp;
	atrib += 3;
	return;
}

void bubble_sort(int a[], int size) {
	int i, swapped;
	do {
		swapped = 0;
		for (i = 0; i <= size - 2; i++) { //Percorrer do início até o penultimo
			comp += 1;
			if (a[i] > a[i+1]) { //Caso esteja na ordem errada
				troca(&a[i], &a[i+1]);
				swapped = 1;
			}
		}
	} while (swapped); //Enquanto trocas tenham sido feitas
}

void cocktail_sort(int a[], int size) {
	int i, swapped;
	
	do {
		swapped = 0;
		for (i = 0; i <= size - 2; i++) { //Percorrer do início ao penutilmo
			comp += 1;
			if (a[i] > a[i+1]) {
				troca(&a[i], &a[i+1]);
				swapped = 1;
			}
		}
		
		if (!swapped) break; //Caso não haja trocas, parar
		
		swapped = 0;
		for (i = size - 2; i >= 0; i--) {
			comp += 1;
			if (a[i] > a[i+1]) {
				troca(&a[i], &a[i+1]);
				swapped = 1;
			}
		}
		
	} while (swapped); //Enquanto trocas tenham sido feitas
}

void selection_sort(int a[], int size) {
	int i, j, min, tmp;
	
	for (j = 0; j < size - 1; j++) {
		min = j;
		atrib += 1;
		for (i = j + 1; i < size; i++)
			comp += 1;
			if (a[i] < a[min]) {
				min = i;
			}
		
		comp += 1;
		if (a[min] < a[j]) {
			troca(&a[min], &a[j]);
		}
	}
}

void heapify(int a[], int size, int root) {
	int f1 = 2*root + 1,
	    f2 = 2*root + 2,
	    maior = root;
	
	//Caso o filho um seja maior
	comp += 1;
	if (a[f1] > a[maior] && f1 < size) {
		maior = f1;
	}
	//Caso o filho dois seja maior
	comp += 1;
	if (a[f2] > a[maior] && f2 < size) {
		maior = f2;
	}
	
	//Caso o maior n seja a raiz
	if (maior != root) {
		troca(&a[root], &a[maior]);
		heapify(a, size, maior);
	}	
}

void heap_sort(int a[], int size) {
	int cont;
	
	for (cont = size/2 - 1; cont >= 0; cont--) heapify(a, size, cont);
	for (cont = size   - 1; cont >= 0; cont--) {
		troca(&a[0], &a[cont]);
		heapify(a, cont, 0);
	}
}

//=====

void insert(int a[], int size){
	int i,j,p;
	for(i=1; i<size ;i++){
		p=a[i];
		atrib++;
		j=i-1;
		while(j>=0 && a[j]>p){
			comp++;
			atrib++;
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=p;
		atrib++;
	}
	return;
}

void bubble_sent(int a[], int size){
	int i,j=0,troca,tmp,sent=0;
	do{
		troca=0;
		for(i=sent;i<size-j-1;i++){
			comp++;
			if(a[i]>a[i+1]){
				tmp=a[i+1];
				a[i+1]=a[i];
				a[i]=tmp;
				atrib += 3;
				troca++;
				if(troca==1){
					sent=i;
				}
			}
		}
		j++;
	}while(troca!=0 || j<size-1);
	return;
}

void merge(int a[], int l, int m, int r){
	int *tmpl, *tmpr, i, j, k;
	int n1=m-l+1;
	int n2=r-m;
	tmpl=(int*)malloc(sizeof(int)*((m-l)+1));
	tmpr=(int*)malloc(sizeof(int)*(r-m));
	for(i=0;i<n1;i++){
		tmpl[i]=a[l+i];
		atrib++;
	}
	for(i=0;i<n2;i++){
		tmpr[i]=a[m+1+i];
		atrib++;
	}
	i=0;j=0;k=l;
	while(i<n1 && j<n2){
		comp++;
		if(tmpl[i]<=tmpr[j]){
			a[k]=tmpl[i];
			i++;
			atrib++;
		}
		else{
			a[k]=tmpr[j];
			j++;
			atrib++;
		}
		k++;
	}
	while(i<n1){
		a[k]=tmpl[i];
		i++;
		k++;
		atrib++;
	}
	while(j<n2){
		a[k]=tmpr[j];
		i++;
		j++;
		atrib++;
	}
	return;
}

void merge_sort(int a[], int l, int r){
	int m =(l+r)/2;
	if(l == r){
		return;
	}
	merge_sort(a, l, m);
	merge_sort(a, m+1, r);
	merge(a,l,m,r);
	return;
}

void quick(int a[], int inicio, int fim){
	int i,j,k,pivot;
	if(inicio>=fim){
		return;
	}
	pivot=rand()%(fim-inicio) + inicio;
	k=a[pivot];
	atrib++;
	i=inicio;
	j=fim-1;
	troca(&a[fim],&a[pivot]);
	pivot=fim;
	while(i<j){
		while(i<j && a[i]<k){
			comp++;
			i++;
		}
		while(j>i && a[j]>=k){
			comp++;
			j--;
		}
		troca(&a[i],&a[j]);
	}
	troca(&a[i],&a[pivot]);
	quick(a, inicio, i-1);
	quick(a, i+1, fim);
	return;
}



//=============================================================================

void init(int a[], int n, int step, int range) {
        int i;
        for (i = 0; i < n; i++) {
                int base = i * step;
                int offset = rand() % range;
                a[i] = base + offset;
        }
}

int main(){
	int *a, alg, type, k, i, ex;
	float size;
	do{
		do{
			printf("Algoritmos de ordenacao\nEscolha o algoritmo:\n1-Bubblue Sort\n2-Sentinel Bubble Sort\n3-Cocktail sort\n4-Insertion Sort\n5-Selection Sort\n6-Merge Sort\n7-Heap Sort\n8-Quick Sort\n");
			scanf("%d", &alg);
		}while(alg < 1 || alg > 8);
		do{
			printf("Escolha o tipo de vetor:\n1-Aleatorio\n2-Quase ordenado\n3-Quase inversamente ordenado\n4-Muitos valores repetidos\n");
			scanf("%d", &type);
		}while(type < 1 || type > 4);
		do{
			printf("Digite um K entre 1 e 6 para o tamanho do vetor: 10^K\n");
			scanf("%d", &k);
		}while(k < 1 || k > 6);
		
		//size=pow(10.0,k);
		size=10;
		for(i=1;i<k;i++)size*=10;
		a = (int*)malloc(sizeof(int)*size);
		for(i=0;i<5;i++){
			atrib = 0;
			comp = 0;
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
			printf("\nNumero de atribuicoes: %lld\nNumero de comparacoes: %lld\n", atrib, comp);
		}
		for(i=0; i < size; i++) printf("%d ",a[i]);
		printf("\n");
		printf("Digite:\n1 - para continuar\n0- para sair\n");
		scanf("%d", &ex);
	}while(ex);
	return (0);
}
