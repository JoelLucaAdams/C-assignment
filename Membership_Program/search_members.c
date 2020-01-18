#include <string.h>
#include "membership.h"

void search_members_by_boat(member_node_pointer node_ptr, char boat_name[30]) {
    if (node_ptr -> left != NULL ) {
        search_members_by_boat(node_ptr->left, boat_name);
    }
    if(strcmp(node_ptr->boat_class_name, boat_name) == 0) {
        print_node(node_ptr);
    }
    if (node_ptr -> right != NULL ) {
        search_members_by_boat(node_ptr -> right, boat_name);
    }

}

void search_members_by_id(member_node_pointer node_ptr, int id) {
    if (node_ptr -> left != NULL ) {
        search_members_by_id(node_ptr->left, id);
    }
    if(node_ptr->ID == id) {
        print_node(node_ptr);
    }
    if (node_ptr -> right != NULL ) {
        search_members_by_id(node_ptr -> right, id);
    }
}