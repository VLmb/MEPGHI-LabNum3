#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

enum TypeOfBuilding {
    PANEL,
    BRICK,
    MONOLITHIC
};

typedef struct {

    char Name_of_building_company[100];
    char Area[100];
    enum TypeOfBuilding type;
    unsigned int year;
    bool chute;
    int amount_of_apartment;
    int amount_of_floors;
    double average_area;

} ApartmentBuilding;


void GenerateString(char *str, size_t len) {
    char Up_alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char Low_alphabet[] = " abc defghijk lmnopqrst uvwxyz";
    int count = len % 10 + rand() % (len - 10);
    for (size_t i = 0; i < count; ++i) {
        if (i == 0 || (i > 0 && str[i-1] == ' ')){
            str[i] = Up_alphabet[rand() % (sizeof(Up_alphabet) - 1)];
        }
        else{
            str[i] = Low_alphabet[rand() % (sizeof(Low_alphabet) - 1)];
        }
    }
    str[count] = '\0';
}

int main(){
    srand(time(NULL));
    char str[100];
    for (int i = 0; i < 10; ++i){
        GenerateString(str, 50);
        printf("%s\n", str);
    }
    char str1[30];
    GenerateString(str1, 30);
    printf("i - %s\n", str1);
}