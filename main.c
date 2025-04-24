#include <stdio.h>
#include <stdlib.h>

struct Connection;

typedef struct Node {
    int id;
    struct Connection **connections;
    int connection_count;
    int connection_capacity;
} Node;

typedef struct Connection {
    Node *init_node;
    Node *connected_to_node;
    int connection_value;
} Connection;

Node* initialize_node() {
    Node *ptr = (Node*) malloc(sizeof(Node));
    ptr->connection_capacity = 10;
    ptr->connections = (Connection**) malloc(sizeof(Connection*) * ptr->connection_capacity);
    ptr->connection_count = 0;
    ptr->id = 0;

    return ptr;
}

Node* add_to_graph(int value, int *connection_id[], Node *graph_pointer) {
    Node *init_node = graph_pointer;
    Node *new_node = init_node();


    init_node->connection_count+=1;
    init_node->connections = 

    free(init_node);
    return init_node;
}
