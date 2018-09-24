/*
===================================
Headers de funcoes.c

Trabalho 1 ICC2


Leandro Satoshi - 10893103
Gabriel Fontes  - 10856803
===================================
*/

#ifndef FUNCOES_H_
#define FUNCOES_H_

typedef struct _contagem {
	unsigned long long int atr;
	unsigned long long int com;
} contagem;

contagem contagem_somar(contagem a, contagem b);
contagem contagem_dividir(contagem n, int d);

void init(int a[], int n, int step, int range);
contagem troca(int *a, int *b);
contagem heapify(int a[], int size, int root);
contagem merge(int a[], int l, int m, int r);

#endif
