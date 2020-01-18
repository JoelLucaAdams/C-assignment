#ifndef RACE
#define RACE
#include <stdio.h>

#define MAX_BOAT_NUMBER 10 //change this value depending oon the number of boats entered

#define PRINT_RACES 1
#define PRINT_CHAMPIONSHIP 2
#define EXIT 0

typedef struct member {
    char family_name[20];
    char personal_names[80];
    int ID;
    char email[50];
    char boat_class_name[30];
    char name_or_boat_num[30];

    struct member * left; /* links to members with alphabetically higher or same family name */
    struct member * right; /* links to members with alphabetically lower family name */
} member_node;

typedef member_node * member_node_ptr;
member_node_ptr add_data(char *full_filename);
void find_skipper_data(member_node_ptr member, int id, int option);
int find_num_of_members(member_node_ptr member);



typedef struct boat_handicap {
    char class_name[30];
    float handicap;
} boat_handicap_node;
typedef boat_handicap_node boat_handicap_ptr;
void get_handicap(char * filename, struct boat_handicap boat_type_array[]);
float find_handicap(char *class_name, int num_of_handicap, boat_handicap_ptr boat_array[]);
int compare_race_times(const void *a, const void *b);
int compare_points(const void *a, const void *b);
int compare_id(const void *a, const void *b);

typedef struct boat_data {
    int ID;
    int time_to_complete_race;
    int points;
} boat_node;
typedef boat_node boat_ptr;
typedef struct race_result {
    char race_date[80];
    int start_time;
    int num_boats_competing;
    struct boat_data boat_data[MAX_BOAT_NUMBER];
} race_node;
typedef race_node race_ptr;
int time_conversion(FILE *file);
int time_conversion_boat(FILE *file);
void print_races(int races, race_ptr results[], member_node_ptr member);
void remove_duplicate_id(boat_ptr *temp_array, int total_boats);


//These need to be defined here as they use typedef from multiple structs above
float find_handicap_value(member_node_ptr member, int id, int num_of_handicap, boat_handicap_ptr *boat_array);
void get_race_results(char * filename, race_ptr results_array[], int total_races, member_node_ptr member,
                      boat_handicap_ptr boat_array[], int num_handicap_boats);
void sort_and_give_points(race_ptr race_root[], int total_races);
void sort_points(boat_ptr final_boat_scores[], race_ptr race_root[], member_node_ptr members,
                 int boats, int total_boats, int total_races);
void sort_boats(boat_ptr boat_scores[], race_ptr race_root[], int total_boats_in_race, int total_boats);
void print_championship(boat_ptr final_boat_scores[], member_node_ptr member);

#endif