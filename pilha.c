#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"

#define TAM_MAX 1000

struct pilha {
	int itens[TAM_MAX];
	int tp;
};

Pilha * criar() {
	Pilha * p = malloc(sizeof(Pilha));
	p->tp = 0;
	return p;
}

void destruir(Pilha * p) {
	if (p != NULL) {
		free(p);
	}
}

int desempilhar(Pilha * p) {
	if (p->tp == 0) {
		printf("Pilha vazia!\n");
		return -1;
	}
	return p->itens[--p->tp];
}

void empilhar(Pilha * p, int v) {
	if (p->tp == TAM_MAX) {
		printf("Pilha cheia!\n");
		return;
	}
	p->itens[p->tp++] = v;
}

int tamanho(Pilha * p) {
	return p->tp;
}

int topo(Pilha * p) {
	if (p->tp == 0) {
		printf("Pilha vazia!\n");
		return -1;
	}
	return p->itens[p->tp-1];
}

void listar(Pilha * p){
    int x;
    printf("[");
    for(x = 1; x < p->tp; x++){
        printf("%d ",p->itens[x]);
    }
    printf("]\n\n");
    return;
}

