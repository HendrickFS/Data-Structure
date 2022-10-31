#include <stdbool.h>

typedef struct timer Timer;

Timer* timerCreation();
void timerDesaloc(Timer** t);
bool timerStart(Timer* t);
bool timerStop(Timer* t);
bool timerReset(Timer* t);
double timerResult(Timer* t);