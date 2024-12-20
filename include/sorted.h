#ifndef SORTED_H
#define SORTED_H

#include "lib.h"

bool Comparator(Element* x, Element* y);
void QuickSort(Deque* deq, int first, int last);
void SortDeque(const char* input_file, const char* output_file, bool reverse);

#endif // SORTED_H
