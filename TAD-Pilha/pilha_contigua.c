#include "pilha.h"

#define TAM_INICIAL 5

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
        int* novoVetor = (int*) calloc(p->tamVetor + TAM_INICIAL, sizeof(int));
        for (int i = 0; i < p->tamVetor; i++) {
            novoVetor[i] = p->vetor[i];
        }
        p->tamVetor += TAM_INICIAL;
        p->qtdeElementos++;
        free(p->vetor);
        p->vetor = novoVetor;
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
    int* novoVetor = (int*) calloc(p->tamVetor, sizeof(int));
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
