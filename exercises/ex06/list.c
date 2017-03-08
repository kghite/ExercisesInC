/* Example code for Exercises in C.

Based on an example from http://www.learn-c.org/en/Linked_lists

Copyright 2016 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *next;
} Node;


/* Makes a new node structure.
 * 
 * val: value to store in the node.
 * next: pointer to the next node
 *
 * returns: pointer to a new node
 */
Node *make_node(int val, Node *next) {
    Node *node = malloc(sizeof(Node));
    node->val = val;
    node->next = next;
    return node;
}


/* Prints the values in a list.
 * 
 * list: pointer to pointer to Node
 */
void print_list(Node **list) {
    Node *current = *list;

    printf("[ ");
    while (current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("]\n");
}


/* Removes and returns the first element of a list.
 * 
 * list: pointer to pointer to Node
 *
 * returns: int or -1 if the list is empty
 */
int pop(Node **list) {
  // Save the head value
  Node *head = *list;
  int temp = head->val;

  // Check for null
  if (&head->next != NULL) {
    **list = *head->next;
  }
  
  return temp;
}


/* Adds a new element to the beginning of the list.
 * 
 * list: pointer to pointer to Node
 * val: value to add
 */
void push(Node **list, int val) {
    // Get the head value
    Node *head = *list;

    // Create new node with head as next
    Node *new_head = make_node(val, head);

    // Reset list to new head
    *list = new_head;
}


/* Removes the first element with the given value
 * 
 * Frees the removed node.
 *
 * list: pointer to pointer to Node
 * val: value to remove
 *
 * returns: number of nodes removed
 */
// Recursive solution got weird with **list so did iterative 
int remove_by_value(Node **list, int val) {
    Node *head = *list;
    Node *dummy = *list; // Set iterable to the head of the list

    // Base Case 1: null head
    if (dummy == NULL) {
        return 0;
    }
    else if (dummy->val == val) { // found node 
        *list = head->next;
        free(head);
        return 1;
    }
    else {
        while (dummy->next != NULL) {
            if (dummy->next->val == val) {
                Node *delete = dummy->next;
                dummy->next = dummy->next->next;
                free(delete);
            }

            dummy = dummy->next;
        }
    }
}

/* Reverses the elements of the list.
 *
 * Does not allocate or free nodes.
 * 
 * list: pointer to pointer to Node
 */
void reverse(Node **list) {
    Node *prev = NULL;
    Node *curr = *list; // Set current to head
    Node *next;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    *list = prev;
}


int main() {
    Node *head = make_node(1, NULL);
    head->next = make_node(2, NULL);
    head->next->next = make_node(3, NULL);
    head->next->next->next = make_node(4, NULL);

    Node **list = &head;
    print_list(list);

    int retval = pop(list);
    print_list(list);

    push(list, retval+10);
    print_list(list);

    remove_by_value(list, 3);
    print_list(list);

    remove_by_value(list, 7);
    print_list(list);

    reverse(list);
    print_list(list);
}
