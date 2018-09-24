#include <stdio.h>
#include <stdlib.h>

#include "algoritmos.h"

void troca(int *a, int *b){
	int tmp;
	tmp=*a;
	*a=*b;
	*b=tmp;
	atrib += 3;
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

void quick(int a[], int low, int high){
    int random,i,j,pivot;
    if (low < high) { //enquanto o inicio for menor que o fim
        random= low + rand() % (high - low); //escolhe um indice aleatorio
        troca(&a[random],&a[high]);//joga ele pro fim do vetor
        pivot = a[high];//defino ultimo elemento como pivo
        i = (low - 1);
        for (j = low; j <= high - 1; j++) { 
            if (a[j] <= pivot) {//se o elemento j for menor q o pivo, joga pro comeco
                i++;
                troca(&a[i], &a[j]);
            }
        }
        troca(&a[i+1],&a[high]); //joga o pivo pro fim da lista de menores que ele
        quick(a, low, i);//como o pivot eh o 1+1, chama recursivamente ate i e a partir de 1+2
        quick(a, i + 2, high);
    }
}

void merge(int a[], int l, int m, int r) { 
    int i, j, k; 
    int n1 = m-l+1; 
    int n2 = r-m; 
    int L[n1], R[n2]; 
  
    for (i = 0; i < n1; i++){
        L[i] = a[l + i];
    }
    for (j = 0; j < n2; j++){
        R[j] = a[m + 1+ j]; 
    }
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2){ 
        if (L[i] <= R[j]){ 
            a[k] = L[i]; 
            i++; 
        } 
        else{ 
            a[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
    while (i < n1) { 
        a[k] = L[i]; 
        i++; 
        k++; 
    } 
    while (j < n2){ 
        a[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  

void merge_sort(int a[], int l, int r) { 
    if (l < r) { 
        int m = l+(r-l)/2; 
        merge_sort(a, l, m); 
        merge_sort(a, m+1, r); 
        merge(a, l, m, r); 
    } 
} 
