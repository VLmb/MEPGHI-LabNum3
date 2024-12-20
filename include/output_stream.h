#ifndef OUTPUT_STREAM_H
#define OUTPUT_STREAM_H

#include "lib.h"

const char* TypeOfBuildingToString(enum TypeOfBuilding type);
void WriteToFileTable(ApartmentBuilding *buildings, int n, const char* filename);
void WriteDequeToFile(const char* output_file, Deque* deq);
void PrintData(const char* input_file, const char* output_file);

#endif // OUTPUT_STREAM_H