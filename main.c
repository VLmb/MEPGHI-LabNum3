#include <stdio.h>
#include <stdlib.h>
#include "deque.c"

int main(){

    int array[] = {1, 2, 3, 4, 5};
    Deque* deq = ArrayToDeque(array, 5);
    int* arr = DequeToArray(deq);
    printf("%d", arr[4]-arr[0]);

    return 0;
}