/*
Pseudocode for Stack Implementation Using Linked List:

1. Define Node Structure:
   - A node contains:
     - `data`: Integer data of the node.
     - `next`: Pointer to the next node.

2. Linked List Utility Functions:
   a. **CREATE_NODE(data)**:
      - Allocate memory for a new node.
      - If allocation fails, return NULL.
      - Assign `data` and set `next` to NULL.
      - Return the pointer to the new node.
   b. **INSERT_BEFORE_HEAD(head, data)**:
      - Create a new node with `data`.
      - If memory allocation fails, return error code (-1).
      - Set the new node's `next` to point to the current head.
      - Update head to point to the new node.
   c. **DELETE_HEAD(head)**:
      - If the list is empty, return error code (-1).
      - Set a temporary pointer to the current head.
      - Update head to the next node.
      - Free the memory of the temporary pointer.

3. Stack Functions:
   a. **IS_EMPTY(stack)**:
      - Return true if stack (head pointer) is NULL.
   b. **PUSH(stack, data)**:
      - Use `INSERT_BEFORE_HEAD(stack, data)` to insert the new element.
      - Print success message or handle memory allocation failure.
   c. **POP(stack)**:
      - If `IS_EMPTY(stack)` returns true, print underflow message and return -1.
      - Retrieve the data from the head node.
      - Call `DELETE_HEAD(stack)` to remove the top element.
      - Return the retrieved data.
   d. **PEEK(stack)**:
      - If `IS_EMPTY(stack)` returns true, print empty stack message and return -1.
      - Return the `data` of the head node.
   e. **PRINT_STACK(stack)**:
      - If `IS_EMPTY(stack)` returns true, print empty stack message.
      - Otherwise, traverse the linked list and print each node's data.

4. MAIN Program:
   a. Initialize `stack` as NULL.
   b. Display menu with options:
      - Push, Pop, Peek, Print Stack, Exit.
   c. Take user input for choice and perform the corresponding operation:
      - For Push, take the value to push and call `PUSH(stack, value)`.
      - For Pop, call `POP(stack)` and display the popped value if valid.
      - For Peek, call `PEEK(stack)` and display the top element if valid.
      - For Print Stack, call `PRINT_STACK(stack)`.
      - For Exit, free all memory using repeated calls to `POP(stack)` and terminate.
      - For invalid input, display an error message.
*/

#include <stdio.h>
#include <stdlib.h>

//  ________LINKED LIST UTILITY FUNCTIONS____________

// Define the structure for a node of the linked list
typedef struct Node
{
    int data;
    struct Node *next;
} node;

// linked list utility function
node *createNode(int data)
{
    // Allocating memory for a new node
    node *newNode = (node *)malloc(sizeof(node));

    // If memory allocation fails
    if (newNode == NULL)
        return NULL;

    // Assign data and set next pointer to NULL
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert data before the head node
int insertBeforeHead(node **head, int data)
{
    // Creating a new node
    node *newNode = createNode(data);
    if (!newNode) // Memory allocation failure
        return -1;

    // Insert new node at the beginning
    newNode->next = *head;
    *head = newNode;
    return 0;
}

// Function to delete the head node
int deleteHead(node **head)
{
    if (*head == NULL) // Empty list, nothing to delete
        return -1;

    node *temp = *head;
    *head = (*head)->next;
    free(temp); // Free the memory of the deleted node
    return 0;
}

// _________STACK IMPLEMENTATION STARTS HERE_________

// Function to check if the stack is empty
int isEmpty(node **stack)
{
    return *stack == NULL;
}

// Function to push an element onto the stack
void push(node **stack, int data)
{
    if (insertBeforeHead(stack, data) != 0)
    {
        printf("Stack Overflow! Unable to allocate memory.\n");
        return;
    }
    printf("Pushed %d onto the stack.\n", data);
}

// Function to pop an element from the stack
int pop(node **stack)
{
    // Checking for underflow condition
    if (isEmpty(stack))
    {
        printf("Stack Underflow! The stack is empty.\n");
        return -1;
    }

    // Retrieve the data from the head node
    int poppedData = (*stack)->data;

    // Delete the head node
    deleteHead(stack);

    return poppedData;
}

// Function to return the topmost element of the stack
int peek(node **stack)
{
    if (!isEmpty(stack))
        return (*stack)->data;

    printf("Stack is empty.\n");
    return -1;
}

// Function to print the stack
void printStack(node **stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty.\n");
        return;
    }

    node *temp = *stack;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Driver code
int main()
{
    node *stack = NULL; // Initialize stack as empty
    int choice, value;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Print Stack\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(&stack, value);
            break;

        case 2:
            value = pop(&stack);
            if (value != -1)
                printf("Popped value: %d\n", value);
            printStack(&stack);
            break;

        case 3:
            value = peek(&stack);
            if (value != -1)
                printf("Top value: %d\n", value);
            printStack(&stack);
            break;

        case 4:
            printf("Stack: ");
            printStack(&stack);
            break;

        case 5:
            printf("Exiting...\n");
            while (!isEmpty(&stack)) // Free memory before exiting
                pop(&stack);
            return 0;

        default:
            printf("Invalid choice, please try again.\n");
        }
    }
}