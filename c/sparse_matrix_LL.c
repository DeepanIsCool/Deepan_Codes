/*
Pseudocode for Sparse Matrix Representation Using Linked Lists

1. Node Structure:
   - Define a node with:
     - value: The non-zero element from the sparse matrix.
     - row_position: Row index of the element.
     - column_position: Column index of the element.
     - next: Pointer to the next node.

2. Create a New Node:
   Function create_new_node(start, non_zero_element, row_index, column_index):
     - Input: Pointer to the head of the list `start`, value of the non-zero element `non_zero_element`,
       and its position (`row_index`, `column_index`).
     - If `start` is NULL (empty list):
       - Dynamically allocate memory for a new node.
       - Set the node's `value`, `row_position`, `column_position`, and `next = NULL`.
       - Update `start` to point to the new node.
     - Else:
       - Traverse to the end of the linked list.
       - Dynamically allocate memory for a new node.
       - Set the node's `value`, `row_position`, `column_position`, and `next = NULL`.
       - Link the new node to the last node in the list.

3. Print Linked List:
   Function PrintList(start):
     - Input: Pointer to the head of the list `start`.
     - Traverse the list and print:
       - `row_position` values of all nodes.
       - `column_position` values of all nodes.
       - `value` of all nodes.

4. Main Function:
   - Define the sparse matrix as a 2D array `sparseMatrix`.
   - Initialize an empty linked list `start = NULL`.
   - For each element `sparseMatrix[i][j]`:
     - If the element is non-zero:
       - Call `create_new_node(&start, sparseMatrix[i][j], i, j)` to add the element to the linked list.
   - Call `PrintList(start)` to display the linked list representation of the sparse matrix.

5. End.
*/

// C program for Sparse Matrix Representation
// using Linked Lists
#include <stdio.h>
#include <stdlib.h>

// Node to represent sparse matrix
struct Node
{
    int value;
    int row_position;
    int column_postion;
    struct Node *next;
};

// Function to create new node
void create_new_node(struct Node **start, int non_zero_element,
                     int row_index, int column_index)
{
    struct Node *temp, *r;
    temp = *start;
    if (temp == NULL)
    {
        // Create new node dynamically
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->value = non_zero_element;
        temp->row_position = row_index;
        temp->column_postion = column_index;
        temp->next = NULL;
        *start = temp;
    }
    else
    {
        while (temp->next != NULL)
            temp = temp->next;

        // Create new node dynamically
        r = (struct Node *)malloc(sizeof(struct Node));
        r->value = non_zero_element;
        r->row_position = row_index;
        r->column_postion = column_index;
        r->next = NULL;
        temp->next = r;
    }
}

// This function prints contents of linked list
// starting from start
void PrintList(struct Node *start)
{
    struct Node *temp, *r, *s;
    temp = r = s = start;

    printf("row_position: ");
    while (temp != NULL)
    {

        printf("%d ", temp->row_position);
        temp = temp->next;
    }
    printf("\n");

    printf("column_postion: ");
    while (r != NULL)
    {
        printf("%d ", r->column_postion);
        r = r->next;
    }
    printf("\n");
    printf("Value: ");
    while (s != NULL)
    {
        printf("%d ", s->value);
        s = s->next;
    }
    printf("\n");
}

// Driver of the program
int main()
{
    // Assume 4x5 sparse matrix
    int sparseMatric[4][5] =
        {
            {0, 0, 3, 0, 4},
            {0, 0, 5, 7, 0},
            {0, 0, 0, 0, 0},
            {0, 2, 6, 0, 0}};

    /* Start with the empty list */
    struct Node *start = NULL;

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 5; j++)

            // Pass only those values which are non - zero
            if (sparseMatric[i][j] != 0)
                create_new_node(&start, sparseMatric[i][j], i, j);

    PrintList(start);

    return 0;
}
