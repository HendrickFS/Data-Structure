#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "pilha.h"

int main(){
    Pilha* p = pilha_criar();

    pilha_empilhar(p,10);

    int vet = {20,30,40,50};
    pilha_empilharTodos(p,vet,4);
    printf("Pilha:");
    pilha_imprimir(p);
    printf("\n\n\n");

    int saida;
    pilha_desempilhar(p,&saida);
    printf("Pilha:");
    pilha_imprimir(p);
    printf("\n\n\n");

    Pilha* p2 = pilha_clone(p);
    printf("Pilha clonada:");
    pilha_imprimir(p2);
    printf("\n\n\n");

    if (pilha_vazia(p)){
        printf("Pilha vazia");
    }else{
        printf("Pilha nao vazia");
    }
    printf("\n\n\n");

    pilha_inverter(p);
    printf("Pilha invertida:");
    pilha_imprimir(p);
    printf("\n\n\n");

    int topo;
    pilha_topo(p,&topo);
    printf("Tamanho da pilha: %d",pilha_tamanho(p));
    printf("Elemento do topo: %d",topo);
    printf("\n\n\n");

    char str[100];
    pilha_toString(p,str);
    printf("Pilha em string: %s",str);

    pilha_destruir(&p);
    return 0;
}