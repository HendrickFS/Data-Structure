#include "tad-vector.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 10

struct vector{
    int* array;
    int size;
    int elements;
};

Vector* vectorCreation(){
    Vector* vet = (Vector*) calloc(1,sizeof(Vector));
    vet->array = (int*) calloc(MAX,sizeof(int));
    vet->size=MAX;
    vet->elements = 0;
    return vet;
};
void vectorDestruction(Vector** adress){
    free((*adress)->array);
    free(*adress);
    *adress = NULL;
};
bool vectorAnex(Vector* v, int element){
    if (v->size == v->elements)
        return false;
    else{
        v->array[v->elements]=element;
        v->elements++;
    }
    return true;
};
void vectorPrint(Vector* v){
    printf("[");
    for (int i=0;i<v->elements;i++){
        if (i==v->elements-1){
            printf("%d",v->array[i]);
        }
        else{
            printf("%d, ",v->array[i]);
        }
    }
    printf("]\n");
};
void vectorToString(Vector* v, char* str){
    char aux[200];
    sprintf(aux,"[");
    strcat(str,aux);
    for (int i = 0;i<v->elements;i++){
        if (i==v->elements-1){
            sprintf(aux,"%d",v->array[i]);
            strcat(str,aux);
        }
        else{
            sprintf(aux,"%d, ",v->array[i]);
            strcat(str,aux);
        }
    }
    sprintf(aux,"]");
    strcat(str,aux);
};
bool vectorInsert(Vector* v, int element, int pos){
    if ((pos >= v->size)||(pos < 0))
        return false;
    else
        v->array[pos]=element;
}; 
bool vectorRemoveByPosition(Vector* v, int pos, int* adress){
    if ((pos >= v->size)||(pos < 0))
        return false;
    else{
        *adress=v->array[pos];
        v->array[pos]=0;
    }
    return true;
};

