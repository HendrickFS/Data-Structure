#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "tad-vector.h"



void verifica(int condicao, char* mensagem){
    if(condicao){
        printf("[OK] : %s\n",mensagem);
    }else{
        printf("Erro : %s\n",mensagem);
    }
}


void testeCriarDestruir(){
    printf("---------------------------------------\n");
    printf("TESTE CRIAR E DESTRUIR \n");
    printf("---------------------------------------\n");

    char resultado_string[200];
    Vector* v1;
    v1 = vectorCreation();
    vectorToString(v1, resultado_string);
    vectorDestruction(&v1);
    
    verifica(strcmp(resultado_string, "[]") == 0, "Criar Vector vazio");
    verifica(v1 == NULL, "Destruir Vector");
}

void testeAnexar(){
    printf("---------------------------------------\n");
    printf("TESTE ANEXAR \n");
    printf("---------------------------------------\n");

    char resultado_string[200];
    Vector* v1;
    v1 = vectorCreation();

    vectorAnex(v1, 10);
    vectorToString(v1, resultado_string);
    verifica(strcmp(resultado_string, "[10]") == 0, "Anexar 1/3");

    vectorAnex(v1, 20);
    vectorToString(v1, resultado_string);
    verifica(strcmp(resultado_string, "[10,20]") == 0, "Anexar 2/3");

    vectorAnex(v1, 30);
    vectorToString(v1, resultado_string);
    verifica(strcmp(resultado_string, "[10,20,30]") == 0, "Anexar 3/3");


    vectorDestruction(&v1);
}

void testeInserir(){
    printf("---------------------------------------\n");
    printf("TESTE INSERIR \n");
    printf("---------------------------------------\n");

    char resultado_string[200];
    Vector* v1;
    v1 = vectorCreation();

    vectorAnex(v1, 10);
    vectorAnex(v1, 20);
    vectorAnex(v1, 30);

    vectorInsert(v1, 5, 0);
    vectorToString(v1, resultado_string);
    verifica(strcmp(resultado_string, "[5,10,20,30]") == 0, "Inserir primeira posicao");

    vectorInsert(v1, 15, 2);
    vectorToString(v1, resultado_string);
    verifica(strcmp(resultado_string, "[5,10,15,20,30]") == 0, "Inserir no meio");
    

    vectorInsert(v1, 40, 5);
    vectorToString(v1, resultado_string);
    verifica(strcmp(resultado_string, "[5,10,15,20,30,40]") == 0, "Inserir no fim");

    vectorDestruction(&v1);
}

void testeremoverPorPosicao(){
    printf("---------------------------------------\n");
    printf("TESTE REMOVER POR POSICAO \n");
    printf("---------------------------------------\n");

    Vector* v1;
    v1 = vectorCreation();

    vectorAnex(v1, 10);
    vectorAnex(v1, 20);
    vectorAnex(v1, 30);
    vectorAnex(v1, 40);

    char resultado_string[200];
    int elementoRemovido;
    bool resultado;
    
    resultado = vectorRemoveByPosition(v1, 0, &elementoRemovido);
    vectorToString(v1, resultado_string);
    verifica(elementoRemovido == 10, "Remover primeira posicao 1/3");
    verifica(resultado == true, "Remover primeira posicao 2/3");
    verifica(strcmp(resultado_string, "[20,30,40]") == 0, "Remover primeira posicao 3/3");
    
    resultado = vectorRemoveByPosition(v1, 1, &elementoRemovido);
    vectorToString(v1, resultado_string);
    verifica(elementoRemovido == 30, "Remover Posicao Meio 1/3");
    verifica(resultado == true, "Remover Posicao Meio 2/3");
    verifica(strcmp(resultado_string, "[20,40]") == 0, "Remover Posicao Meio 3/3");

    resultado = vectorRemoveByPosition(v1, 1, &elementoRemovido);
    vectorToString(v1, resultado_string);
    verifica(elementoRemovido == 40, "Remover ultima posicao 1/3");
    verifica(resultado == true, "Remover ultima posicao 2/3");
    verifica(strcmp(resultado_string, "[20]") == 0, "Remover ultima posicao 3/3");
    
    resultado = vectorRemoveByPosition(v1, 0, &elementoRemovido);
    vectorToString(v1, resultado_string);
    verifica(elementoRemovido == 20, "Remover unico elemento 1/3");
    verifica(resultado == true, "Remover unico elemento 2/3");
    verifica(strcmp(resultado_string, "[]") == 0, "Remover unico elemento 3/3");

    resultado = vectorRemoveByPosition(v1, 0, &elementoRemovido);
    verifica(resultado == false, "Remover em um Vector vazio");

    vectorDestruction(&v1);
}

void testeRemoverElemento(){
    printf("---------------------------------------\n");
    printf("TESTE REMOVER ELEMENTO \n");
    printf("---------------------------------------\n");

    Vector* v1 = vectorCreation();

    vectorAnex(v1, 10);
    vectorAnex(v1, 20);
    vectorAnex(v1, 30);
    vectorAnex(v1, 40);

    char resultado_string[200];
    int posicao;
    
    posicao = vectorRemoveElement(v1, 200);
    vectorToString(v1, resultado_string);
    verifica(posicao == -1, "Remover elemento que nao existe 1/2");    
    verifica(strcmp(resultado_string, "[10,20,30,40]") == 0, "Remover elemento que nao existe 2/2");


    posicao = vectorRemoveElement(v1, 10);
    vectorToString(v1, resultado_string);
    verifica(posicao == 0, "Remover elemento da primeira posicao 1/2");    
    verifica(strcmp(resultado_string, "[20,30,40]") == 0, "Remover elemento da primeira posicao 2/2");

    posicao = vectorRemoveElement(v1, 30);
    vectorToString(v1, resultado_string);
    verifica(posicao == 1, "Remover elemento do meio 1/2");    
    verifica(strcmp(resultado_string, "[20,40]") == 0, "Remover elemento do meio 2/2");

    posicao = vectorRemoveElement(v1, 40);
    vectorToString(v1, resultado_string);
    verifica(posicao == 1, "Remover elemento do fim 1/2");    
    verifica(strcmp(resultado_string, "[20]") == 0, "Remover elemento do fim 2/2");

    posicao = vectorRemoveElement(v1, 20);
    vectorToString(v1, resultado_string);
    verifica(posicao == 0, "Remover unico elemento do Vector 1/2");    
    verifica(strcmp(resultado_string, "[]") == 0, "Remover unico elemento do Vector 2/2");

    posicao = vectorRemoveElement(v1, 10);    
    verifica(posicao == -1, "Remover elemento no Vector vazio 1/1");    

}

void testePosicao(){
    printf("---------------------------------------\n");
    printf("TESTE Vector_POSICAO \n");
    printf("---------------------------------------\n");

    Vector* v1 = vectorCreation();

    vectorAnex(v1, 10);
    vectorAnex(v1, 20);
    vectorAnex(v1, 30);
    

    char resultado_string[200];
    int posicao;

    posicao = vectorPosition(v1, 10);
    verifica(posicao == 0, "Vector_posicao 1/4");
    posicao = vectorPosition(v1, 20);
    verifica(posicao == 1, "Vector_posicao 2/4");
    posicao = vectorPosition(v1, 30);
    verifica(posicao == 2, "Vector_posicao 3/4");
    posicao = vectorPosition(v1, -50);
    verifica(posicao == -1, "Vector_posicao 4/4");

    verifica(vectorSize(v1) == 3, "Tamanho do Vector");

    vectorDestruction(&v1);
}

void testeElemento(){
    printf("---------------------------------------\n");
    printf("TESTE Vector_POSICAO \n");
    printf("---------------------------------------\n");

    Vector* v1 = vectorCreation();

    vectorAnex(v1, 10);
    vectorAnex(v1, 20);
    vectorAnex(v1, 30);
    

    char resultado_string[200];
    int elemento;
    bool resultado;

    resultado = vectorElemento(v1, 0, &elemento);
    verifica(resultado == true && elemento == 10, "Vector_elemento 1/4");

    resultado = vectorElemento(v1, 1, &elemento);
    verifica(resultado == true && elemento == 20, "Vector_elemento 2/4");

    resultado = vectorElemento(v1, 2, &elemento);
    verifica(resultado == true && elemento == 30, "Vector_elemento 3/4");

    resultado = vectorElemento(v1, 5, &elemento);
    verifica(resultado == false, "Vector_elemento 4/4");

    vectorDestruction(&v1);
}

void testeCriarAleatorio(){
    printf("---------------------------------------\n");
    printf("TESTE Vector ALEATORIO \n");
    printf("---------------------------------------\n");

    char resultado_string[500];
    

    Vector* v1 = vectorCreateRandom(5);
    vectorToString(v1, resultado_string);
    printf("%s\n", resultado_string);
    verifica(vectorSize(v1) == 5, "Vector aleatorio 1/2");


    Vector* v2 = vectorCreateRandom(10);
    vectorToString(v2, resultado_string);
    printf("%s\n", resultado_string);
    verifica(vectorSize(v2) == 10, "Vector aleatorio 2/2");

    vectorDestruction(&v1);
    vectorDestruction(&v2);

}

int main(){

    // testeRemoverElemento();
    // testeElemento();
    // testePosicao();
    // testeCriarAleatorio();

    return 0;
}