#include <stdio.h>
#include <stdlib.h>

void bubble(int a[], int size) {
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

void cocktail(int a[], int size) {
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

void selection(int a[], int size) {
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
	int i,j=0,troca,tmp;
	do{
		troca=0;
		for(i=0;i<size-j-1;i++){
			if(a[i]>a[i+1]){
				tmp=a[i+1];
				a[i+1]=a[i];
				a[i]=tmp;
				troca++;
			}
		}
		j++;
	}while(troca!=0 || j<size-1);
	return;
}
/*
void merge_sort(int a[], int l, int r){
	int m =(l+r)/2;
	if(m == l){
		return;
	}
	merge_sort(a, l, m);
	merge_sort(a, m+1, r);
	merge();
	return;
}

void merge*/
