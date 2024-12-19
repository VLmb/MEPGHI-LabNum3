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

void WriteToFileTable(ApartmentBuilding *buildings, int n, char* filename) {

    char* str1 = "Num";
    char* str2 = "Name of company";
    char* str3 = "Area";
    char* str4 = "Type";
    char* str5 = "Year";
    char* str6 = "Chute";
    char* str7 = "Amount of apartments";
    char* str8 = "Amount of floors";
    char* str9 = "Average area";

    if (filename == NULL){
        FILE* file = stdout;
        fprintf(file, "%-3s %-20s %-20s %-12s %-5s %-6s %-21s %-17s %-13s\n", str1, str2, str3, str4, str5, str6, str7, str8, str9);
            for (int i = 0; i < n; i++) {
            fprintf(file, "%-3d %-20s %-20s %-12s %-5d %-6s %-21d %-17d %-13.2f\n",
            i + 1,
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
            // for (int i = 0; i < n; i++) {
            //     fprint(file, "Building number %d\n", i);
            //     fprintf(file, "Name of building company: %s\n", buildings[i].Name_of_building_company);
            //     fprintf(file, "Area: %s\n", buildings[i].Area);
            //     fprintf(file, "Type of building: %s\n", TypeOfBuildingToString(buildings[i].type));
            //     fprintf(file, "Year: %u\n", buildings[i].year);
            //     fprintf(file, "Chute: %s\n", buildings[i].chute ? "YES" : "NO");
            //     fprintf(file, "Amount of apartments: %d\n", buildings[i].amount_of_apartment);
            //     fprintf(file, "Amount of floors: %d\n", buildings[i].amount_of_floors);
            //     fprintf(file, "Average area: %.2f\n", buildings[i].average_area);
            //     fprintf(file, "\n");
            // }
            fprintf(file, "%-3s %-20s %-20s %-12s %-5s %-6s %-21s %-17s %-13s\n", str1, str2, str3, str4, str5, str6, str7, str8, str9);
            for (int i = 0; i < n; i++) {
                fprintf(file, "%-3d %-20s %-20s %-12s %-5d %-6s %-21d %-17d %-13.2f\n",
                i + 1,
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

        else{
            perror("Wrong file extension");
        }
    fclose(file);
    }
}

// int main(){
//     int n = 10;
//     ApartmentBuilding* houses = GenerateData(n);
//     WriteToFileTable(houses, n, "test.csv");

//     return 0;
// }