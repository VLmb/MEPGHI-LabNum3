#ifndef INPUT_STREAM_H
#define INPUT_STREAM_H

#include "lib.h"

enum TypeOfBuilding StringToTypeOfBuilding(const char* str);
ApartmentBuilding* ReadApartmentBuildingsFromFile(const char* filename, int* count);
int* ReadArray(const char* filename, int* count);

#endif // INPUT_STREAM_H
