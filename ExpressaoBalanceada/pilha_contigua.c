#include "pilha.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define TAM_INICIAL 30

/**************************************
* DADOS
**************************************/
struct pilha {
	TipoElemento* vetor;
	int tamVetor;
	int qtdeElementos;
};

/**************************************
* IMPLEMENTAÇÃO
**************************************/
// Desenvolva as funções
Pilha* pilha_criar(){
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    p->vetor = (TipoElemento*) malloc(sizeof(TipoElemento) * TAM_INICIAL);
    p->tamVetor = TAM_INICIAL;
    p->qtdeElementos = 0;
    return p;
}
void pilha_destruir(Pilha** endereco){
    free((*endereco)->vetor);
    free(*endereco);
    *endereco = NULL;
}
bool pilha_empilhar(Pilha* p, TipoElemento elemento){
    if (p == NULL) return false;
    if (p->qtdeElementos == p->tamVetor) {
        TipoElemento* novoVetor = (TipoElemento*) calloc(p->tamVetor + TAM_INICIAL, sizeof(TipoElemento));
        for (int i = 0; i < p->tamVetor; i++) {
            novoVetor[i] = p->vetor[i];
        }
        p->tamVetor += TAM_INICIAL;
        p->qtdeElementos++;
        p->vetor = novoVetor;
        return true;
    }
    else{
        p->vetor[p->qtdeElementos] = elemento;
        p->qtdeElementos++;
        return true;
    }
}
bool pilha_desempilhar(Pilha* p, TipoElemento* saida){
    if (p == NULL || p->qtdeElementos==0) return false;
    *saida = p->vetor[p->qtdeElementos - 1];
    p->qtdeElementos--;
    return true;
}
bool pilha_topo(Pilha* p, TipoElemento* saida){
    if (p == NULL || p->qtdeElementos==0) return false;
    *saida = p->vetor[p->qtdeElementos - 1];
    return true;
}
bool pilha_vazia(Pilha* p){
    if (p == NULL) return false;
    if (p->qtdeElementos == 0) return true;
    return false;
}
void pilha_imprimir(Pilha* p){
    if (p == NULL) return;
    for (int i = 0; i < p->qtdeElementos; i++) {
        printf(FORMATO, p->vetor[i]);
        printf("\n");
    }
}
int pilha_tamanho(Pilha* p){
    if (p == NULL) return -1;
    return p->qtdeElementos;
}
Pilha* pilha_clone(Pilha* p){
    if (p == NULL) return NULL;
    Pilha* clone = pilha_criar();
    for (int i = 0; i < p->qtdeElementos; i++) {
        pilha_empilhar(clone, p->vetor[i]);
    }
    return clone;
}
void pilha_inverter(Pilha* p){
    if (p == NULL) return;
    TipoElemento* novoVetor = (TipoElemento*) calloc(p->tamVetor, sizeof(TipoElemento));
    for (int i = 0; i < p->qtdeElementos; i++) {
        novoVetor[i] = p->vetor[(p->qtdeElementos-1) - i];
    }
    free(p->vetor);
    p->vetor = novoVetor;
}
bool pilha_empilharTodos(Pilha* p, TipoElemento* vetor, int tamVetor){
    if (p == NULL) return false;
    for (int i = 0; i < tamVetor; i++) {
        pilha_empilhar(p, vetor[i]);
    }
    return true;
}
bool pilha_toString(Pilha* f, char* str){
    if (f == NULL) return false;
    char* aux = (char*) calloc(100, sizeof(char));
    for (int i = 0; i < f->qtdeElementos; i++) {
        sprintf(aux, FORMATO, f->vetor[i]);
        strcat(str, aux);
        strcat(str, "\n");
    }
    free(aux);
    return true;
}
bool auxBalanceamento(Pilha* p,int sentido){
    char aux[6] = "";
    if (sentido == 0){
        strcpy(aux,"([{)]}");
    }else{
        strcpy(aux,")]}([{");
    }
    for (int i = 0; i < p->tamVetor; i++){
        if (p->vetor[i] == aux[0] || p->vetor[i] == aux[1] || p->vetor[i] == aux[2]){
            int pos = 0;
            for (pos; aux[pos]!=p->vetor[i];pos++);
            char caractereFinal = aux[pos+3];
            int c = i+1;
            int op = 1;
            while (op > 0 && c < p->qtdeElementos){
                if (p->vetor[c] == aux[0] || p->vetor[c] == aux[1] || p->vetor[c] == aux[2]) op++;
                else if (p->vetor[c] == aux[3] || p->vetor[c] == aux[4] || p->vetor[c] == aux[5]){
                    op--;
                    if (op == 0 && p->vetor[c] != caractereFinal) return false;
                }
                c++;
            }
            if (op > 0) return false;
        }
    }
    return true;
}

bool verificaBalanceamento(Pilha* p){
	if (p == NULL) return false;
    if (auxBalanceamento(p,0) == false) return false;
    pilha_inverter(p);
    if (auxBalanceamento(p,1) == false) return false;
    pilha_inverter(p);
    return true;
}
