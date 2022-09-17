#include <stdbool.h>

// DADOS
typedef struct vector Vector;

// PROTÓTIPOS
Vector* vectorCreation();
void vectorDestruction(Vector** adress);
bool vectorAnex(Vector* v, int element);
void vectorPrint(Vector* v);
void vectorToString(Vector* v, char* str);
bool vectorInsert(Vector* v, int element, int pos); 
bool vectorRemoveByPosition(Vector* v, int pos, int* adress);