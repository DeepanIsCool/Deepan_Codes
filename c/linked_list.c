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
    }
    else
    {
        N *temp = head;
        N *prev = NULL;
        for (int i = 1; i < pos && temp != NULL; i++)
        {
            prev = temp;
            temp = temp->link;
        }
        if (temp == NULL)
        {
            printf("Position out of range\n");
        }
        else
        {
            prev->link = temp->link;
            free(temp);
        }
    }
    printf("Node deleted from position %d.\n", pos);
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
        printf("Enter your choice: ");
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
        default:
            printf("Invalid choice! Please try again.\n");
            break;
        }
    }

    return 0;
}