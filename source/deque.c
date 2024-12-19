#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Element;
typedef struct Element Element;

struct Element
{
    int value;
    size_t index;
    Element* next;
    Element* prev;
};

typedef struct
{
    Element* begin;
    Element* end;
    size_t size;

} Deque;

//Инициализация дека
Deque* Init(){
    Deque* deque = malloc(sizeof(Deque));
    deque->begin = NULL;
    deque->end = NULL;
    deque->size = 0;
    return deque;
}


size_t Size(Deque* deque){
    return deque->size;
}

bool IsEmpty(Deque* deque){
    return (deque->begin == NULL || deque->end == NULL);
}

//Добавление в конец
void PushBack(Deque* deque, int val){
    Element* new_el = malloc(sizeof(Element));  // [beg                  end]
    new_el->value = val;
    if (deque->size == 0){
        new_el->index = 0;
        deque->begin = new_el;
        deque->end = new_el;
        new_el->prev = NULL;
        new_el->next = NULL;
    }
    else{ 
        new_el->prev = deque->end;
        new_el->prev->next = new_el;
        deque->end = new_el;
        new_el->next = NULL; 
        new_el->index = new_el->prev->index + 1;
    }
    deque->size++;
}

//Добавление в начало
void PushFront(Deque* deque, int val){
    Element* new_el = malloc(sizeof(Element)); // begin[ 11 12 ]end
    new_el->value = val;
    if (deque->size == 0){
        new_el->index = 0;
        deque->begin = new_el;
        deque->end = new_el;
        new_el->prev = NULL;
        new_el->next = NULL;
    }
    else{
        new_el->next = deque->begin;
        new_el->prev = NULL;
        deque->begin = new_el;
        new_el->next->prev = new_el;
        Element* el = new_el;
        size_t i = 0;
        while (el != NULL){
            el->index = i;
            i++;
            el = el->next;
        }
    }
    deque->size++;
}

//Добавление по указателю
void Push(Deque* deque, Element* ptr, int val){
    Element* new_el = malloc(sizeof(Element));
    Element* ptr1 = ptr->next;
    new_el->value = val;
    new_el->prev = ptr;
    ptr->next = new_el;
    new_el->next = ptr1;
    ptr1->prev = new_el;
    deque->size++;
    Element* el = new_el;
    size_t i = el->prev->index + 1;
    while (el != NULL){
        el->index = i;
        i++;
        el = el->next;
    }

}

//Получение последнего элемента в деке
int GetBack(Deque* deque){
    if (IsEmpty(deque)){
        printf("Deque is empty");
        return 0;
    }
    return deque->end->value;
}

//Получение первого элемента в деке
int GetFront(Deque* deque){
    if (IsEmpty(deque)){
        printf("Deque is empty");
        return 0;
    }
    return deque->begin->value;
}

//Удаление с конца
void PopBack(Deque* deque){
    if (IsEmpty(deque)) {
        printf("Deque is empty");
        return;
    }
    Element* i = deque->end->prev;   // // begin[ 11 12 ]end
    free(deque->end);
    deque->end = i;
    if (deque->size == 1){
        deque->size--;
        return;
    }
    deque->end->next = NULL;
    deque->size--;
}

//Удаление с начала
void PopFront(Deque* deque){
    if (IsEmpty(deque)) {
        printf("Deque is empty");
        return;
    }
    Element* i = deque->begin->next;   // // begin[ 11 12 ]end
    free(deque->begin);
    deque->begin = i;
    if (deque->size == 1){
        deque->size--;
        return;
    }
    deque->begin->prev = NULL;
    size_t x = 0;
    while (i != NULL){
        i->index = x;
        x++;
        i = i->next;
    }
    deque->size--;
}

//Удаление по указателю
void Pop(Deque* deque, Element* ptr) {
    if (ptr == NULL) return; // Добавлена проверка на нулевой указатель

    if (ptr->prev != NULL) {
        ptr->prev->next = ptr->next;
    } else {
        deque->begin = ptr->next; // ptr был первым элементом
    }
    if (ptr->next != NULL) {
        ptr->next->prev = ptr->prev;
    } else {
        deque->end = ptr->prev; // ptr был последним элементом
    }
    free(ptr);
    deque->size--;
    // Переиндексация с начала
    Element* el = deque->begin;
    size_t i = 0;
    while (el != NULL) {
        el->index = i++;
        el = el->next;
    }
}

Element* GetElByIndex(Deque* deque, size_t index){
    if (index > Size(deque) - 1){
        printf("Index out of range");
        return NULL;
    }
    Element* el = deque->begin;
    while (el->index != index){
        el = el->next;
    }
    return el;
}

//Замена элементов друг на друга
void Switch(Deque* deque, Element* el1, Element* el2){
    int val_el1 = el1->value;
    el1->value = el2->value;
    el2->value = val_el1;
}

//Очистка дека
void Clear(Deque* deque){
    Element* x = deque->begin;
    while (x->next != NULL) {
        Element* x0 = x->next;
        free(x);
        x = x0;
    }
    deque->size = 0;
}

Deque* ArrayToDeque(int* array, size_t size){
    Deque* deque = Init();
    for (int* val = array; val < array + size; val++){
        // printf("%d\n", *val);
        PushBack(deque, *val);
        // printf("%d\n", deque->end->value);
    }
    return deque;
}

int* DequeToArray(Deque* deque){
    int* array = malloc(sizeof(int) * deque->size);
    Element* el = deque->begin;
    while (el != NULL){
        array[el->index] = el->value;
        el = el->next;
    }
    return array;
}

void PrintDeque(Deque* deq){
    if (!IsEmpty(deq)){
        Element* el = deq->begin;
        do{
            printf("%d  ", el->value);
            el = el->next;
        } while(el != NULL);
    }
    else{
        printf("Deque is empty :(");
    }
    printf("\n");
    return;
}