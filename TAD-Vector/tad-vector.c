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

/***********************************************
* AUX FUNCTIONS
************************************************/
bool IncreaseVerify(Vector* v){
    if(v->elements < v->size) return true;
    int newSize = v->size * 2;
    int* temp = (int*) calloc(newSize, sizeof(int));
    memcpy( temp, v->array, v->elements * sizeof(int));
    free(v->array);
    v->array = temp;
    v->size = newSize;

    return true;
}

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
    IncreaseVerify(v);
    if (v->size == v->elements) return false;
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
    IncreaseVerify(v);
    if ((pos >= v->size)||(pos < 0)||(v==NULL)) return false;
    else{
        for (int i=v->size;i>pos-1;i--)
            v->array[i]=v->array[i-1];
        v->array[pos-1]=element;
        v->elements++;
        return true;
    }
}; 
bool vectorRemoveByPosition(Vector* v, int pos, int* adress){
    if ((pos >= v->size)||(pos <= 0)||(v==NULL)) return false;
    else{
        *adress=v->array[pos];
        v->array[pos]=0;
        for (int i=pos;i<v->elements-1;i++)
            v->array[i]=v->array[i+1];
    }
    v->elements--;
    return true;
};

/***********************************************
* PART 2
************************************************/
int vectorRemoveElement(Vector* v, int element){
    int pos = vectorPosition(v,element);
    vectorRemoveByPosition(v,pos,&element);
    return pos;
};
bool vectorElemento(Vector* v, int pos, int* output){
    if ((pos >= v->size)||(pos <= 0)||(v==NULL)) return false;
    *output = v->array[pos];
    return true;
};
int vectorPosition(Vector* v, int element){
    for (int i = 0; i<v->elements;i++){
        if (v->array[i]==element)
            return i;
    }
    return -1;
}; 
int vectorSize(Vector* v){
    return v->elements;
}
Vector* vectorCreateRandom(int  nElements){
    Vector* randVet = vectorCreation();
    for (int i = 0;i<nElements;i++)
        vectorAnex(randVet,rand());
    return randVet;
};
Vector* vectorImport(char* fileName){
    FILE *file = fopen(fileName,"r");
    if (file==NULL) return NULL;

    Vector* vet = vectorCreation();
    int elements;
    int aux;
    fscanf(file,"%d",&elements);
    for (int i = 0;i<elements;i++){
        fscanf(file,"%d",&aux);
        vectorAnex(vet,aux);
    }
    fclose(file);
    return vet;
};
bool vectorSubistituition(Vector* v, int pos, int newElement){
    if ((pos >= v->size)||(pos <= 0)||(v==NULL)) return false;
    v->array[pos]=newElement;
    return true;
};

/***********************************************
* PART 3
************************************************/
bool vectorSave(Vector* v, char* fileName){
    FILE *file = fopen(fileName,"wb");
    if (file ==  NULL){
        return false;
    }
    fwrite(&v->size,sizeof(int),1,file);
    fwrite(&v->elements,sizeof(int),1,file);
    fwrite(v->array,sizeof(int),v->elements,file);
    fclose(file);
    return true;
}

Vector* vectorLoad(char* fileName){
    FILE *file = fopen(fileName,"rb");
    if (file ==  NULL){
        return false;
    }
    Vector* v = vectorCreation();

    fread(&v->size,sizeof(int),1,file);
    fread(&v->elements,sizeof(int),1,file);
    fread(v->array,sizeof(int),v->elements,file);
    fclose(file);
    return v;
}