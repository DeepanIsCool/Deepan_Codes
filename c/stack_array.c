/*
Pseudocode for Stack Operations Using Array:

1. Initialize:
   - Declare `stack` array, `top = -1`, and `n` (maximum size of the stack).

2. MAIN Program:
   - Input the size `n` of the stack.
   - While `choice != 4`:
      a. Display menu:
         - Options: Push, Pop, Show, Exit.
      b. Take user input for `choice`.
      c. Perform operation based on `choice`:
         i. If `choice == 1`, call `PUSH`.
         ii. If `choice == 2`, call `POP`.
         iii. If `choice == 3`, call `SHOW`.
         iv. If `choice == 4`, print "Exiting...".
         v. Otherwise, print "Invalid choice".

3. Function: PUSH()
   - Input a value `val`.
   - If `top == n - 1` (stack full), print "Overflow".
   - Else:
      - Increment `top`.
      - Insert `val` at `stack[top]`.
   - Call `SHOW` to display the stack.

4. Function: POP()
   - If `top == -1` (stack empty), print "Underflow".
   - Else:
      - Decrement `top`.
   - Call `SHOW` to display the stack.

5. Function: SHOW()
   - Print all elements in the stack from `stack[top]` to `stack[0]`.
   - If `top == -1`, print "Stack is empty".

6. End.
*/

#include <stdio.h>

int stack[100], i, j, choice = 0, n, top = -1;

void push();
void pop();
void show();

int main()
{

    printf("Enter the number of elements in the stack ");
    scanf("%d", &n);
    printf("\nStack operations using array");

    printf("\n----------------------------------------------\n");
    while (choice != 4)
    {
        printf("Choose one from the below options...\n");
        printf("\n1.Push\n2.Pop\n3.Show\n4.Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            push();
            break;
        }
        case 2:
        {
            pop();
            break;
        }
        case 3:
        {
            show();
            break;
        }
        case 4:
        {
            printf("Exiting....\n");
            break;
        }
        default:
        {
            printf("Please Enter valid choice ");
        }
        };
    }
    return 0;
}

void push()
{
    int val;
    if (top == n - 1)
        printf("\n Overflow");
    else
    {
        printf("Enter the value?");
        scanf("%d", &val);
        top = top + 1;
        stack[top] = val;
    }
    show();
}

void pop()
{
    if (top == -1)
        printf("Underflow");
    else
        top = top - 1;

    show();
}
void show()
{
    for (i = top; i >= 0; i--)
    {
        printf("%d\n", stack[i]);
    }
    if (top == -1)
    {
        printf("Stack is empty");
    }
}