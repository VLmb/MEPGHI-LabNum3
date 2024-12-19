#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "generate_random_data.c"
#include "output_stream.c"

enum TypeOfBuilding StringToTypeOfBuilding(const char* str) {
    if (strcmp(str, "PANEL") == 0) {
        return PANEL;
    } else if (strcmp(str, "BRICK") == 0) {
        return BRICK;
    } else if (strcmp(str, "MONOLITHIC") == 0) {
        return MONOLITHIC;
    } 
}

ApartmentBuilding* ReadApartmentBuildingsFromFile(const char* filename, int* count) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error with opening file");
        return;
    }

    char line[1024];
    int capacity = 20;
    ApartmentBuilding* buildings = malloc(capacity * sizeof(ApartmentBuilding));
    *count = 0;

    while (fgets(line, sizeof(line), file)) {
        if (*count >= capacity) {
            capacity *= 2;
            ApartmentBuilding* buildings = realloc(buildings, capacity * sizeof(ApartmentBuilding));
        }

        ApartmentBuilding building;
        char* token = strtok(line, ",");
        if (token != NULL) {
            strncpy(building.Name_of_building_company, token, sizeof(building.Name_of_building_company) - 1);
            building.Name_of_building_company[sizeof(building.Name_of_building_company) - 1] = '\0';
        }

        token = strtok(NULL, ",");
        if (token != NULL) {
            strncpy(building.Area, token, sizeof(building.Area) - 1);
            building.Area[sizeof(building.Area) - 1] = '\0';
        }

        token = strtok(NULL, ",");
        if (token != NULL) {
            building.type = StringToTypeOfBuilding(token);
        }

        token = strtok(NULL, ",");
        if (token != NULL) {
            building.year = (unsigned int)atoi(token);
        }

        token = strtok(NULL, ",");
        if (token != NULL) {
            building.chute = (strcmp(token, "YES") == 0) ? true : false;
        }

        token = strtok(NULL, ",");
        if (token != NULL) {
            building.amount_of_apartment = atoi(token);
        }

        token = strtok(NULL, ",");
        if (token != NULL) {
            building.amount_of_floors = atoi(token);
        }

        token = strtok(NULL, ",");
        if (token != NULL) {
            building.average_area = atof(token);
        }
        buildings[*count] = building;
        (*count)++;
    }
    fclose(file);
    return buildings;
}

int main(){

    int n;
    ApartmentBuilding* buildings = ReadApartmentBuildingsFromFile("test.csv", &n);
    WriteToFileTable(buildings, n, "test.txt");

    return 0;
}