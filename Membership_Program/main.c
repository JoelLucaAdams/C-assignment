#include <stdio.h>
#include "membership.h"

int main() {
    member_node_pointer tree_root;
    char file[20]; //filename
    char data_directory[201]; //Directory location of the file

    printf("Please supply the name of the directory containing the membership file: \n");
    scanf("%200s", data_directory);

    printf("Please enter the name of the file you wish to open: \n");
    scanf("%s", file);

    tree_root = add_data(data_directory, file); //adds all the members into the binary search tree

    int what_next;
    int id;
    char boat_class_name[30];
    do {
    printf("\nWhat would you like to do?\n");
    printf("%2d = Membership list, %2d = Search members by ID,\n%2d = Search members by boat class,"
           "%2d = Add new member,\n%2d = Save and exit\n", MEMBERSHIP_LIST, SEARCH_MEMBERS_BY_ID, SEARCH_MEMBERS_BY_BOAT,
           ADD_MEMBER, SAVE_AND_EXIT);
    scanf("%d", &what_next);
    switch(what_next) {
        case MEMBERSHIP_LIST:
            print_data(tree_root); //prints out a list of all the members
            break;
        case SEARCH_MEMBERS_BY_ID:
            printf("Please enter a members ID: ");
            scanf("%d", &id);
            search_members_by_id(tree_root, id); //searches for the member with the matching id in the binary search tree
            break;
        case SEARCH_MEMBERS_BY_BOAT:
            printf("Please enter a boat class name: ");
            scanf("%s", boat_class_name);
            search_members_by_boat(tree_root, boat_class_name); //searches for the member with the matching boat
            break;
        case ADD_MEMBER:
            add_new_member(tree_root); //adds a new member to the binary search tree
            break;
        case SAVE_AND_EXIT:
            printf("Saving...\n");
            save(tree_root, file, data_directory); //saves the binary search tree back to the file
            printf("Exiting...");
            break;
        default:
            printf("Incorrect input. Please try again");
            break;
    }
    } while(what_next != SAVE_AND_EXIT);
}