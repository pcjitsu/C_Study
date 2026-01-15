#include <stdlib.h>
#include <stdio.h>
#include "node.h"

struct node *first = NULL;
struct node *new_node;

int main()
{
    // allocating memory based on size of deferenced struct
    new_node = malloc(sizeof(*new_node));
    printf("Inset a number: ");
    // use right arrow selection to input value into the node
    scanf("&d", &new_node->value);

    // pushes the next to null
    new_node->next = first;
    // front of the line is the new node created
    first = new_node;

    free(new_node);

    return 0;
}