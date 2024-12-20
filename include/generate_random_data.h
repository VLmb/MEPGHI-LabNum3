#ifndef GENERATE_RANDOM_DATA_H
#define GENERATE_RANDOM_DATA_H

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

void GenerateString(char *str, size_t len);
ApartmentBuilding* GenerateData(int n);

#endif // GENERATE_RANDOM_DATA_H
