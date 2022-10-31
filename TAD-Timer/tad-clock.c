#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include "tad-timer.h"

struct timer{
    clock_t start;
    clock_t end;
};

Timer* timerCreation(){   
    Timer* t = calloc(1,sizeof(Timer));
    t->start = 0;
    t->end = 0;
    return t;
};
void timerDesaloc(Timer** t){
    free(*t);
    *t = NULL;
};
bool timerStart(Timer* t){
    if (t == NULL) return false;
    time(&t->start);
    return true;
};
bool timerStop(Timer* t){
    if (t == NULL) return false;
    time(&t->end);
    return true;
};
bool timerReset(Timer* t){
    if (t==NULL) return false;
    t->start = 0;
    t->end = 0;
    return true;
};
double timerResult(Timer* t){
    if (t==NULL || t->end == 0) return -1;
    return (t->end - t->start);
};