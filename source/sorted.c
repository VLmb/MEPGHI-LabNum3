#include <stdio.h>
#include <stdlib.h>
#include "deque.c"


bool Comparator(Element* x, Element* y){
    return x->value <= y->value;
}
bool RComparator(Element* x, Element* y){
    return x->value <= y->value;
}

void QuickSort(Deque* deq, int first, int last)
{
    int i = first, j = last;
    Element* el = GetElByIndex(deq, (first + last) / 2);
    
    do {
        while (!Comparator(el, GetElByIndex(deq, i))){
            i++;
        }
        while (!Comparator(GetElByIndex(deq, j), el)){
            j--;
        }
        if(i <= j) {
            if (!Comparator(GetElByIndex(deq, i), GetElByIndex(deq, j))){
                Switch(deq, GetElByIndex(deq, i), GetElByIndex(deq, j));
            }
            i++;
            j--;
        }
    } while (i <= j);
  
    if (i < last)
        QuickSort(deq, i, last);
    if (first < j)
        QuickSort(deq, first, j);
    return;
}

void QuickSortReverse(Deque* deq, int first, int last)
{
    int i = first, j = last;
    Element* el = GetElByIndex(deq, (first + last) / 2);
    
    do {
        while (Comparator(el, GetElByIndex(deq, i))){
            i++;
        }
        while (Comparator(GetElByIndex(deq, j), el)){
            j--;
        }
        if(i <= j) {
            if (Comparator(GetElByIndex(deq, i), GetElByIndex(deq, j))){
                Switch(deq, GetElByIndex(deq, i), GetElByIndex(deq, j));
            }
            i++;
            j--;
        }
    } while (i <= j);
  
    if (i < last)
        QuickSort(deq, i, last);
    if (first < j)
        QuickSort(deq, first, j);
    return;
}

int main(){
    int a[5] = {1, 2, 3, 4, 5};
    Deque* deq = ArrayToDeque(a, 5);
    QuickSort(deq, 0, 4);
    PrintDeque(deq);
    QuickSortReverse(deq, 0, 4);
    PrintDeque(deq);
}