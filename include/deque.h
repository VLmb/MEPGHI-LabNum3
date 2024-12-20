#ifndef DEQUE_H
#define DEQUE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Element;
typedef struct Element Element;

struct Element {
    int value;
    size_t index;
    Element* next;
    Element* prev;
};

typedef struct {
    Element* begin;
    Element* end;
    size_t size;
} Deque;

Deque* Init();
size_t Size(Deque* deque);
bool IsEmpty(Deque* deque);
void PushBack(Deque* deque, int val);
void PushFront(Deque* deque, int val);
void Push(Deque* deque, Element* ptr, int val);
int GetBack(Deque* deque);
int GetFront(Deque* deque);
void PopBack(Deque* deque);
void PopFront(Deque* deque);
void Pop(Deque* deque, Element* ptr);
Element* GetElByIndex(Deque* deque, size_t index);
void Switch(Deque* deque, Element* el1, Element* el2);
void Clear(Deque* deque);
Deque* ArrayToDeque(int* array, size_t size);
int* DequeToArray(Deque* deque);
void PrintDeque(Deque* deq);

#endif // DEQUE_H
