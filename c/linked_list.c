/*
Detailed Pseudocode for Linked List Operations:

1. Define Node Structure:
   - Each node contains:
     - `data`: Integer data of the node.
     - `link`: Pointer to the next node.

2. Core Linked List Operations:

   a. **Insert At End**:
      - Input: Data value to insert.
      - Create a new node with the given `data`.
      - If the list is empty:
         - Set the `head` to the new node.
      - Else:
         - Traverse the list to the last node.
         - Update the last node's `link` to point to the new node.
      - End.

   b. **Insert At Beginning**:
      - Input: Data value to insert.
      - Create a new node with the given `data`.
      - Set the new node's `link` to the current `head`.
      - Update the `head` to the new node.
      - End.

   c. **Insert At Position**:
      - Input: Data value and position `pos`.
      - Create a new node with the given `data`.
      - If `pos == 1`:
         - Insert at the beginning using the **Insert At Beginning** method.
      - Else:
         - Traverse to the node at `pos - 1`.
         - If position is invalid (node at `pos - 1` is NULL), print an error.
         - Otherwise:
            - Set the new node's `link` to the `link` of the node at `pos - 1`.
            - Update the node at `pos - 1` to point to the new node.
      - End.

   d. **Delete At Beginning**:
      - Check if the list is empty. If true, print "List is empty".
      - Otherwise:
         - Save the `head` node in a temporary variable.
         - Update `head` to point to the second node.
         - Free the memory of the old head node.
      - End.

   e. **Delete At End**:
      - Check if the list is empty. If true, print "List is empty".
      - If the list has one node:
         - Free the `head` and set `head` to NULL.
      - Else:
         - Traverse to the second-last node.
         - Free the memory of the last node and set the second-last node's `link` to NULL.
      - End.

   f. **Delete At Position**:
      - Input: Position `pos`.
      - If `pos == 1`, delete the first node using **Delete At Beginning**.
      - Else:
         - Traverse to the node at `pos - 1`.
         - If position is invalid, print "Position out of range".
         - Otherwise:
            - Update the node at `pos - 1` to skip the target node.
            - Free the memory of the target node.
      - End.

   g. **Display From Left to Right**:
      - Input: `head` of the list.
      - Traverse the list from the `head` to NULL, printing each node's `data`.

   h. **Display From Right to Left (Recursive)**:
      - Input: `head` of the list.
      - If the list is not empty:
         - Recursively call the function on the next node.
         - Print the `data` of the current node.

   i. **Insert in Sorted Order**:
      - Input: Data value to insert.
      - Create a new node with the given `data`.
      - If the list is empty or `head->data >= data`:
         - Insert at the beginning using **Insert At Beginning**.
      - Else:
         - Traverse to the node where `data` can be inserted in sorted order.
         - Insert the new node at the correct position.
      - End.

   j. **Linear Search**:
      - Input: Data value to search.
      - Traverse the list, comparing each node's `data` with the target value.
      - If found, return the position (1-based index).
      - If not found, return -1.

   k. **Bubble Sort**:
      - Input: `head` of the list.
      - Perform nested traversal:
         - Compare adjacent nodes.
         - Swap their `data` if out of order.
      - Repeat until the list is sorted.
      - End.

   l. **Count Nodes**:
      - Input: `head` of the list.
      - Traverse the list, incrementing a counter for each node.
      - Return the count.

   m. **Reverse Linked List**:
      - Input: `head` of the list.
      - Use three pointers (`prev`, `current`, `next`) to reverse the links.
      - Update `head` to the last node.
      - End.

   n. **Delete All Occurrences of a Value**:
      - Input: Data value to delete.
      - Traverse the list:
         - If the current node matches the value:
            - Update the previous node's `link` to skip the current node.
            - Free the current node.
         - Else:
            - Move to the next node.
      - End.

3. MAIN Program:
   - Display a menu for the user to choose operations.
   - Take user input for the choice and required parameters.
   - Call the corresponding function for each choice.
   - Exit the program when the user selects "Exit".
   - Ensure memory cleanup before exiting.

4. End.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
} N;

N *head = NULL;

void InsertAtEnd(int data)
{
    N *newNode = (N *)malloc(sizeof(N));
    newNode->data = data;
    newNode->link = NULL;
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        N *temp = head;
        while (temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = newNode;
    }
}

void InsertAtBeginning(int data)
{
    N *newNode = (N *)malloc(sizeof(N));
    newNode->data = data;
    newNode->link = head;
    head = newNode;
}

void InsertAtPosition(int data, int pos)
{
    N *newNode = (N *)malloc(sizeof(N));
    newNode->data = data;
    if (pos == 1)
    {
        newNode->link = head;
        head = newNode;
    }
    else
    {
        N *temp = head;
        for (int i = 1; i < pos - 1 && temp != NULL; i++)
        {
            temp = temp->link;
        }
        if (temp == NULL)
        {
            printf("Position out of range\n");
            free(newNode);
        }
        else
        {
            newNode->link = temp->link;
            temp->link = newNode;
        }
    }
}

void DeleteAtBeginning()
{
    if (head == NULL)
    {
        printf("List is empty, nothing to delete.\n");
        return;
    }
    N *temp = head;
    head = head->link;
    free(temp);
    printf("Node deleted from the beginning.\n");
}

void DeleteAtEnd()
{
    if (head == NULL)
    {
        printf("List is empty, nothing to delete.\n");
        return;
    }
    if (head->link == NULL)
    {
        free(head);
        head = NULL;
    }
    else
    {
        N *temp = head;
        while (temp->link->link != NULL)
        {
            temp = temp->link;
        }
        free(temp->link);
        temp->link = NULL;
    }
    printf("Node deleted from the end.\n");
}

void DeleteAtPosition(int pos)
{
    if (head == NULL)
    {
        printf("List is empty, nothing to delete.\n");
        return;
    }
    if (pos == 1)
    {
        N *temp = head;
        head = head->link;
        free(temp);
        printf("Node deleted from position %d.\n", pos);
    }
    else
    {
        N *temp = head;
        N *prev = NULL;
        for (int i = 1; i < pos && temp != NULL; i++) // i=5
        {

            prev = temp;       // prev=5
            temp = temp->link; // temp=6
        }
        if (temp == NULL)
        {
            printf("Position out of range\n");
        }
        else
        {
            prev->link = temp->link;
            free(temp);
            printf("Node deleted from position %d.\n", pos);
        }
    }
}

void DisplayL2R()
{
    N *temp = head;
    while (temp != NULL)
    {
        printf("%d-> ", temp->data);
        temp = temp->link;
    }
}

void DisplayR2L(N *temp)
{
    if (temp == NULL)
    {
        return;
    }
    DisplayR2L(temp->link);
    printf("%d-> ", temp->data);
}

void Insert_Sorted(int data)
{
    N *newNode = (N *)malloc(sizeof(N));
    newNode->data = data;
    newNode->link = NULL;

    if (head == NULL || head->data >= data)
    {
        newNode->link = head;
        head = newNode;
    }
    else
    {
        N *temp = head;
        while (temp->link != NULL && temp->link->data < data)
        {
            temp = temp->link;
        }
        newNode->link = temp->link;
        temp->link = newNode;
    }
}

int LinearSearch(int data)
{
    N *temp = head;
    int pos = 1;
    while (temp != NULL)
    {
        if (temp->data == data)
        {
            return pos;
        }
        pos++;
        temp = temp->link;
    }
    return -1;
}

void BubbleSort()
{
    N *temp = head;
    while (temp != NULL)
    {
        N *temp2 = head;
        while (temp2->link != NULL)
        {
            if (temp2->data > temp2->link->data)
            {
                int t = temp2->data;
                temp2->data = temp2->link->data;
                temp2->link->data = t;
            }
            temp2 = temp2->link;
        }
        temp = temp->link;
    }
}

int CountNodes()
{
    N *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->link;
    }
    return count;
}

void Reverse()
{
    N *prev = NULL;
    N *current = head;
    N *next = NULL;
    while (current != NULL)
    {
        next = current->link;
        current->link = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

void DeleteAllOccurrences(int data)
{
    N *temp = head;
    N *prev = NULL;
    while (temp != NULL)
    {
        if (temp->data == data)
        {
            if (prev == NULL)
            {
                head = temp->link;
                free(temp);
                temp = head;
            }
            else
            {
                prev->link = temp->link;
                free(temp);
                temp = prev->link;
            }
        }
        else
        {
            prev = temp;
            temp = temp->link;
        }
    }
}

int main()
{
    int choice, data, pos;

    while (1)
    {
        printf("\nLinked List Operations\n");
        printf("0. Exit\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Insert at any position\n");
        printf("4. Display from left to right\n");
        printf("5. Display from right to left\n");
        printf("6. Delete from the beginning\n");
        printf("7. Delete from the end\n");
        printf("8. Delete from any position\n");
        printf("9. Insert in sorted order(Provided the list is already sorted)\n");
        printf("10.Linear Search\n");
        printf("11.Bubble Sort\n");
        printf("12.Count the number of nodes\n");
        printf("13.Reverse the linked list\n");
        printf("14.Delete all occurrences of a given element\n");
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
            printf("\n");
            break;

        case 2:
            printf("Enter the data to insert at the end: ");
            scanf("%d", &data);
            InsertAtEnd(data);
            printf("Data inserted at the end.\n");
            DisplayL2R();
            printf("\n");
            break;

        case 3:
            printf("Enter the position to insert the data: ");
            scanf("%d", &pos);
            printf("Enter the data to insert: ");
            scanf("%d", &data);
            InsertAtPosition(data, pos);
            printf("Data inserted at position %d.\n", pos);
            DisplayL2R();
            printf("\n");
            break;

        case 4:
            printf("Linked List (Left to Right): ");
            DisplayL2R();
            printf("\n");
            break;

        case 5:
            printf("Linked List (Right to Left): ");
            DisplayR2L(head);
            printf("\n");
            break;

        case 6:
            printf("Deleting node from the beginning...\n");
            DeleteAtBeginning();
            DisplayL2R();
            printf("\n");
            break;

        case 7:
            printf("Deleting node from the end...\n");
            DeleteAtEnd();
            DisplayL2R();
            printf("\n");
            break;

        case 8:
            printf("Enter the position to delete the node from: ");
            scanf("%d", &pos);
            DeleteAtPosition(pos);
            DisplayL2R();
            printf("\n");
            break;

        case 9:
            printf("Enter the data to insert in sorted order: ");
            scanf("%d", &data);
            Insert_Sorted(data);
            printf("Data inserted in sorted order.\n");
            DisplayL2R();
            printf("\n");
            break;

        case 10:
            printf("Enter the element to search: ");
            scanf("%d", &data);
            printf("Searched data found at position %d.\n", LinearSearch(data));
            DisplayL2R();
            printf("\n");
            break;

        case 11:
            printf("Sorting the linked list...\n");
            BubbleSort();
            DisplayL2R();
            printf("\n");
            break;

        case 12:
            printf("Number of nodes in the linked list: %d\n", CountNodes());
            DisplayL2R();
            printf("\n");
            break;

        case 13:
            printf("Reversing the linked list...\n");
            Reverse();
            DisplayL2R();
            printf("\n");
            break;

        case 14:
            printf("Enter the element to delete all occurrences of: ");
            scanf("%d", &data);
            DeleteAllOccurrences(data);
            DisplayL2R();
            printf("\n");
            break;

        default:
            printf("Invalid choice! Please try again.\n");
            break;
        }
    }

    return 0;
}