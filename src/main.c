#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"


int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s [--generate N | --sort | --print]\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (strcmp(argv[1], "--generate") == 0 || strcmp(argv[1], "-g") == 0) {
        if (argc < 3) {
            fprintf(stderr, "Usage: %s --generate N [--out output.csv]\n", argv[0]);
            return EXIT_FAILURE;
        }
        int n = atoi(argv[2]);
        char* output_file = NULL;

        for (int i = 3; i < argc; i++) {
            if (strcmp(argv[i], "-o") == 0) {
                output_file = argv[++i];
            }
            else if (strncmp(argv[i], "--out=", 6) == 0){
                const char* prefix = "--out=";
                output_file = argv[i] + 6;
            }
        }
        WriteToFileTable(GenerateData(n), n, output_file);
    }
 
    else if (strcmp(argv[1], "--sort") == 0 || strcmp(argv[1], "-s") == 0) {
        char *input_file = NULL;
        char *output_file = NULL;
        bool reverse = false;
        int count;

        for (int i = 2; i < argc; i++) {
            if (strcmp(argv[i], "-i") == 0) {
                input_file = argv[++i];
            }
            else if (strncmp(argv[i], "--in=", 5) == 0){
                const char* prefix = "--in=";
                input_file = argv[i] + 5;
            }
            else if (strncmp(argv[i], "--out=", 6) == 0){
                const char* prefix = "--out=";
                output_file = argv[i] + 6;
            }
            else if (strcmp(argv[i], "-o") == 0) {
                output_file = argv[++i];
            } 
            else if (strncmp(argv[i], "--type", 6) == 0 || strcmp(argv[i], "-t") == 0) {
                if (strcmp(argv[i] + 7, "desc") == 0 || strcmp(argv[++i], "D") == 0) {
                    reverse = true;
                }
            }
        }
        SortDeque(input_file, output_file, reverse);
    } 
    else if (strcmp(argv[1], "-print") == 0 || strcmp(argv[1], "-P") == 0) {
        const char *input_file = NULL;
        const char *output_file = NULL;
        for (int i = 2; i < argc; i++) {
            if (strcmp(argv[i], "-i") == 0) {
                input_file = argv[++i];
            }
            else if (strncmp(argv[i], "--in=", 5) == 0){
                const char* prefix = "--in=";
                input_file = argv[i] + 5;
            } 
            else if (strncmp(argv[i], "--out=", 6) == 0){
                const char* prefix = "--out=";
                output_file = argv[i] + 6;
            }
            else if (strcmp(argv[i], "-o") == 0) {
                output_file = argv[++i];
            } 
        }
        PrintData(input_file, output_file);

    } else {
        fprintf(stderr, "Unknown command: %s\n", argv[1]);
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}