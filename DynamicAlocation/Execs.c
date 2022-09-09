#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void conc(int v1[], int n1, int v2[], int n2,int v3[]){
    int c=0;
    for (int i=0;i<n1;i++){ 
        v3[c]=v1[i];
        c++;
    }
    for (int i=0;i<n1;i++){
        v3[c]=v2[i];
        c++;
    }
}

int* concMalloc(int v1[],int n1,int v2[],int n2){
    int* v3 = (int*) malloc ((n1+n2) * sizeof(int));
    int c=0;
    for (int i=0;i<n1;i++){ 
        v3[c]=v1[i];
        c++;
    }
    for (int i=0;i<n1;i++){
        v3[c]=v2[i];
        c++;
    }
    return v3;
}

void copy(char str1[],char str2[]){
    int len=0;
    for (len;str2[len]!=0;len++);
    for (int i=0;i<len;i++)
        str1[i]=str2[i];
}

char* copyCalloc(char str2[]){
    int len=0;
    for (len;str2[len]!=0;len++);
    char* str1=(char*) calloc(len , sizeof(char));
    for (int i=0;i<len;i++)
        str1[i]=str2[i];
    return str1;
}

void fillVector(int v[], int size, int value){
    for (int i=0;i<size;i++)
        v[i]=value;
}
int* fillVectorMalloc(int size,int value){
    int* v=(int*) malloc(size*sizeof(int));
    for (int i=0;i<size;i++)
        v[i]=value;
    return v;
}

int main(){
    int v1[]={1,2,3,4,5};
    int v2[]={6,7,8,9};
    int v3noMalloc[9];
    conc(v1,5,v2,4,v3noMalloc);
    int* v3=concMalloc(v1,5,v2,4);

    char orig[50] = "ablueblhebluha";
    char destNoCalloc[50]; 
    copy(destNoCalloc,orig);
    char* dest = copyCalloc(orig);

    int vetNoMalloc[10];
    fillVector(vetNoMalloc,10,9);
    int* v = fillVectorMalloc(10,9);

    return 0;
}