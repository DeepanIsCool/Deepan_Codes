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

void MergeSortedLists(N *List1, N *List2)
{
    N *temp1 = List1;
    N *temp2 = List2;
    N *TotalSorted = NULL;
    N *temp = TotalSorted;
    // while (temp1->link != NULL)
    // {
    //     temp1 = temp1->link;
    // }
    // while (temp2->link != NULL)
    // {
    //     temp2 = temp2->link;
    // }
    // temp1->link = temp2;
    // BubbleSort();
    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->data < temp2->data || temp1->data == temp2->data)
        {
            TotalSorted->data = temp1->data;
            temp1 = temp1->link;
            TotalSorted = TotalSorted->link;
            TotalSorted->data = temp2->data;
        }
        else if (temp1->data > temp2->data)
        {
            TotalSorted->data = temp2->data;
            temp2 = temp2->link;
            TotalSorted = TotalSorted->link;
            TotalSorted->data = temp1->data;
        }
    }

    printf("Merged sorted linked list: ");
    while (temp != NULL)
    {
        printf("%d-> ", temp->data);
        temp = temp->link;
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
        printf("15.Merge two sorted linked lists into sorted order\n");
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

        case 15:
        {
            int n1, n2;
            printf("Enter the number of elements in the first linked list: ");
            scanf("%d", &n1);
            printf("Enter the elements in sorted order: ");
            for (int i = 0; i < n1; i++)
            {
                scanf("%d", &data);
                Insert_Sorted(data);
            }
            printf("Enter the number of elements in the second linked list: ");
            scanf("%d", &n2);
            printf("Enter the elements in sorted order: ");
            for (int i = 0; i < n2; i++)
            {
                scanf("%d", &data);
                Insert_Sorted(data);
            }
            // provided 2 lists are created and sorted -> MergeSortedLists(List1, List2);
            DisplayL2R();
            printf("\n");
            break;
        }
        default:
            printf("Invalid choice! Please try again.\n");
            break;
        }
    }

    return 0;
}