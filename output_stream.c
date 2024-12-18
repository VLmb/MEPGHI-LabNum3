#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "generate_random_data.c"

// Функция для преобразования значений перечисления в строку
const char* TypeOfBuildingToString(enum TypeOfBuilding type) {
    switch (type) {
        case PANEL:
            return "PANEL";
        case BRICK:
            return "BRICK";
        case MONOLITHIC:
            return "MONOLITHIC";
        default:
            return "Unknown";
    }
}

void WriteToFile(ApartmentBuilding *buildings, int n, char* filename) {

    if (filename == NULL){
        FILE* file = stdout;
        for (int i = 0; i < n; i++) {
                fprintf(file, "Name of building company: %s\n", buildings[i].Name_of_building_company);
                fprintf(file, "Area: %s\n", buildings[i].Area);
                fprintf(file, "Type of building: %s\n", TypeOfBuildingToString(buildings[i].type));
                fprintf(file, "Year: %u\n", buildings[i].year);
                fprintf(file, "Chute: %s\n", buildings[i].chute ? "YES" : "NO");
                fprintf(file, "Amount of apartments: %d\n", buildings[i].amount_of_apartment);
                fprintf(file, "Amount of floors: %d\n", buildings[i].amount_of_floors);
                fprintf(file, "Average area: %.2f\n", buildings[i].average_area);
                fprintf(file, "\n");
            }
    }
    
    else{
        FILE *file = fopen(filename, "w");
        if (file == NULL) {
            perror("Error with file opening");
            return;
        }

        char* extention = strrchr(filename, '.');

        if (strcmp(extention, ".csv") == 0){
            for (int i = 0; i < n; ++i){
                fprintf(file, "%s,%s,%s,%u,%s,%d,%d,%.2f\n",
                            buildings[i].Name_of_building_company,
                            buildings[i].Area,
                            TypeOfBuildingToString(buildings[i].type),
                            buildings[i].year,
                            buildings[i].chute ? "YES" : "NO",
                            buildings[i].amount_of_apartment,
                            buildings[i].amount_of_floors,
                            buildings[i].average_area);
            }
        }

        else if (strcmp(extention, ".txt") == 0){
            for (int i = 0; i < n; i++) {
                fprintf(file, "Name of building company: %s\n", buildings[i].Name_of_building_company);
                fprintf(file, "Area: %s\n", buildings[i].Area);
                fprintf(file, "Type of building: %s\n", TypeOfBuildingToString(buildings[i].type));
                fprintf(file, "Year: %u\n", buildings[i].year);
                fprintf(file, "Chute: %s\n", buildings[i].chute ? "YES" : "NO");
                fprintf(file, "Amount of apartments: %d\n", buildings[i].amount_of_apartment);
                fprintf(file, "Amount of floors: %d\n", buildings[i].amount_of_floors);
                fprintf(file, "Average area: %.2f\n", buildings[i].average_area);
                fprintf(file, "\n");
            }
        }

        else{
            perror("Wrong file extension");
        }
    fclose(file);
    }
}