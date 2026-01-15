#ifndef NODE_H
#define NODE_H

typedef struct node
{
    int value;
    struct node *next;
} node;

struct node *add_to_list(struct node *list, int n);

struct node *read_numbers(void);

struct node *search_list(struct node *list, int n);

#endif