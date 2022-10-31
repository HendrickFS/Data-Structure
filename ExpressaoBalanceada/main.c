#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "pilha.h"

int main(){
    Pilha* equacao = pilha_criar();


    char* eq = "(5+(4+4-[7*6]())/2)";
    pilha_empilharTodos(equacao,eq,18);
    printf("Equacao:\n");
    pilha_imprimir(equacao);

    if (verificaBalanceamento(equacao)) printf("Equacao balanceada");
    else printf("Equacao nao balanceada");

    return 0;
}