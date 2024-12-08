/*
Pseudocode for Doubly Linked List Operations

1. Data Structure:
   - Define a node structure with:
     - data: Stores the value of the node.
     - prev: Pointer to the previous node.
     - next: Pointer to the next node.

2. Insert at the End:
   Function InsertAtEnd(data):
     - Create a new node with the given data.
     - If the list is empty (head == NULL):
       - Set head = newNode.
     - Else:
       - Traverse to the last node (node with next == NULL).
       - Set lastNode.next = newNode and newNode.prev = lastNode.

3. Insert at the Beginning:
   Function InsertAtBeginning(data):
     - Create a new node with the given data.
     - Set newNode.next = head and newNode.prev = NULL.
     - If the list is not empty:
       - Set head.prev = newNode.
     - Update head = newNode.

4. Insert at a Specific Position:
   Function InsertAtPosition(data, pos):
     - If pos == 1, call InsertAtBeginning(data).
     - Otherwise:
       - Traverse to the (pos - 1)th node.
       - If position is out of range, print "Position out of range" and exit.
       - Set newNode.next = currentNode.next and newNode.prev = currentNode.
       - If currentNode.next is not NULL:
         - Set currentNode.next.prev = newNode.
       - Set currentNode.next = newNode.

5. Delete from the Beginning:
   Function DeleteAtBeginning():
     - If the list is empty (head == NULL), print "List is empty" and exit.
     - Save head in a temporary pointer.
     - Update head = head.next.
     - If head is not NULL, set head.prev = NULL.
     - Free the temporary pointer.

6. Delete from the End:
   Function DeleteAtEnd():
     - If the list is empty (head == NULL), print "List is empty" and exit.
     - Traverse to the last node.
     - If lastNode.prev is not NULL:
       - Set lastNode.prev.next = NULL.
     - Otherwise:
       - Update head = NULL (list becomes empty).
     - Free the last node.

7. Display List from Left to Right:
   Function DisplayL2R():
     - Traverse the list from head to NULL.
     - Print each node's data followed by "->".

8. Display List from Right to Left:
   Function DisplayR2L():
     - Traverse to the last node.
     - Traverse back from the last node to head using the prev pointer.
     - Print each node's data followed by "->".

9. Main Menu:
   - Provide options for:
     1. Insert at the beginning.
     2. Insert at the end.
     3. Insert at any position.
     4. Display list from left to right.
     5. Display list from right to left.
     6. Delete from the beginning.
     7. Delete from the end.
     0. Exit.
   - Execute the selected operation and repeat until the user chooses to exit.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *prev; // Pointer to the previous node
    struct node *next; // Pointer to the next node
} N;

N *head = NULL;

// Insert at the end of the doubly linked list
void InsertAtEnd(int data)
{
    N *newNode = (N *)malloc(sizeof(N));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        N *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// Insert at the beginning of the doubly linked list
void InsertAtBeginning(int data)
{
    N *newNode = (N *)malloc(sizeof(N));
    newNode->data = data;
    newNode->next = head;
    newNode->prev = NULL;

    if (head != NULL)
    {
        head->prev = newNode;
    }
    head = newNode;
}

// Insert at a specific position in the doubly linked list
void InsertAtPosition(int data, int pos)
{
    if (pos == 1)
    {
        InsertAtBeginning(data);
        return;
    }

    N *newNode = (N *)malloc(sizeof(N));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    N *temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Position out of range\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL)
    {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}

// Delete from the beginning of the doubly linked list
void DeleteAtBeginning()
{
    if (head == NULL)
    {
        printf("List is empty, nothing to delete.\n");
        return;
    }

    N *temp = head;
    head = head->next;

    if (head != NULL)
    {
        head->prev = NULL;
    }
    free(temp);
    printf("Node deleted from the beginning.\n");
}

// Delete from the end of the doubly linked list
void DeleteAtEnd()
{
    if (head == NULL)
    {
        printf("List is empty, nothing to delete.\n");
        return;
    }

    N *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    if (temp->prev != NULL)
    {
        temp->prev->next = NULL;
    }
    else
    {
        head = NULL; // List becomes empty
    }
    free(temp);
    printf("Node deleted from the end.\n");
}

// Display the doubly linked list from left to right
void DisplayL2R()
{
    N *temp = head;
    printf("List (Left to Right): ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Display the doubly linked list from right to left
void DisplayR2L()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    N *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    printf("List (Right to Left): ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

int main()
{
    int choice, data, pos;

    while (1)
    {
        printf("\nDoubly Linked List Operations\n");
        printf("0. Exit\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Insert at any position\n");
        printf("4. Display from left to right\n");
        printf("5. Display from right to left\n");
        printf("6. Delete from the beginning\n");
        printf("7. Delete from the end\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
            printf("Exiting...\n");
            exit(0);

        case 1:
            printf("Enter the data to insert at the beginning: ");
            scanf("%d", &data);
            InsertAtBeginning(data);
            printf("Data inserted at the beginning.\n");
            DisplayL2R();
            break;

        case 2:
            printf("Enter the data to insert at the end: ");
            scanf("%d", &data);
            InsertAtEnd(data);
            printf("Data inserted at the end.\n");
            DisplayL2R();
            break;

        case 3:
            printf("Enter the position to insert the data: ");
            scanf("%d", &pos);
            printf("Enter the data to insert: ");
            scanf("%d", &data);
            InsertAtPosition(data, pos);
            printf("Data inserted at position %d.\n", pos);
            DisplayL2R();
            break;

        case 4:
            DisplayL2R();
            break;

        case 5:
            DisplayR2L();
            break;

        case 6:
            DeleteAtBeginning();
            DisplayL2R();
            break;

        case 7:
            DeleteAtEnd();
            DisplayL2R();
            break;

        default:
            printf("Invalid choice! Please try again.\n");
            break;
        }
    }

    return 0;
}