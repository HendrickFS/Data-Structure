#include "fila.h"

#define TAM_INICIAL 5
/**************************************
* DADOS
**************************************/
struct fila {
	TipoElemento* vetor;
	int tamVetor;
	int inicio;
	int fim;
	int qtdeElementos;
};

/**************************************
* IMPLEMENTAÇÃO
**************************************/
Fila* fila_criar(){
    Fila* f = (Fila*) calloc (1,sizeof(Fila*));
    TipoElemento* vetor = (TipoElemento*) calloc(TAM_INICIAL, sizeof(TipoElemento));
    f->vetor = vetor;
    f->qtdeElementos = 0; 
    f->tamVetor = TAM_INICIAL;
    f->inicio = 0;
    f->fim = 0;
    return f;
}
void fila_destruir(Fila** enderecoFila){
    free((*enderecoFila)->vetor);
    free(*enderecoFila);
    *enderecoFila = NULL;
}
bool fila_inserir(Fila* f, TipoElemento elemento){
    if (f == NULL) return false;
    if (f->qtdeElementos == f->tamVetor){
        f->tamVetor *= 2;
        TipoElemento* novoVetor = (TipoElemento*) calloc(f->tamVetor,sizeof(TipoElemento));
        for (int i = 0; i<f->qtdeElementos;i++) novoVetor[f->inicio + i] = f->vetor[(f->inicio + i)%f->qtdeElementos];
        free(f->vetor);
        f->fim = f->qtdeElementos + f->inicio;
        f->vetor = novoVetor;
    }
    f->vetor[f->fim] = elemento;
    f->fim = (f->fim + 1)%f->tamVetor;
    f->qtdeElementos++;
    return true;
}
bool fila_remover(Fila* f, TipoElemento* saida){
    if (f == NULL || f->qtdeElementos == 0) return false;
    *saida = f->vetor[f->inicio];
    f->inicio = (f->inicio + 1)%f->tamVetor;
    f->qtdeElementos--;
    return true;
}
void fila_imprimir(Fila* f){
    if (f == NULL) return;
    if (f->qtdeElementos == 0) return;
    for (int i = 0; i<f->qtdeElementos;i++) {
        printf(FORMATO,f->vetor[(f->inicio + i)%f->tamVetor]);
        if (i != f->qtdeElementos - 1) printf(" ");
    }
    printf("\n");
}
