#include <stdio.h>
#include <stdlib.h>

#include "algoritmos.h"

void troca(int *a, int *b){
	int tmp;
	tmp=*a;
	*a=*b;
	*b=tmp;
	return;
}

void heapify(int a[], int size, int root) {
	int f1 = 2*root + 1,
	    f2 = 2*root + 2,
	    maior = root;
	
	//Caso o filho um seja maior
	if (a[f1] > a[maior] && f1 < size) maior = f1;
	//Caso o filho dois seja maior
	if (a[f2] > a[maior] && f2 < size) maior = f2;
	
	//Caso o maior n seja a raiz
	if (maior != root) {
		troca(&a[root], &a[maior]);
		heapify(a, size, maior);
	}
	
}

void bubble_sort(int a[], int size) {
	int i, tmp, swapped;
	
	do {
		swapped = 0;
		for (i = 0; i <= size - 2; i++) //Percorrer do início até o penultimo
			if (a[i] > a[i+1]) { //Caso esteja na ordem errada
				tmp = a[i];
				a[i] = a[i+1];
				a[i+1] = tmp;
				swapped = 1;
			}
	} while (swapped); //Enquanto trocas tenham sido feitas
}

void cocktail_sort(int a[], int size) {
	int i, tmp, swapped;
	
	do {
		swapped = 0;
		for (i = 0; i <= size - 2; i++) //Percorrer do início ao penutilmo
			if (a[i] > a[i+1]) {
				tmp = a[i];
				a[i] = a[i+1];
				a[i+1] = tmp;
				swapped = 1;
			}
		
		if (!swapped) break; //Caso não haja trocas, parar
		
		swapped = 0;
		for (i = size - 2; i >= 0; i--)
			if (a[i] > a[i+1]) {
				tmp = a[i];
				a[i] = a[i+1];
				a[i+1] = tmp;
				swapped = 1;
			}
		
	} while (swapped); //Enquanto trocas tenham sido feitas
}

void selection_sort(int a[], int size) {
	int i, j, min, tmp;
	
	for (j = 0; j < size - 1; j++) {
		min = j;
		for (i = j + 1; i < size; i++)
			if (a[i] < a[min]) min = i;
		
		if (a[min] < a[j]) {
			tmp = a[min];
			a[min] = a[j];
			a[j] = tmp;
		}
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
		j=i-1;
		while(j>=0 && a[j]>p){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=p;
	}
	return;
}

void bubble_sent(int a[], int size){
	int i,j=0,troca,tmp,sent;
	do{
		troca=0;
		sent=0;
		for(i=sent;i<size-j-1;i++){
			if(a[i]>a[i+1]){
				tmp=a[i+1];
				a[i+1]=a[i];
				a[i]=tmp;
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
	}
	for(i=0;i<n2;i++){
		tmpr[i]=a[m+1+i];
	}
	i=0;j=0;k=l;
	while(i<n1 && j<n2){
		if(tmpl[i]<=tmpr[j]){
			a[k]=tmpl[i];
			i++;
		}
		else{
			a[k]=tmpr[j];
			j++;
		}
		k++;
	}
	while(i<n1){
		a[k]=tmpl[i];
		i++;
		k++;
	}
	while(j<n2){
		a[k]=tmpr[j];
		i++;
		j++;
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
	i=inicio;
	j=fim-1;
	troca(&a[fim],&a[pivot]);
	pivot=fim;
//	printf("%d\n", a[pivot]);
	while(i<j){
		while(i<j && a[i]<k){
			i++;
		}
		while(j>i && a[j]>=k){
			j--;
		}
		troca(&a[i],&a[j]);
	}
	troca(&a[i],&a[pivot]);
	quick(a, inicio, i-1);
	quick(a, i+1, fim);
	return;
}
