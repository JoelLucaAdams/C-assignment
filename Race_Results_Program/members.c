#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "race_results.h"

member_node_ptr read_node(FILE *filename) {
    int scan_status;
    member_node *temp_member_node;
    temp_member_node = calloc(1, sizeof(member_node));
    scan_status = fscanf(filename, " %[^\n] %[^\n] %d %s %s %[^\n]",
                         temp_member_node -> family_name,
                         temp_member_node -> personal_names,
                         &temp_member_node -> ID,
                         temp_member_node -> email,
                         temp_member_node -> boat_class_name,
                         temp_member_node -> name_or_boat_num);
    if (scan_status == EOF) {
        free(temp_member_node);
        return NULL;
    } else {
        return temp_member_node;
    }
}
//adds a new node to the tree
void add_node(member_node_ptr current, member_node_ptr new) {
    if (strcmp(new -> family_name, current -> family_name) > 0) {
        if (current -> right == NULL) {
            current -> right = new;
        } else {
            add_node(current -> right, new);
        }
    } else {
        if (current -> left == NULL) {
            current -> left = new;
        } else {
            add_node(current -> left, new);
        }
    }
}
//adds data to the tree
member_node_ptr add_data(char *full_filename) {
    FILE *members_filename;
    member_node_ptr tree_root_ptr;
    member_node_ptr temp_node_ptr;


    members_filename = fopen(full_filename, "r");

    if (members_filename != NULL) {
        tree_root_ptr = read_node(members_filename);
        while(1) {
            temp_node_ptr = read_node(members_filename);
            if(temp_node_ptr == NULL) {
                break;
            }
            add_node(tree_root_ptr, temp_node_ptr);
        }
    } else {
        printf("Failed to create the tree\n");
        return NULL;
    }
    fclose(members_filename);
    return tree_root_ptr;
}

//prints the option selected using their id
void find_skipper_data(member_node_ptr member, int id, int option) {
    if (member -> left != NULL) {
        find_skipper_data(member->left, id, option);
    }

    if (member->ID == id && option == 1) {
        printf("\tSkipper Name: %s %s\n", member->personal_names, member->family_name);
        return;
    } else if (member->ID == id && option == 2) {
        printf("\tBoat Name: %s\n", member->name_or_boat_num);
        return;
    }

    if (member -> right != NULL) {
        find_skipper_data(member->right, id, option);
    }
}

//finds the handicap value by searching through the tree and then checking if the id is equal to member id
float find_handicap_value(member_node_ptr member, int id, int num_of_handicap, boat_handicap_ptr *boat_array) {
    if (member -> left != NULL) {
        find_handicap_value(member->left, id, num_of_handicap, boat_array);
    }
    if (member->ID == id) {
        return find_handicap(member->boat_class_name, num_of_handicap, boat_array);
    }
    if (member -> right != NULL) {
        find_handicap_value(member->right, id, num_of_handicap, boat_array);
    }
}

//returns an int of the total number of members in the club
int i = 0;
int find_num_of_members(member_node_ptr member) {
    if (member -> left != NULL) {
        find_num_of_members(member->left);
    }
    i++;
    if (member -> right != NULL) {
        find_num_of_members(member->right);
    }
    return i;
}