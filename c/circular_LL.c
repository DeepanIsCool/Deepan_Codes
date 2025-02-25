/*
Pseudocode for Circular Linked List Operations

1. Data Structure:
   - Define a node structure with:
     - data: Stores the integer value of the node.
     - link: Pointer to the next node.

2. Insert at the End:
   Function InsertAtEnd(data):
     - Create a new node with the given data.
     - If the list is empty (head == NULL):
       - Set head = newNode, and make newNode.link = head.
     - Else:
       - Traverse the list to the last node (node with link pointing to head).
       - Set lastNode.link = newNode, and newNode.link = head.

3. Insert at the Beginning:
   Function InsertAtBeginning(data):
     - Create a new node with the given data.
     - If the list is empty (head == NULL):
       - Set head = newNode, and make newNode.link = head.
     - Else:
       - Traverse the list to the last node.
       - Set lastNode.link = newNode, newNode.link = head, and head = newNode.

4. Insert at a Specific Position:
   Function InsertAtPosition(data, pos):
     - If pos == 1, call InsertAtBeginning(data).
     - Otherwise:
       - Traverse the list to the (pos - 1)th node.
       - If position is out of range, print "Position out of range" and exit.
       - Create a new node and set newNode.link = currentNode.link, currentNode.link = newNode.

5. Delete from the Beginning:
   Function DeleteAtBeginning():
     - If the list is empty (head == NULL):
       - Print "List is empty, nothing to delete" and exit.
     - If there is only one node:
       - Free the node and set head = NULL.
     - Else:
       - Traverse the list to the last node.
       - Set lastNode.link = head.link, free head, and update head = head.link.

6. Delete from the End:
   Function DeleteAtEnd():
     - If the list is empty (head == NULL):
       - Print "List is empty, nothing to delete" and exit.
     - If there is only one node:
       - Free the node and set head = NULL.
     - Else:
       - Traverse to the second-last node.
       - Free the last node and set secondLastNode.link = head.

7. Display Circular Linked List:
   Function DisplayL2R():
     - If the list is empty (head == NULL):
       - Print "List is empty" and exit.
     - Start from head and traverse until the list loops back to head.
     - Print each node's data followed by "->", and end with "(HEAD)".

8. Main Menu:
   - Provide options for:
     1. Insert at the beginning.
     2. Insert at the end.
     3. Insert at any position.
     4. Display the list.
     5. Delete from the beginning.
     6. Delete from the end.
     0. Exit.
   - Execute the selected operation and repeat until the user chooses to exit.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
} N;

N *head = NULL;

// Insert at the end of the circular linked list
void InsertAtEnd(int data)
{
    N *newNode = (N *)malloc(sizeof(N));
    newNode->data = data;
    if (head == NULL)
    {
        head = newNode;
        newNode->link = head;
    }
    else
    {
        N *temp = head;
        while (temp->link != head)
        {
            temp = temp->link;
        }
        temp->link = newNode;
        newNode->link = head;
    }
}

// Insert at the beginning of the circular linked list
void InsertAtBeginning(int data)
{
    N *newNode = (N *)malloc(sizeof(N));
    newNode->data = data;
    if (head == NULL)
    {
        head = newNode;
        newNode->link = head;
    }
    else
    {
        N *temp = head;
        while (temp->link != head)
        {
            temp = temp->link;
        }
        temp->link = newNode;
        newNode->link = head;
        head = newNode;
    }
}

// Insert at a specific position in the circular linked list
void InsertAtPosition(int data, int pos)
{
    N *newNode = (N *)malloc(sizeof(N));
    newNode->data = data;

    if (pos == 1)
    {
        InsertAtBeginning(data);
        return;
    }

    N *temp = head;
    for (int i = 1; i < pos - 1 && temp->link != head; i++)
    {
        temp = temp->link;
    }
    if (temp->link == head && pos != 1)
    {
        printf("Position out of range\n");
        free(newNode);
        return;
    }

    newNode->link = temp->link;
    temp->link = newNode;
}

// Delete from the beginning of the circular linked list
void DeleteAtBeginning()
{
    if (head == NULL)
    {
        printf("List is empty, nothing to delete.\n");
        return;
    }
    if (head->link == head)
    {
        free(head);
        head = NULL;
    }
    else
    {
        N *temp = head;
        while (temp->link != head)
        {
            temp = temp->link;
        }
        N *toDelete = head;
        head = head->link;
        temp->link = head;
        free(toDelete);
    }
    printf("Node deleted from the beginning.\n");
}

// Delete from the end of the circular linked list
void DeleteAtEnd()
{
    if (head == NULL)
    {
        printf("List is empty, nothing to delete.\n");
        return;
    }
    if (head->link == head)
    {
        free(head);
        head = NULL;
    }
    else
    {
        N *temp = head;
        while (temp->link->link != head)
        {
            temp = temp->link;
        }
        free(temp->link);
        temp->link = head;
    }
    printf("Node deleted from the end.\n");
}

// Display circular linked list from left to right
void DisplayL2R()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    N *temp = head;
    do
    {
        printf("%d -> ", temp->data);
        temp = temp->link;
    } while (temp != head);
    printf("(HEAD)\n");
}

// Additional functions that manipulate the list will also need adjustments for the circular nature, ensuring no operations break due to the last node pointing back to the head.

int main()
{
    int choice, data, pos;

    while (1)
    {
        printf("\nCircular Linked List Operations\n");
        printf("0. Exit\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Insert at any position\n");
        printf("4. Display list\n");
        printf("5. Delete from the beginning\n");
        printf("6. Delete from the end\n");
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
            printf("Circular Linked List: ");
            DisplayL2R();
            break;

        case 5:
            printf("Deleting node from the beginning...\n");
            DeleteAtBeginning();
            DisplayL2R();
            break;

        case 6:
            printf("Deleting node from the end...\n");
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