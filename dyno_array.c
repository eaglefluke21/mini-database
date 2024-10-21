#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "dyno_array.h"

DynoArray* initArray(int capacity) {
    DynoArray* array = (DynoArray*)malloc(sizeof(DynoArray));
    array->records = (Record*)malloc(capacity * sizeof(Record));
    array->size = 0;
    array->capacity = capacity;
    return array;
}

void resizeArray(DynoArray* array) {
    int newCapacity = array->capacity * 2;
    array->records = (Record*)realloc(array->records, newCapacity * sizeof(Record));
    array->capacity = newCapacity;
}

void addRecord(DynoArray* array, int id, const char* name, const char* work) {
    if (array->size == array->capacity) {
        resizeArray(array);
    }
    array->records[array->size].id = id;
    strcpy(array->records[array->size].name, name);
    strcpy(array->records[array->size].work, work);
    array->size++;
}

void removeRecord(DynoArray* array, int id) {
    for (int i = 0; i < array->size; i++) {
        if (array->records[i].id == id) {
            for (int j = i; j < array->size - 1; j++) {
                array->records[j] = array->records[j + 1];
            }
            array->size--;
            break;
        }
    }
}

void displayRecords(DynoArray* array) {
    printf("ID\tName\t\tWork\n");
    printf("-----------------------------\n");
    for (int i = 0; i < array->size; i++) {
        printf("%d\t%s\t\t%s\n", array->records[i].id, array->records[i].name, array->records[i].work);
    }
}

void freeArray(DynoArray* array) {
    free(array->records);
    free(array);
}
