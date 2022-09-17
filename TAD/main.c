#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "tad-vector.h"



int main(){
    Vector* v1 = vectorCreation();
    vectorAnex(v1,0);
    vectorAnex(v1,1);
    vectorAnex(v1,2);
    vectorAnex(v1,3);
    vectorAnex(v1,4);

    char str[200]="";
    vectorToString(v1,str);
    printf("%s\n",str);

    vectorPrint(v1);

    int n;
    vectorRemoveByPosition(v1,2,&n);
    vectorPrint(v1);
    
    vectorInsert(v1,5,2);
    vectorPrint(v1);

    vectorDestruction(&v1);

    return 0;
}