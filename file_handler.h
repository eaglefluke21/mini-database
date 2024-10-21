#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include "dyno_array.h"

void saveToFile(DynoArray* array, const char* filename);
void loadFromFile(DynoArray* array, const char* filename);

#endif
     