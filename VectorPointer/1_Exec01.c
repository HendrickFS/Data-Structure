#include <stdio.h>
#include <stdlib.h>

int main(){
    int i = 30;
    int *x = &i;

    int v[] = {1,2,3,4};
    int *p = v;
    int *w = v + 2;

    return 0;
}