#ifndef MEMBERS
#define MEMBERS
#include <stdio.h>

#define MEMBERSHIP_LIST 1
#define SEARCH_MEMBERS_BY_ID 2
#define SEARCH_MEMBERS_BY_BOAT 3
#define ADD_MEMBER 4
#define SAVE_AND_EXIT 0

typedef struct member{
    char family_name[20];
    char personal_names[80];
    int ID;
    char email[50];
    char boat_class_name[30];
    char name_or_boat_num[30];

    struct member * left; /* links to members with alphabetically higher or same family name */
    struct member * right; /* links to members with alphabetically lower family name */
} member_node;

typedef member_node * member_node_pointer; /* pointer to the member struct */

member_node_pointer add_data(char *directory, char *filename); /*Adds a new node into a struct and returns a
 * node pointer to it so that it can get added to the tree */
void add_new_member(member_node_pointer tree_root_ptr); /* Used to add a new member to the tree */

void print_data(member_node_pointer node_ptr); /* Prints data of whole tree */
void print_node(member_node_pointer node_ptr); /* Prints data of single specified node */
void print_to_file(member_node_pointer tree_root, FILE *fp); /* Puts data back into file */

void search_members_by_id(member_node_pointer node_ptr, int id); /* Traverses tree until it finds the members ID
 * and prints it */
void search_members_by_boat(member_node_pointer node_ptr, char boat_name[30]); /* Traverses tree until it finds the
 * members boat class names */

void save(member_node_pointer tree_root, char *filename, char *directory); /* Takes the file and directory, checks
 * the file exists and then saves the data to it */

#endif