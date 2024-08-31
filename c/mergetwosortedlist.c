#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
} N;

N *List1 = NULL;
N *List2 = NULL;
N *TotalSorted = NULL;

void InsertAtEnd(N **list, int data)
{
    N *newNode = (N *)malloc(sizeof(N));
    newNode->data = data;
    newNode->link = NULL;
    if (*list == NULL)
    {
        *list = newNode;
    }
    else
    {
        N *temp = *list;
        while (temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = newNode;
    }
}

void BubbleSort(N *list)
{
    if (list == NULL)
    {
        return;
    }

    N *temp = list;
    while (temp != NULL)
    {
        N *temp2 = list;
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

void DisplayL2R(N *list)
{
    N *temp = list;
    while (temp != NULL)
    {
        printf("%d-> ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

void MergeSortedLists()
{
    if (List1 == NULL || List2 == NULL)
    {
        printf("One of the lists is empty.\n");
        return;
    }

    N *temp1 = List1;
    N *temp2 = List2;
    N *temp3 = TotalSorted;
    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->data < temp2->data || temp1->data == temp2->data)
        {
            // N *newNode = (N *)malloc(sizeof(N));
            // newNode->data = temp1->data;
            // printf("%d,if\n", newNode->data);
            // newNode->link = NULL;
            // if (TotalSorted == NULL)
            // {
            //     TotalSorted = newNode;
            //     DisplayL2R(TotalSorted);
            // }
            // else
            // {
            //     N *temp = TotalSorted;
            //     while (temp->link != NULL)
            //     {
            //         temp = temp->link;
            //     }
            //     temp->link = newNode;
            //     DisplayL2R(TotalSorted);
            // }
            // temp1 = temp1->link;
            InsertAtEnd(&TotalSorted, temp1->data);
            temp1 = temp1->link;
            InsertAtEnd(&TotalSorted, temp2->data);
            temp2 = temp2->link;
        }
        else if (temp1->data > temp2->data)
        {
            // N *newNode = (N *)malloc(sizeof(N));
            // newNode->data = temp2->data;
            // printf("%d,else if\n", newNode->data);
            // newNode->link = NULL;
            // if (TotalSorted == NULL)
            // {
            //     TotalSorted = newNode;
            //     DisplayL2R(TotalSorted);
            // }
            // else
            // {
            //     N *temp = TotalSorted;
            //     while (temp->link != NULL)
            //     {
            //         temp = temp->link;
            //     }
            //     temp->link = newNode;
            //     DisplayL2R(TotalSorted);
            // }
            // temp2 = temp2->link;
            InsertAtEnd(&TotalSorted, temp2->data);
            temp2 = temp2->link;
            InsertAtEnd(&TotalSorted, temp1->data);
            temp1 = temp1->link;
        }
    }
}

int main()
{
    int n1, n2, data;
    printf("Enter the number of elements in the first linked list: ");
    scanf("%d", &n1);
    printf("Enter the elements in sorted order: ");
    for (int i = 0; i < n1; i++)
    {
        scanf("%d", &data);
        // N *newNode = (N *)malloc(sizeof(N));
        // newNode->data = data;
        // newNode->link = NULL;
        // if (List1 == NULL)
        // {
        //     List1 = newNode;
        // }
        // else
        // {
        //     N *temp = List1;
        //     while (temp->link != NULL)
        //     {
        //         temp = temp->link;
        //     }
        //     temp->link = newNode;
        // }
        InsertAtEnd(&List1, data);
    }

    printf("Enter the number of elements in the second linked list: ");
    scanf("%d", &n2);
    printf("Enter the elements in sorted order: ");
    for (int i = 0; i < n2; i++)
    {
        scanf("%d", &data);
        // N *newNode = (N *)malloc(sizeof(N));
        // newNode->data = data;
        // newNode->link = NULL;
        // if (List2 == NULL)
        // {
        //     List2 = newNode;
        // }
        // else
        // {
        //     N *temp = List2;
        //     while (temp->link != NULL)
        //     {
        //         temp = temp->link;
        //     }
        //     temp->link = newNode;
        // }
        InsertAtEnd(&List2, data);
    }
    printf("List1: ");
    DisplayL2R(List1);
    BubbleSort(List1);
    printf("List1 after sorting: ");
    DisplayL2R(List1);
    printf("List2: ");
    DisplayL2R(List2);
    BubbleSort(List2);
    printf("List2 after sorting: ");
    DisplayL2R(List2);
    MergeSortedLists();
    printf("Merged sorted linked list: ");
    DisplayL2R(TotalSorted);
    printf("\n");
    return 0;
}