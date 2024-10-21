#include <stdio.h>
#include <stdlib.h>
#include "file_handler.h"
#include "dyno_array.h"

void saveToFile(DynoArray* array, const char* filename) {
    FILE* file = fopen(filename, "wb");  // Open file in binary write mode
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    fwrite(&array->size, sizeof(int), 1, file);         // Save the size of the array
    fwrite(array->records, sizeof(Record), array->size, file);  // Write all records
    fclose(file);
}

void loadFromFile(DynoArray* array, const char* filename) {
    FILE* file = fopen(filename, "rb");  // Open file in binary read mode
    if (file == NULL) {
        printf("Error opening file for reading, starting fresh.\n");
        return;
    }
    fread(&array->size, sizeof(int), 1, file);  // Read the size of the array
    array->records = (Record*)malloc(array->size * sizeof(Record));  // Allocate memory
    fread(array->records, sizeof(Record), array->size, file);  // Read the records
    fclose(file);
}
