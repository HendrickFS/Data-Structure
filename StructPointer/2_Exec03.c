#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    typedef struct produto{
        int codigo;
        char descricao[12];
        float preco;
    } Produto;
    Produto prodA = {1,"Teclado",98.5};
    Produto prodB = {2,"Teclado",65.0};
    Produto prodC = {3,"Webcam",130.0};

    Produto* vet[4];
    vet[0]=&prodA;
    vet[1]=&prodB;
    vet[2]=&prodC;

    vet[2]->codigo=100;
    strcpy(vet[1]->descricao,"Mouse sem fio");

    Produto prodD={4,"Monitor",350.7};
    vet[3]=&prodD

    return 0;
}