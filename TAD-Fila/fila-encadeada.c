#include "fila.h"

/**************************************
* DADOS
**************************************/
typedef struct no{
    int dado;
    struct no* prox;
}No;

struct fila {
    No* inicio;
    No* fim;
    int qtde;
};

/**************************************
* IMPLEMENTAÇÃO
**************************************/
Fila* fila_criar(){
    Fila* f = (Fila*) calloc (1,sizeof(Fila*));
    f->inicio = NULL;
    f->fim = NULL;
    f->qtde = 0;
    return f;
}
void fila_destruir(Fila** enderecoFila){
    No* aux = (*enderecoFila)->inicio;
    while (aux != NULL){
        No* aux2 = aux->prox;
        free(aux);
        aux = aux2;
    }
    free(*enderecoFila);
    *enderecoFila = NULL;
}
bool fila_inserir(Fila* f, TipoElemento elemento){
    if (f == NULL) return false;
    No* novo = (No*) calloc (1,sizeof(No));
    novo->dado = elemento;
    novo->prox = NULL;
    if (f->inicio == NULL){
        f->inicio = novo;
        f->fim = novo;
    }else{
        f->fim->prox = novo;
        f->fim = novo;
    }
    f->qtde++;
    return true;
}
bool fila_remover(Fila* f, TipoElemento* saida){
    if (f == NULL || f->inicio == NULL) return false;
    No* aux = f->inicio;
    *saida = aux->dado;
    f->inicio = aux->prox;
    free(aux);
    f->qtde--;
    return true;
}
bool fila_primeiro(Fila* f, TipoElemento* saida){
    if (f == NULL || f->qtde == 0) return false;
    *saida = f->inicio->dado;
    return true;
}
bool fila_vazia(Fila* f){
    if (f == NULL) return false;
    if (f->qtde == 0) return true;
    return false;
}
int fila_tamanho(Fila* f){
    if (f == NULL) return -1;
    return f->qtde;
}
void fila_imprimir(Fila* f){
    if (f == NULL) return;
    No* aux = f->inicio;
    while (aux != NULL){
        printf(FORMATO, aux->dado);
        aux = aux->prox;
    }
    printf("\n");
}
Fila* fila_clone(Fila* f){
    if (f == NULL) return NULL;
    Fila* clone = fila_criar();
    No* aux = f->inicio;
    while (aux != NULL){
        fila_inserir(clone, aux->dado);
        aux = aux->prox;
    }
    return clone;
}
bool fila_toString(Fila* f, char* str){
    if (f == NULL) return false;
    No* aux = f->inicio;
    while (aux != NULL){
        sprintf(str, "%s" FORMATO, str, aux->dado);
        aux = aux->prox;
    }
    return true;
}
bool fila_inserirTodos(Fila* f, TipoElemento* vetor, int tamVetor){
    if (f == NULL) return false;
    for (int i = 0; i < tamVetor; i++){
        fila_inserir(f, vetor[i]);
    }
}
