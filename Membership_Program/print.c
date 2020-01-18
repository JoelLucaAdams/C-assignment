#include "membership.h"

void print_data(member_node_pointer node_ptr) {
    if (node_ptr -> left != NULL) {
        print_data(node_ptr -> left);
    }
    print_node(node_ptr);
    if(node_ptr -> right != NULL) {
        print_data(node_ptr -> right);
    }
}

void print_node(member_node_pointer node_ptr) {
    printf("\nFamily Name: %s\nPersonal Name(s): %s\nID: %d\nEmail: %s\nBoat Class Name: %s\n"
           "Name or Boat Number: %s\n", node_ptr -> family_name, node_ptr -> personal_names, node_ptr -> ID,
           node_ptr -> email, node_ptr -> boat_class_name, node_ptr -> name_or_boat_num);
}