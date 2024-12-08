/*
Pseudocode for Linked List-Based Queue Implementation

1. Data Structures:
   - Define a `Node` structure:
     - data: Stores the value of the node.
     - next: Pointer to the next node in the queue.
   - Define a `Queue` structure:
     - front: Pointer to the front node of the queue.
     - rear: Pointer to the rear node of the queue.

2. Create a New Node:
   Function createNode(data):
     - Allocate memory for a new node.
     - If memory allocation fails, return NULL.
     - Set newNode.data = data and newNode.next = NULL.
     - Return the new node.

3. Create a New Queue:
   Function createQueue():
     - Allocate memory for a new queue.
     - If memory allocation fails, return NULL.
     - Set front = NULL and rear = NULL.
     - Return the new queue.

4. Check if the Queue is Empty:
   Function isEmpty(queue):
     - Return true if queue.front == NULL, otherwise false.

5. Add an Element to the Queue (Enqueue):
   Function enqueue(queue, data):
     - Create a new node with the given data.
     - If memory allocation fails, print "Queue Overflow!" and exit.
     - If queue.rear == NULL (queue is empty):
       - Set queue.front = queue.rear = newNode.
     - Otherwise:
       - Set queue.rear.next = newNode and update queue.rear = newNode.
     - Print "Enqueued <data>".

6. Remove an Element from the Queue (Dequeue):
   Function dequeue(queue):
     - If queue is empty (queue.front == NULL):
       - Print "Queue Underflow!" and return -1.
     - Store the value of queue.front.data in a variable `data`.
     - Update queue.front = queue.front.next.
     - If queue.front == NULL (queue is now empty), set queue.rear = NULL.
     - Free the memory of the dequeued node.
     - Return `data`.

7. Get the Front Element (Peek):
   Function peek(queue):
     - If queue is empty, print "Queue is empty!" and return -1.
     - Return queue.front.data.

8. Print the Queue:
   Function printQueue(queue):
     - If queue is empty, print "Queue is empty!" and exit.
     - Traverse from queue.front to queue.rear and print each node's data.

9. Main Menu-Driven Program:
   - Initialize a queue using createQueue().
   - Display the menu with options:
     1. Enqueue: Add an element to the queue.
     2. Dequeue: Remove an element from the queue.
     3. Peek: Display the front element of the queue.
     4. Print Queue: Display all elements in the queue.
     5. Exit: Exit the program.
   - Execute the selected operation and repeat until the user chooses to exit.
   - Before exiting:
     - Dequeue all elements to free memory.
     - Free the queue structure.
*/

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node of the linked list
typedef struct Node
{
    int data;
    struct Node *next;
} node;

// Define the structure for the queue
typedef struct Queue
{
    node *front;
    node *rear;
} queue;

// Function to create a new node
node *createNode(int data)
{
    node *newNode = (node *)malloc(sizeof(node));
    if (newNode == NULL)
        return NULL;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a new queue
queue *createQueue()
{
    queue *newQueue = (queue *)malloc(sizeof(queue));
    if (!newQueue)
        return NULL;
    newQueue->front = newQueue->rear = NULL;
    return newQueue;
}

// Function to check if the queue is empty
int isEmpty(queue *q)
{
    return q->front == NULL;
}

// Function to add an element to the queue
void enqueue(queue *q, int data)
{
    node *newNode = createNode(data);
    if (!newNode)
    {
        printf("Queue Overflow!\n");
        return;
    }
    if (q->rear == NULL)
    {
        q->front = q->rear = newNode;
    }
    else
    {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    printf("Enqueued %d\n", data);
}

// Function to remove an element from the queue
int dequeue(queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue Underflow!\n");
        return -1;
    }
    node *temp = q->front;
    int data = temp->data;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp);
    return data;
}

// Function to return the front element of the queue
int peek(queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty!\n");
        return -1;
    }
    return q->front->data;
}

// Function to print the queue
void printQueue(queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty.\n");
        return;
    }
    node *temp = q->front;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Menu-driven program
int main()
{
    queue *q = createQueue();
    if (!q)
    {
        printf("Failed to initialize queue!\n");
        return -1;
    }

    int choice, value;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Print Queue\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to enqueue: ");
            scanf("%d", &value);
            enqueue(q, value);
            break;

        case 2:
            value = dequeue(q);
            if (value != -1)
                printf("Dequeued: %d\n", value);
            break;

        case 3:
            value = peek(q);
            if (value != -1)
                printf("Front element: %d\n", value);
            break;

        case 4:
            printf("Queue: ");
            printQueue(q);
            break;

        case 5:
            printf("Exiting...\n");
            // Free memory before exiting
            while (!isEmpty(q))
                dequeue(q);
            free(q);
            return 0;

        default:
            printf("Invalid choice, please try again.\n");
        }
    }
}