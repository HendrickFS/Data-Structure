#include "pilha.h"

/**************************************
* DADOS
**************************************/
typedef struct no{
	TipoElemento dado;
	struct no *prox;
}No;

struct pilha{
	No *topo;
	int qtdeElementos;
};

/**************************************
* IMPLEMENTAÇÃO
**************************************/
// Desenvolva as funções
Pilha* pilha_criar(){
	Pilha* p = (Pilha*) malloc(sizeof(Pilha));
	p->topo = NULL;
	p->qtdeElementos = 0;
	return p;
}
void pilha_destruir(Pilha** endereco){
	No* no = (*endereco)->topo;
	while(no != NULL){
		No* no2 = no->prox;
		free(no);
		no = no2;
	}
	free(*endereco);
	*endereco = NULL;
}
bool pilha_empilhar(Pilha* p, TipoElemento elemento){
	if (p == NULL) return false;
	No* no = (No*) calloc(1,sizeof(No*));
	no->dado = elemento;
	no->prox = p->topo;
	p->topo = no;
	p->qtdeElementos++;
	return true;
}
bool pilha_desempilhar(Pilha* p, TipoElemento* saida){
	if (p == NULL || p->qtdeElementos==0) return false;
	*saida = p->topo->dado;
	No* no = p->topo;
	p->topo = p->topo->prox;
	free(no);
	return true;
}
bool pilha_topo(Pilha* p, TipoElemento* saida){
	if (p == NULL || p->qtdeElementos==0) return false;
	saida = p->topo->dado;
	return true;
}
bool pilha_vazia(Pilha* p){
	if ((p == NULL) || (p->qtdeElementos != 0)) return false;
	return true;
}
void pilha_imprimir(Pilha* p){
	if (p == NULL) return;
	No* no = p->topo;
	while (no != NULL){
		printf(FORMATO, no->dado);
		no = no->prox;
	}
	printf("\n");
}
int pilha_tamanho(Pilha* p){
	if (p == NULL) return -1;
	return p->qtdeElementos;
}
Pilha* pilha_clone(Pilha* p){
	if (p == NULL) return NULL;
	Pilha* p2 = pilha_criar();
	No* no = p->topo;
	while (no != NULL){
		pilha_empilhar(p2, no->dado);
		no = no->prox;
	}
	return p2;
}
void pilha_inverter(Pilha* p){
	Pilha* p2 = pilha_criar();
	No* no = p->topo;
	No* aux = (No*) calloc(1, sizeof(No*));
	p2->topo = aux;
	p2->qtdeElementos = p->qtdeElementos;
	while (no != NULL){
		while (aux != NULL){
			aux = aux->prox;
		}
		aux->dado = no->dado;
		no = no->prox;
	}
	Pilha* end = p;
	p = p2;
	pilha_destruir(&end);
}
bool pilha_empilharTodos(Pilha* p, TipoElemento* vetor, int tamVetor){
	if (p == NULL) return false;
	for (int i = 0; i < tamVetor; i++){
		pilha_empilhar(p, vetor[i]);
	}
	return true;
}
bool pilha_toString(Pilha* f, char* str){
	if (f == NULL) return false;
	No* no = f->topo;
	while (no != NULL){
		sprintf(str, FORMATO, no->dado);
		no = no->prox;
	}
	return true;
}