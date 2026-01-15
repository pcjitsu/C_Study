#include <stdlib.h>
#include <stdio.h>
#include "node.h"

struct node *first = NULL;
struct node *new_node;

int main()
{
    // Create first node
    first = read_numbers();

    // Traverse the list
    struct node *current = first;
    printf("Your list: ");
    while (current != NULL)
    {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");

    // Test the search function
    int search_value;
    printf("\nEnter a number to search for: ");
    scanf("%d", &search_value);

    struct node *found = search_list(first, search_value);
    if (found != NULL)
    {
        printf("Found %d in the list!\n", found->value);
    }
    else
    {
        printf("%d not found in the list.\n", search_value);
    }

    // Freeing all nodes when program terminates
    while (first != NULL)
    {
        struct node *temp = first;
        first = first->next;
        free(temp);
    }

    return 0;
}

/*
 * LINKED LIST EXAMPLE WALKTHROUGH
 * ================================
 *
 * Example: User enters `5 3 8 0` in read_numbers()
 *
 * INITIAL STATE:
 * -------------
 * first = NULL
 * (The list is empty)
 *
 *
 * STEP 1: User enters `5`
 * -----------------------
 * In read_numbers():
 *   - scanf("%d", &n) → n = 5
 *   - n != 0, so we call: first = add_to_list(first, 5)
 *
 * Inside add_to_list(NULL, 5):
 *   1. Allocate memory for new_node:
 *      new_node → [value: ?, next: ?]  (memory allocated but uninitialized)
 *
 *   2. Set the value:
 *      new_node → [value: 5, next: ?]
 *
 *   3. Set next to point to the current list (which is NULL):
 *      new_node → [value: 5, next: NULL]
 *
 *   4. Return new_node
 *
 * Back in read_numbers():
 *   first → [value: 5, next: NULL]
 *
 *
 * STEP 2: User enters `3`
 * -----------------------
 * In read_numbers():
 *   - scanf("%d", &n) → n = 3
 *   - n != 0, so we call: first = add_to_list(first, 3)
 *
 * Inside add_to_list(first, 3):
 *   - Remember, first currently points to the node with value 5
 *
 *   1. Allocate memory for new_node:
 *      new_node → [value: ?, next: ?]
 *
 *      (existing list is still there)
 *      first → [value: 5, next: NULL]
 *
 *   2. Set the value:
 *      new_node → [value: 3, next: ?]
 *
 *      first → [value: 5, next: NULL]
 *
 *   3. Set next to point to the current list head (the node with 5):
 *      new_node → [value: 3, next: •]
 *                             ↓
 *                 first → [value: 5, next: NULL]
 *
 *   4. Return new_node
 *
 * Back in read_numbers():
 *   first → [value: 3, next: •] → [value: 5, next: NULL]
 *
 *
 * STEP 3: User enters `8`
 * -----------------------
 * Inside add_to_list(first, 8):
 *
 *   1. Allocate and set up new_node:
 *      new_node → [value: 8, next: ?]
 *
 *   2. Point it to the current list:
 *      new_node → [value: 8, next: •] → [value: 3, next: •] → [value: 5, next: NULL]
 *
 * Result:
 *   first → [value: 8, next: •] → [value: 3, next: •] → [value: 5, next: NULL]
 *
 *
 * STEP 4: User enters `0`
 * -----------------------
 * In read_numbers():
 *   - scanf("%d", &n) → n = 0
 *   - n == 0, so we hit the return statement
 *   - Return first
 *
 *
 * FINAL LIST STRUCTURE:
 * ---------------------
 * first → [8] → [3] → [5] → NULL
 *
 * Notice: The list is in REVERSE ORDER from how the user entered the numbers!
 * This is because we always add to the FRONT of the list.
 *
 *
 * MEMORY LAYOUT:
 * --------------
 * Memory Address    Content
 * 0x1000           [value: 8, next: 0x2000]  ← first points here
 * 0x2000           [value: 3, next: 0x3000]
 * 0x3000           [value: 5, next: NULL]
 *
 * Each arrow (→) is just a memory address stored in the 'next' field.
 *
 *
 * TRAVERSING THE LIST:
 * --------------------
 * To print this list:
 *
 *   struct node *current = first;  // Start at the head
 *   while (current != NULL) {
 *       printf("%d ", current->value);  // Print: 8, then 3, then 5
 *       current = current->next;        // Move to next node
 *   }
 *   // Output: 8 3 5
 *
 *
 * KEY INSIGHT:
 * ------------
 * Each new node gets inserted at the FRONT, which is why the order reverses.
 * This is called a "stack" behavior: Last In, First Out (LIFO).
 */