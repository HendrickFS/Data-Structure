#include <stdio.h>
#include <stdlib.h>

int main(){
    int v[] = {1,2,3,4};
    int *p = v;
    printf("%d",p[0]);
    printf("%d",p[1]);
    printf("%d",p[2]);
    printf("%d",p[3]);

    return 0;
}