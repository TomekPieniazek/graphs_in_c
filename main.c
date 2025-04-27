#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

struct Connection;

typedef struct Node {
    int value;
    int connection_count;
    int connection_capacity;
    struct Node **connections;
} Node;

Node *create_node(int val) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->value = val;
    new_node->connection_count = 0;
    new_node->connection_capacity = 2;
    new_node->connections = malloc(sizeof(Node *) * new_node->connection_capacity);
    return new_node;
}

bool check_for_existence_of_connection(Node *ptr_to_add, Node *add_to) {
    for(int i=0; i<add_to->connection_count; i++) {
        if(add_to->connections[i] == ptr_to_add) {
            return true;
        }
    }
    return false;
}

void create_one_way_connection(Node *first_node, Node *second_node) {
    if(first_node->connection_count >= first_node->connection_capacity) {
        first_node->connection_capacity*=2;
        first_node->connections = realloc(first_node->connections, sizeof(Node *) * first_node->connection_capacity);
    }

    if(check_for_existence_of_connection(second_node, first_node) == false) {
        first_node->connections[first_node->connection_count] = second_node;
        first_node->connection_count+=1;   
    } else {
        printf("Connection already exist\n");
    }
}

void create_two_way_connection(Node *first_node, Node *second_node) {
    create_one_way_connection(first_node, second_node);
    create_one_way_connection(second_node, first_node);
}

int main(void) {
    Node *first_node = create_node(120);
    Node *second_node = create_node(130);
    Node *third_node = create_node(1230);
    Node *fourth_node = create_node(198049);
    create_one_way_connection(first_node, second_node);
    create_two_way_connection(first_node, third_node);
    create_one_way_connection(third_node, fourth_node);

    printf("%d\n", first_node->connections[0]->value);
    printf("%d\n", third_node->connections[0]->value);
    printf("%d\n", first_node->connections[1]->value);
}