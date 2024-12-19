#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

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
    int count = 5 + rand() % (len - 10);
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

ApartmentBuilding* GenerateData(int n){
    srand(time(NULL));
    ApartmentBuilding* buildings = malloc(sizeof(ApartmentBuilding) * n);
    for(int i = 0; i < n; ++i){
        GenerateString(buildings[i].Name_of_building_company, 20);
        GenerateString(buildings[i].Area, 20);
        enum TypeOfBuilding building_types[] = {PANEL, BRICK, MONOLITHIC};
        buildings[i].type = building_types[rand() % 3];
        buildings[i].year = 1960 + rand() % 64;
        buildings[i].chute = rand() % 2;
        buildings[i].amount_of_apartment = 200 + rand() % 200;
        buildings[i].amount_of_floors = 10 + rand() % 30;
        buildings[i].average_area = 35.0 + (double)rand() / RAND_MAX * 120.0;
    }
    return buildings;
}
