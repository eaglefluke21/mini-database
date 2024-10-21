#ifndef DYNO_ARRAY_H
#define DYNO_ARRAY_H

typedef struct {
    int id;
    char name[50];
    char work[50];
} Record;

typedef struct {
    Record* records;
    int size;
    int capacity;
} DynoArray;

DynoArray* initArray(int capacity);
void addRecord(DynoArray* array, int id, const char* name, const char* work);
void removeRecord(DynoArray* array, int id);
void displayRecords(DynoArray* array);
void freeArray(DynoArray* array);

#endif
