#include <stdio.h>
#include <stdlib.h>
#include "race_results.h"

void get_race_results(char * filename, race_ptr results_array[], int total_races, member_node_ptr member,
        boat_handicap_ptr boat_array[], int num_handicap_boats) {
    FILE *file;

    file = fopen(filename, "r");

    if (file != NULL) {
        fscanf(file, "%d", &total_races);
        for (int races = 0; races < total_races; races++) {
            fscanf(file, " %[^\n]", results_array[races].race_date);
            results_array[races].start_time =  time_conversion(file);
            fscanf(file, "%d", &results_array[races].num_boats_competing);

            for (int num_boats = 0; num_boats < results_array[races].num_boats_competing; num_boats++) {
                fscanf(file, "%d", &results_array[races].boat_data[num_boats].ID);
                results_array[races].boat_data[num_boats].time_to_complete_race =
                        time_conversion_boat(file) *
                                find_handicap_value(member, results_array[races].boat_data[num_boats].ID,
                                                    num_handicap_boats, boat_array); /*multiplies the converted time in
            * seconds by the handicap value*/
                results_array[races].boat_data[num_boats].points = 0;
            }
        }
        fclose(file);
    } else {
        printf("Failed to open file\n");
    }
}

//converts the time to int e.g. 14 00 05 becomes 140005
int time_conversion(FILE *file) {
    int hrs;
    int mins;
    int secs;

    fscanf(file, " %d %d %d", &hrs, &mins, &secs);
    return hrs*10000 + mins*100 +secs;
}

//converts the time to seconds for the boats to then be multiplied by the handicap value
int time_conversion_boat(FILE *file) {
    int hrs;
    int mins;
    int secs;

    fscanf(file, " %d %d %d", &hrs, &mins, &secs);
    return hrs*3600 + mins*60 +secs;
}

//prints the values for the races
void print_races(int races, race_ptr results[], member_node_ptr member) {

    for(int race = 0; race < races; race++) {
        printf("Race Date: %s\n", results[race].race_date);
        printf("Race Start Time: %d\n", results[race].start_time);
        printf("Number of Skippers: %d\n", results[race].num_boats_competing);
        for(int boats = 0; boats < results[race].num_boats_competing; boats++) {
            find_skipper_data(member, results[race].boat_data[boats].ID, 1);
            find_skipper_data(member, results[race].boat_data[boats].ID, 2);
            printf("\tPoints Scored: %d\n", results[race].boat_data[boats].points);
        }
        printf("\n");
    }
}

//prints the data for the championship
void print_championship(boat_ptr final_boat_scores[], member_node_ptr member) {
    for (int boat = 0; boat < 3; boat++) {
        find_skipper_data(member, final_boat_scores[boat].ID, 1);
        find_skipper_data(member, final_boat_scores[boat].ID, 2);
        printf("\tPoints Scored: %d\n", final_boat_scores[boat].points);
    }
}

//sorts the races and gives 4, 2 and 1 points to 1st, 2nd and third places respectively to the boats
void sort_and_give_points(race_ptr race_root[], int total_races) {

    for(int race = 0; race < total_races; race++) {
        qsort(race_root[race].boat_data, race_root[race].num_boats_competing,
              sizeof *race_root[race].boat_data, compare_race_times);
    }

    for(int race = 0; race < total_races; race++) {
        double points_awarded = 4;
        for(int boat = 0; boat < MAX_BOAT_NUMBER; boat++) {
            if(points_awarded == 0.5) {
                break;
            }
            race_root[race].boat_data[boat].points = (int) points_awarded;
            points_awarded = points_awarded / 2;
        }
    }
}

//sorts and adds boats to the boat_scores[]
void sort_boats(boat_ptr boat_scores[], race_ptr race_root[], int total_races, int total_boats) {
    int i = 0;
    for (int race = 0; race < total_races; race++) {
        for (int boat = 0; boat < 3; boat++) {
            boat_scores[i] = race_root[race].boat_data[boat];
            i++;
        }
    }
    qsort(boat_scores, total_boats, sizeof(boat_node), compare_id);
}


//gets the boat_scores[] and puts it into final_boat_scores[] in order of points
void sort_points(boat_ptr final_boat_scores[], race_ptr race_root[], member_node_ptr members,
                 int boats, int total_boats, int total_races) {

    boat_ptr boat_scores[total_boats]; //creates a array to store all the boats in


    sort_boats(boat_scores, race_root, total_races, total_boats);

    boat_ptr temp_array[total_boats]; //creates a temporary array to store the boat IDs removing any duplicate IDs
    for (int i = 0; i < total_boats; i++) {
        temp_array[i] = boat_scores[i];
    }
    remove_duplicate_id(temp_array, total_boats);
    for (int k = 0; k < boats; ++k) {
        final_boat_scores[k] = temp_array[k];
    }

    for (int i = 0; i < total_boats; i++) {
        final_boat_scores[i].points = 0;
        for (int j = 0; j < total_boats; j++) {
            //if there exist an struct boat_score[j] with the same ID
            //as the current final_boat_score[i] struct, add its points to the total
            if (final_boat_scores[i].ID == boat_scores[j].ID) {
                final_boat_scores[i].points += boat_scores[j].points;
            }
        }
    }
    qsort(final_boat_scores, total_boats, sizeof *boat_scores, compare_points);
}

//compares the race times of two boat_nodes
int compare_race_times(const void *a, const void *b) {
    boat_node const *pa = a, *pb = b;

    return (pa->time_to_complete_race > pb->time_to_complete_race) -
           (pa->time_to_complete_race < pb->time_to_complete_race);
}

//compares the points of two boat_nodes
int compare_points(const void *a, const void *b) {
    boat_node *pa = (boat_node *)a, *pb = (boat_node *)b;

    return (pb->points - pa->points);
}

//compares the ID's of two boat_nodes
int compare_id(const void *a, const void *b) {
    boat_node const *pa = a, *pb = b;

    return (pb->ID  - pa->ID);
}

//removes the duplicate id's from an array
void remove_duplicate_id(boat_ptr *temp_array, int total_boats) {
    int i, j, k;

    for(i = 0; i < total_boats; i++) {
        for(j = i+1; j < total_boats; j++) {

            if(temp_array[i].ID == temp_array[j].ID) {
                for(k = j; k < total_boats; k++) {
                    temp_array[k] = temp_array[k + 1];
                }
                total_boats--;
                j--;
            }
        }
    }
}