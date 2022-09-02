#include <stdio.h>
#include <stdlib.h>

int main(){
    int v1[] = {1,2,3};
    int v2[] = {4,5,6};

    int *p1 = v1;
    int *p2 = v2;

    int *m[]={v1,v2};

    int **pm = m;

    printf("%d\n", m[0][0]);
    printf("%d\n", m[0][1]);
    printf("%d\n", m[0][2]);
    printf("%d\n", m[1][0]);
    printf("%d\n", m[1][1]);
    printf("%d\n", m[1][2]);

    return 0;
}