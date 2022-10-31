#include <stdbool.h>

typedef struct vector Vector;

Vector* vectorCreation();
void vectorDestruction(Vector** adress);
bool vectorAnex(Vector* v, int element);
void vectorPrint(Vector* v);
void vectorToString(Vector* v, char* str);
bool vectorInsert(Vector* v, int element, int pos); 
bool vectorRemoveByPosition(Vector* v, int pos, int* adress);
int vectorRemoveElement(Vector* v, int element);
bool vectorElemento(Vector* v, int pos, int* output);
int vectorPosition(Vector* v, int element);
int vectorSize(Vector* v);
Vector* vectorCreateRandom(int elements);
Vector* vectorImport(char* fileName);
bool vectorSubistituition(Vector* v, int pos, int newElement);
bool vectorSave(Vector* v, char* fileName);
Vector* vectorLoad(char* fileName);