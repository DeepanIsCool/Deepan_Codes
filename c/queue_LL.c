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