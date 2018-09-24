/*
===================================
Funções auxiliares e struct para armazenar contagens.

Trabalho 1 ICC2


Leandro Satoshi - 10893103
Gabriel Fontes  - 10856803
===================================
*/

#include <stdio.h>
#include <stdlib.h>

#include "funcoes.h"

//Somar duas contagens
contagem contagem_somar(contagem a, contagem b) {
	a.atr += b.atr;
	a.com += b.com;
	
	return (a);
}

//Dividir uma contagem
contagem contagem_dividir(contagem n, int d) {
	n.atr /= d;
	n.com /= d;
	
	return (n);
}

//Função para criar um vetor com atributos dados
void init(int a[], int n, int step, int range) {
		int i;
		for (i = 0; i < n; i++) {
				int base = i * step;
				int offset = rand() % range;
				a[i] = base + offset;
		}
}

//Troca dois elementos dados
contagem troca(int *a, int *b){
	contagem cont;
	int tmp;
	
	tmp=*a;
	*a=*b;
	*b=tmp;
	
	cont.com = 0;
	cont.atr = 3;
	return (cont);
}

//Ordena o vetor dado em um heap
contagem heapify(int a[], int size, int root) {
	int f1 = 2*root + 1,
		f2 = 2*root + 2,
		maior = root;
	contagem cont;
	
	cont.atr = 0;
	cont.com = 3;
	
	//Caso o filho um seja maior
	
	if (f1 < size && a[f1] > a[maior]) {
		cont.atr += 1;
		maior = f1;
	}
	
	//Caso o filho dois seja maior
	if (f2 < size && a[f2] > a[maior]) {
		cont.atr += 1;
		maior = f2;
	}
	
	//Caso o maior n seja a raiz
	if (maior != root) {
		troca(&a[root], &a[maior]);
		cont = contagem_somar(heapify(a, size, maior), cont);
	}
	
	return (cont);
	
}

//Une dois subvetores
contagem merge(int a[], int l, int m, int r) { 
	int i, j, k,
		n1 = m-l+1,
		n2 = r-m,
		L[n1], R[n2];
	contagem cont;
	cont.atr = 0;
	cont.com = 0;
  
	for (i = 0; i < n1; i++){
		L[i] = a[l + i];
		cont.atr += 1;
	}
	for (j = 0; j < n2; j++){
		R[j] = a[m + 1+ j]; 
		cont.atr += 1;
	}
	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2){ 
		cont.com += 1;
		if (L[i] <= R[j]){ 
			a[k] = L[i];
			i++;
			cont.atr += 1;
		} 
		else{ 
			a[k] = R[j]; 
			j++;
			cont.atr += 1;
		} 
		k++; 
	} 
	while (i < n1) { 
		a[k] = L[i]; 
		i++; 
		k++;
		cont.atr += 1;
	} 
	while (j < n2){ 
		a[k] = R[j]; 
		j++; 
		k++;
		cont.atr += 1;
	} 
	return (cont);
}
