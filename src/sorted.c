#include "lib.h"


bool Comparator(Element* x, Element* y){
    return x->value <= y->value;
}

void QuickSort(Deque* deq, int first, int last)
{
    int i = first, j = last;
    Element* el = GetElByIndex(deq, (first + last) / 2);
    
    do {
        //while(arr[i] < arr[f+l/2])
        while (!Comparator(el, GetElByIndex(deq, i))){
            i++;
        }
        //while(arr[f+l/2] < arr[j])
        while (!Comparator(GetElByIndex(deq, j), el)){
            j--;
        }
        if(i <= j) {
            Switch(deq, GetElByIndex(deq, i), GetElByIndex(deq, j));
            i++;
            j--;
        }
    } while (i <= j);
  
    if (i < last){
        QuickSort(deq, i, last);
    }
    if (first < j){
        QuickSort(deq, first, j);
    }
    return;
}


void SortDeque(const char* input_file, const char* output_file, bool reverse){
    Deque* deq = Init();
    if (input_file != NULL){
        int count;
        int* array = ReadArray(input_file, &count);
        deq = ArrayToDeque(array, count);
        if (!reverse){
            QuickSort(deq, 0, count - 1);
        }
        else{
            QuickSort(deq, 0, count - 1);
            Deque* deqr = Init();
            Element* cur_el = deq->end;
            while(cur_el != NULL){
                PushBack(deqr, cur_el->value);
                cur_el = cur_el->prev;
            }
            deq = deqr;
            
        }
        if (output_file != NULL){
            WriteDequeToFile(output_file, deq);
        }
        else{
            PrintDeque(deq);
        }
    }
    else{
        int array[1024];
        int count;
        scanf("%d", &count);
        for (int k = 0; k < count; ++k){
            int a;
            scanf("%d", &a);
            array[k] = a;
        }
        Deque* deq = ArrayToDeque(array, count);
        if (!reverse){
            QuickSort(deq, 0, count - 1);
        }
        else{
            QuickSort(deq, 0, count - 1);
        }
        if (!reverse){
            if (output_file != NULL){
                WriteDequeToFile(output_file, deq);
            }
            else{
                PrintDeque(deq);
            }
        }
        else{
            Deque* deqr = Init();
            Element* cur_el = deq->end;
            while(cur_el != NULL){
                PushBack(deqr, cur_el->value);
                cur_el = cur_el->prev;
            }
            deq = deqr;
            if (output_file != NULL){
                WriteDequeToFile(output_file, deq);
            }
            else{
                PrintDeque(deq);
            }
        }
    }
}