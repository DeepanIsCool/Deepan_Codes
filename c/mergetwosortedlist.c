/*
Pseudocode for Merging and Sorting Two Linked Lists:

1. Define a Node Structure:
   - Each node contains `data` and a pointer `link` to the next node.

2. Functions:
   a. **Insert At End**:
      - Input: Pointer to the list (`list`) and data to insert (`data`).
      - Create a new node.
      - If the list is empty, make the new node the head.
      - Otherwise, traverse to the last node and link it to the new node.

   b. **Bubble Sort**:
      - Input: Pointer to the list (`list`).
      - Use nested loops to compare and swap adjacent nodes if out of order.
      - Outer loop traverses the entire list.
      - Inner loop compares each pair of adjacent nodes.

   c. **Display From Left to Right**:
      - Input: Pointer to the list (`list`).
      - Traverse from head to end and print each node's data.

   d. **Merge Two Sorted Lists**:
      - Input: Two linked lists (`List1` and `List2`).
      - Output: Merged list (`TotalSorted`).
      - Traverse both lists simultaneously:
         - Insert each node from `List1` and `List2` alternately into `TotalSorted`.
         - Continue until one or both lists are fully traversed.

3. MAIN Program:
   a. Input:
      - Read the number of elements and data for `List1` in sorted order.
      - Read the number of elements and data for `List2` in sorted order.
   b. Process:
      - Display `List1` and `List2`.
      - Call `MergeSortedLists` to merge `List1` and `List2` into `TotalSorted`.
      - Call `BubbleSort` to sort `TotalSorted`.
   c. Output:
      - Display the final merged and sorted linked list (`TotalSorted`).

4. End.
*/

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
        InsertAtEnd(&TotalSorted, temp1->data);
        temp1 = temp1->link;
        InsertAtEnd(&TotalSorted, temp2->data);
        temp2 = temp2->link;
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
        InsertAtEnd(&List1, data);
    }

    printf("Enter the number of elements in the second linked list: ");
    scanf("%d", &n2);
    printf("Enter the elements in sorted order: ");
    for (int i = 0; i < n2; i++)
    {
        scanf("%d", &data);
        InsertAtEnd(&List2, data);
    }
    printf("List1: ");
    DisplayL2R(List1);
    printf("List2: ");
    DisplayL2R(List2);
    MergeSortedLists();
    BubbleSort(TotalSorted);
    printf("Merged sorted linked list: ");
    DisplayL2R(TotalSorted);
    printf("\n");
    return 0;
}