#include <stdio.h>
#include <string.h>
#include "race_results.h"

int main() {
    member_node_ptr tree_root;
    FILE *fp;
    int total_races;
    int total_boats;
    int total_boat_types;
    int final_total_boats;
    char file1[20];
    char file2[20];
    char file3[20];
    char data_directory[201]; //Directory location of the files

    printf("Please supply the name of the directory containing the files: \n");
    scanf("%200s", data_directory);

    printf("Please enter the name of the members file you wish to open: \n");
    scanf("%s", file1);

    /*This section adds the file path to the filename*/
    char full_filename[strlen(data_directory) + strlen(file1) + 1];
    strcpy(full_filename, data_directory);
    strcat(full_filename, file1);

    tree_root = add_data(full_filename); //reads data in to store in the tree

    printf("Please enter the name of the race file you wish to open: \n");
    scanf("%s", file2);

    /*This section adds the file path to the filename*/
    char race_file[strlen(data_directory) + strlen(file2) + 1];
    strcpy(race_file, data_directory);
    strcat(race_file, file2);

    fp = fopen(race_file, "r");
    fscanf(fp, "%d", &total_races); //Gets the total number of races
    race_ptr race_root[total_races];
    total_boats = total_races * 3;

    printf("Please enter the name of the handicap file you wish to open: \n");
    scanf("%s", file3);

    /*This section adds the file path to the filename*/
    char handicap_file[strlen(data_directory) + strlen(file3) + 1];
    strcpy(handicap_file, data_directory);
    strcat(handicap_file, file3);

    fp = fopen(handicap_file, "r");
    fscanf(fp, "%d", &total_boat_types);
    boat_handicap_ptr boat_handicap_root[total_boat_types];
    get_handicap(handicap_file, boat_handicap_root); //reads in data to the handicap array

    get_race_results(race_file, race_root, total_races, tree_root, boat_handicap_root, total_boat_types);
    sort_and_give_points(race_root, total_races); //orders the boats in each race and gives points
    final_total_boats = find_num_of_members(tree_root);
    boat_ptr final_boat_scores[final_total_boats]; //creates array to store the top boat winners

    sort_points(final_boat_scores, race_root, tree_root, final_total_boats, total_boats, total_races);

    int what_next;
    do {
        printf("\nWhat would you like to do?\n");
        printf("%2d = Print the races, %2d = print the championship results,%2d = Exit\n",
                PRINT_RACES, PRINT_CHAMPIONSHIP, EXIT);
        scanf("%d", &what_next);
        switch(what_next) {
            case PRINT_RACES:
                print_races(total_races, race_root, tree_root);
                break;
            case PRINT_CHAMPIONSHIP:
                print_championship(final_boat_scores, tree_root);
                break;
            case EXIT:
                printf("Exiting...");
                break;

            default:
                printf("Incorrect input. Please try again");
                break;
        }
    } while(what_next != EXIT);
}