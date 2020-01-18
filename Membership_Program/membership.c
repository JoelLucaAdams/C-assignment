#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "membership.h"

member_node_pointer read_node(FILE *filename) {
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

void add_node(member_node_pointer current, member_node_pointer new) {
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

member_node_pointer add_data(char *directory, char *filename) {
    FILE *members_filename;
    member_node_pointer tree_root_ptr;
    member_node_pointer temp_node_ptr;

    char full_filename[strlen(directory) + strlen(filename) + 1];
    strcpy(full_filename, directory);
    strcat(full_filename, filename);

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

void add_new_member(member_node_pointer tree_root_ptr) {
    member_node_pointer new_node = calloc(1, sizeof(member_node));
    printf("Enter the members family name: ");
    scanf("%s", new_node->family_name);
    printf("Enter the members name(s): ");
    fflush(stdin);
    scanf("%[^\n]", new_node->personal_names);
    printf("Enter the members ID: ");
    scanf("%d", &new_node->ID);
    printf("Enter the members email: ");
    scanf("%s", new_node->email);
    printf("Enter the members boat class: ");
    scanf("%s", new_node->boat_class_name);
    printf("Enter the members boat name or number: ");
    fflush(stdin);
    scanf("%[^\n]", new_node->name_or_boat_num);
    add_node(tree_root_ptr, new_node);
}

void save(member_node_pointer tree_root, char *filename, char *directory) {
    FILE *fp;

    char full_filename[strlen(directory) + strlen(filename) + 1];
    strcpy(full_filename, directory);
    strcat(full_filename, filename);

    fp = fopen(full_filename, "w");

    if (fp == NULL) {
        printf("Error saving to file");
        exit(1);
    }
    print_to_file(tree_root, fp);
    fclose(fp);
}

void print_to_file(member_node_pointer tree_root, FILE *fp) {
    if (tree_root -> left != NULL) {
        print_to_file(tree_root->left, fp);
    }

    fprintf(fp, "%s\n", tree_root->family_name);
    fprintf(fp, "%s\n", tree_root->personal_names);
    fprintf(fp, "%d\n", tree_root->ID);
    fprintf(fp, "%s\n", tree_root->email);
    fprintf(fp, "%s\n", tree_root->boat_class_name);
    fprintf(fp, "%s\n", tree_root->name_or_boat_num);

    if (tree_root -> right != NULL) {
        print_to_file(tree_root -> right, fp);
    }
}