#include <stdio.h>
#include <stdlib.h>

int main(){
    int a = 10;
    int b = 20;
    int c = 30;
    int d = 40;

    int *v[] = {&a,&b,&c,&c};

    int **p = v;

    return 0;
}