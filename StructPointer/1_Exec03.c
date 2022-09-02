#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    typedef struct produto{
        int codigo;
        char descricao[12];
        float preco;
    } Produto;
    Produto prod = {10,"Teclado",98.5};
    Produto* p = &prod;
    int* pi = &prod.codigo;
    char* pc = prod.descricao;
    float* pf = &prod.preco;

    prod.codigo = 20;
    (*p).codigo = 20;
    p->codigo = 20;
    *pi = 20;

    strcpy(prod.descricao,"Mouse");
    strcpy(*pc,"Mouse");
    strcpy((*p).descricao,"Mouse");
    strcpy(p->.descricao,"Mouse");

    prod.preco = 45.5;
    (*p).preco = 45.5;
    p->preco = 45.5;
    *pf = 45.5;

    return 0;
}