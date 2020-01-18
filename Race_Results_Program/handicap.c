#include <stdio.h>
#include <string.h>
#include "race_results.h"

//loads in the file for the handicap data
void get_handicap(char * filename, boat_handicap_ptr boat_type_array[]) {
    int scan_status = 0;

    FILE *file;
    int total_boat_types;
    file = fopen(filename, "r");

    if (file != NULL) {
        fscanf(file, "%d", &total_boat_types);
        for (int boat_type = 0; boat_type < total_boat_types; boat_type++) {
            fscanf(file, " %s", boat_type_array[boat_type].class_name);
            scan_status = fscanf(file, "%f", &boat_type_array[boat_type].handicap);
            if (scan_status == EOF) {
                printf("Error reading in data\n");
                break;
            }
        }
        fclose(file);
    } else {
        printf("Failed to open file\n");
    }
}

//returns a float of the handicap value by taking a char * value of the boat class name
float find_handicap(char *class_name, int num_of_handicap, boat_handicap_ptr boat_array[]) {
    int boat_num;
    for (boat_num = 0; boat_num < num_of_handicap; boat_num++) {
        if (strcmp(class_name, boat_array[boat_num].class_name) == 0) {
            return boat_array[boat_num].handicap;
        }
    }
}