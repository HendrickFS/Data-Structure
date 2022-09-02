#include <stdio.h>
#include <stdlib.h>

int main(){
    int v1[] = {1,2,3};
    int v2[] = {4,5,6};

    int *p1 = v1;
    int *p2 = v2;

    int *m[]={v1,v2};

    int **pm = m;

    printf("%d  %d",&p1,&p2);
    return 0;
}