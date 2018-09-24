/*
===================================
Algoritmos de ordenação.

Trabalho 1 ICC2


Leandro Satoshi - 10893103
Gabriel Fontes  - 10856803
===================================
*/

#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

#include "algoritmos.h"

contagem bubble_sort(int a[], int size) {
	int i, swapped;
	contagem cont;
	cont.atr = 0;
	cont.com = 0;
	
	do {
		swapped = 0;
		for (i = 0; i <= size - 2; i++) {//Percorrer do início até o penultimo
			cont.com += 1;
			if (a[i] > a[i+1]) { //Caso esteja na ordem errada
				cont = contagem_somar(troca(&a[i], &a[i+1]), cont);
				swapped = 1;
			}
		}
	} while (swapped); //Enquanto trocas tenham sido feitas
	
	return (cont);
}

contagem bubble_sort_sent (int a[], int size) {
	int i, j = 0, swapped, sent=0;
	contagem cont;
	cont.atr = 0;
	cont.com = 0;
	
	do{
		swapped = 0;
		for(i = sent; i < (size - j - 1); i++) {
			cont.com += 1;
			if(a[i]>a[i+1]) {
				cont = contagem_somar(troca(&a[i+1], &a[i]), cont);
				swapped++;
				if(swapped) {
					sent = i;
				}
			}
		}
		j++;
	} while (swapped || j < size - 1);
	return (cont);
}

contagem cocktail_sort(int a[], int size) {
	int i, swapped;
	contagem cont;
	cont.atr = 0;
	cont.com = 0;
	
	do {
		swapped = 0;
		for (i = 0; i <= size - 2; i++) { //Percorrer do início ao penutilmo
			cont.com += 1;
			if (a[i] > a[i+1]) {
				cont = contagem_somar(troca(&a[i+1], &a[i]), cont);
				swapped = 1;
			}
		}
		
		if (!swapped) break; //Caso não haja trocas, parar
		
		swapped = 0;
		for (i = size - 2; i >= 0; i--) {
			cont.com += 1;
			if (a[i] > a[i+1]) {
				cont = contagem_somar(troca(&a[i+1], &a[i]), cont);
				swapped = 1;
			}
		}
		
	} while (swapped); //Enquanto trocas tenham sido feitas
	
	return (cont);
}

contagem insertion_sort(int a[], int size) {
	int i, j, p;
	contagem cont;
	cont.atr = 0;
	cont.com = 0;

	for(i = 1; i < size; i++) {
		p = a[i];
		cont.atr += 1;
		j = i - 1;
		
		while(j >= 0 && a[j]>p) {
			cont.atr += 1;
			cont.com += 1;
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = p;
		cont.atr += 1;
	}
	return (cont);
}

contagem selection_sort(int a[], int size) {
	int i, j, min;
	contagem cont;
	cont.atr = 0;
	cont.com = 0;
	
	for (j = 0; j < size - 1; j++) {
		min = j;
		cont.atr += 1;
		
		for (i = j + 1; i < size; i++) {
			cont.com += 1;
			if (a[i] < a[min]) {
				min = i;
				cont.atr += 1;
			}
		}
		cont.com += 1;
		if (a[min] < a[j]) {
			cont = contagem_somar(troca(&a[min], &a[j]), cont);
		}
	}
	
	return (cont);
}

contagem merge_sort(int a[], int l, int r) { 
	contagem cont;
	cont.atr = 0;
	cont.com = 0;
	
	if (l < r) { 
		int m = l+(r-l)/2; 
		cont = contagem_somar(merge_sort(a, l, m), cont); 
		cont = contagem_somar(merge_sort(a, m+1, r), cont); 
		cont = contagem_somar(merge(a, l, m, r), cont); 
	} 
	return (cont);
} 

contagem heap_sort(int a[], int size) {
	int i;
	contagem cont;
	cont.atr = 0;
	cont.com = 0;
	
	for (i = size/2 - 1; i >= 0; i--) {
		cont = contagem_somar(heapify(a, size, i), cont);
	}
	for (i = size   - 1; i >= 0; i--) {
		cont = contagem_somar(troca(&a[0], &a[i]), cont);
		cont = contagem_somar(heapify(a, i, 0), cont);
	}
	return (cont);
}


contagem quick_sort(int a[], int low, int high) {
	int random,i,j,pivot;
	contagem cont;
	cont.atr = 0;
	cont.com = 0;
	
	if (low < high) { //enquanto o inicio for menor que o fim
		random = low + rand() % (high - low); //escolhe um indice aleatorio
		cont.atr += 1;
		
		cont = contagem_somar(troca(&a[random],&a[high]), cont);//joga ele pro fim do vetor
		
		pivot = a[high];//defino ultimo elemento como pivo
		cont.atr += 1;
		
		i = (low - 1);
		
		for (j = low; j <= high - 1; j++) { 
			cont.com += 1;
			if (a[j] <= pivot) {//se o elemento j for menor q o pivo, joga pro comeco
				i++;
				cont = contagem_somar(troca(&a[i], &a[j]), cont);
			}
		}
		cont = contagem_somar(troca(&a[i+1],&a[high]), cont); //joga o pivo pro fim da lista de menores que ele
		cont = contagem_somar(quick_sort(a, low, i), cont);//como o pivot eh o 1+1, chama recursivamente ate i e a partir de 1+2
		cont = contagem_somar(quick_sort(a, i + 2, high), cont);
	}
	
	return (cont);
}

