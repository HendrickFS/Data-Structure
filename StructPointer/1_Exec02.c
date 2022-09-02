#include <stdio.h>
#include <stdlib.h>

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

    return 0;
}