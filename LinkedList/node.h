#ifndef NODE_H
#define NODE_H

typedef struct node
{
    int value;
    struct node *next;
};

struct node *add_to_list(struct node *list, int n);

struct node *read_numbers(void);

#endif