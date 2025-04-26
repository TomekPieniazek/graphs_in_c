#include <stdio.h>
#include <stdlib.h>

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

void create_one_way_connection(Node *first_node, Node *second_node) {
    if(first_node->connection_count >= first_node->connection_capacity) {
        first_node->connection_capacity*=2;
        first_node->connections = realloc(first_node->connections, sizeof(Node *) * first_node->connection_capacity);
    }

    first_node->connections[first_node->connection_count] = second_node;
    first_node->connection_count+=1;
}

int main(void) {
    Node *first_node = create_node(120);
    Node *second_node = create_node(130);
    create_one_way_connection(first_node, second_node);

    printf("%d", first_node->connections[0]->value);
}