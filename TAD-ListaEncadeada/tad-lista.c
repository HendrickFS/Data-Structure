#include "lista.h"

/**************************************
* DADOS
**************************************/

typedef struct no{
	TipoElemento dado;
	struct no    *ant;
	struct no    *prox;
}No;

struct lista{
	No *inicio;
	No *fim;
	int qtde;
};

/**************************************
* IMPLEMENTAÇÃO
**************************************/

Lista* lista_criar(){
    Lista* l = (Lista*) calloc(1, sizeof(Lista));
    l->inicio = NULL;
    l->fim = NULL;
    l->qtde = 0;

    return l;
}
void lista_destruir(Lista** endereco){

}

bool lista_anexar(Lista* l, TipoElemento elemento){
    if (l == NULL) return false;
    No* no = (No*) calloc(1,sizeof(No*));
    no->dado = elemento;
    no->prox = NULL;
    no->ant = l->fim;
    if (l->inicio == NULL) l->inicio = no;
    else l->fim->prox = no;
    l->fim = no;
    l->qtde++;
    return true;
}
int lista_posicao(Lista* l, TipoElemento elemento){
    if (l==NULL) return -1;
    No* aux = l->inicio;
    int pos = 0;
    while(aux->dado != elemento && aux != NULL){
        pos++;
        aux = aux->prox;
    }
    if(aux == NULL) return -1;
    return pos;
}
bool lista_inserir(Lista* l, TipoElemento elemento, int posicao){
    if (l == NULL || posicao < 0 || posicao > l->qtde) return false;
    No* no = (No*) calloc(1,sizeof(No*));
    no->dado = elemento;
    if (posicao == 0){
        no->prox = l->inicio;
        no->ant = NULL;
        l->inicio = no;
    }else if (posicao == l->qtde){
        no->prox = NULL;
        no->ant = l->fim;
        l->fim = no;
    }else{
        No* aux = l->inicio;
        for (int i = 0; i < posicao; i++) aux = aux->prox;
        no->prox = aux;
        no->ant = aux->ant;
        aux->ant->prox = no;
        aux->ant = no;
    }
    l->qtde++;
    return true;
}

bool lista_removerPosicao(Lista* l, int posicao, TipoElemento* endereco){
    if (l == NULL || posicao < 0 || posicao >= l->qtde) return false;
    No* aux = l->inicio;
    for (int i = 0; i < posicao; i++) aux = aux->prox;
    if (aux == l->inicio){
        l->inicio = aux->prox;
        l->inicio->ant = NULL;
    }else if (aux == l->fim){
        l->fim = aux->ant;
        l->fim->prox = NULL;
    }else{
        aux->ant->prox = aux->prox;
        aux->prox->ant = aux->ant;
    }
    *endereco = aux->dado;
    free(aux);
    l->qtde--;
    return true;
}
int lista_removerElemento(Lista* l, TipoElemento elemento){
    int pos = lista_posicao(l,elemento);
    if (pos == -1) return -1;
    lista_removerPosicao(l,pos,&elemento);
    return pos;
}

bool lista_substituir(Lista* l, int posicao, TipoElemento novoElemento){
    if (l == NULL || posicao < 0 || posicao >= l->qtde) return false;
    No* no = l->inicio;
    for (int i = 0; i < posicao; i++) no = no->prox;
    no->dado = novoElemento;
    return true;
}
bool lista_buscar(Lista* l, int posicao, TipoElemento* endereco){
    if (l == NULL || posicao < 0 || posicao >= l->qtde) return false;
    No* aux = l->inicio;
    int c = 0;
    while(c<posicao) aux = aux->prox;
    *endereco = aux->dado;
    return true;
}
int lista_tamanho(Lista* l){
    if (l == NULL) return 0;
    return l->qtde;
}
bool lista_vazia(Lista* l){
    if(l==NULL || l->qtde==0) return true;
    return false;
}
bool lista_toString(Lista* l, char* str){
    if(l == NULL) return false;
    No* aux = l->inicio;
    char strAux[100];
    while(aux != NULL){
        sprintf(strAux, FORMATO, aux->dado);
        strcat(str, strAux);
        aux = aux->prox;
    }
    return true;
}