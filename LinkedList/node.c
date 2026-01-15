#include "node.h"
#include <stdlib.h>
#include <stdio.h>

struct node *add_to_list(struct node *list, int n)
{
    struct node *new_node;
    // Allocating memory for new_noode based on size of the struct;
    new_node = malloc(sizeof(struct node));
    // if we allocated nothing its a failure
    if (new_node == NULL)
    {
        printf("ERROR: malloc failed in add_to_list\n");
        exit(EXIT_FAILURE);
    }
    // Setting the new nodes value
    new_node->value = n;
    // setting the next value to the current first node.
    new_node->next = list;
    return new_node;
};

struct node *read_numbers(void)
{
    // Created a pointer to a node;
    struct node *first = NULL;
    int n;
    printf("Enter a series of integers (0 to terminate): ");
    // Essentially just continue indefinetly
    for (;;)
    {
        // Capture number
        scanf("%d", &n);
        if (n == 0)
        {
            return first;
        }
        // take the value inputed and create a node with the value of n and put it at front of the list;
        first = add_to_list(first, n);
    }
}

struct node *search_list(struct node *list, int n)
{
    struct node *p;
    for (p = list; p != NULL; p = p->next)
    {
        if (p->value == n)
        {
            return p;
        }
    }
    return NULL;
}