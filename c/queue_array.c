/*
Pseudocode for Static Array-Based Queue Implementation

1. Data Structure:
   - Use an array `queue[MAXSIZE]` to store the elements.
   - Use two pointers:
     - `front`: Points to the front element of the queue.
     - `rear`: Points to the rear element of the queue.
   - Initialize:
     - `front = -1`, `rear = -1`.

2. Insert an Element (Enqueue):
   Function insert():
     - Input: An integer `item` to insert.
     - If `rear == MAXSIZE - 1`:
       - Print "Queue Overflow! Cannot insert element."
       - Exit.
     - If `front == -1 && rear == -1` (queue is empty):
       - Set `front = 0` and `rear = 0`.
     - Otherwise:
       - Increment `rear`.
     - Set `queue[rear] = item`.
     - Print "Value inserted into the queue."

3. Delete an Element (Dequeue):
   Function delete():
     - If `front == -1 || front > rear` (queue is empty):
       - Print "Queue Underflow! Cannot delete element."
       - Exit.
     - Retrieve the element at `queue[front]`.
     - If `front == rear` (only one element in the queue):
       - Set `front = -1` and `rear = -1` (queue becomes empty).
     - Otherwise:
       - Increment `front`.
     - Print "Value deleted from the queue."

4. Display the Queue:
   Function display():
     - If `front == -1` (queue is empty):
       - Print "The queue is empty."
       - Exit.
     - Print all elements in the queue from `front` to `rear`.

5. Main Menu:
   - Provide options for:
     1. Insert an element.
     2. Delete an element.
     3. Display the queue.
     4. Exit the program.
   - Execute the selected operation and repeat until the user chooses to exit.

6. End.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 5 // Maximum size of the queue

void insert();  // Function to insert an element into the queue
void delete();  // Function to delete an element from the queue
void display(); // Function to display the elements of the queue

int front = -1, rear = -1; // Initialize front and rear pointers
int queue[MAXSIZE];        // Array to store queue elements

void main()
{
    int choice;
    printf("\n************************* Main Menu *****************************\n");
    while (1) // Infinite loop for menu-driven interface
    {

        printf("\n=================================================================\n");
        printf("1. Insert an element\n");
        printf("2. Delete an element\n");
        printf("3. Display the queue\n");
        printf("4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            delete ();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("\nExiting program. Goodbye!\n");
            exit(0);
        default:
            printf("\nInvalid choice! Please try again.\n");
        }
    }
}

// Function to insert an element into the queue
void insert()
{
    int item;
    printf("\nEnter the element to insert: ");
    scanf("%d", &item);

    if (rear == MAXSIZE - 1) // Check if the queue is full
    {
        printf("\nQueue Overflow! Cannot insert element.\n");
        return;
    }

    if (front == -1 && rear == -1) // If queue is empty
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear = rear + 1; // Increment rear pointer
    }

    queue[rear] = item;
    printf("\nValue %d inserted into the queue.\n", item);
}

// Function to delete an element from the queue
void delete()
{
    if (front == -1 || front > rear) // Check if the queue is empty
    {
        printf("\nQueue Underflow! Cannot delete element.\n");
        return;
    }

    int item = queue[front];
    if (front == rear) // If the queue has only one element
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = front + 1; // Increment front pointer
    }

    printf("\nValue %d deleted from the queue.\n", item);
}

// Function to display the queue
void display()
{
    if (front == -1) // Check if the queue is empty
    {
        printf("\nThe queue is empty.\n");
        return;
    }

    printf("\nQueue elements:\n");
    for (int i = front; i <= rear; i++)
    {
        printf("%d->", queue[i]);
    }
    printf("\n");
}