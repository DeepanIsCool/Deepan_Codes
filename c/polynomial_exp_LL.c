/*
Pseudocode for Linked List-Based Polynomial Addition

1. Data Structure:
   - Define a node structure `Node` with:
     - coeff: Coefficient of the term.
     - pow: Power of the term.
     - next: Pointer to the next node.

2. Create a New Node:
   Function create_node(coeff, pow):
     - Allocate memory for a new node.
     - Set the node's `coeff` to `coeff` and `pow` to `pow`.
     - Initialize `next` to NULL.
     - Return the new node.

3. Insert Node at the End:
   Function insert_node(poly, coeff, pow):
     - Input: Pointer to the polynomial list `poly`, `coeff`, and `pow`.
     - Create a new node with the given `coeff` and `pow`.
     - If `poly` is empty, set `poly` to the new node and return.
     - Otherwise, traverse to the last node and set its `next` to the new node.

4. Display Polynomial:
   Function show(node):
     - Input: Pointer to the head of the polynomial list.
     - If the list is empty, print "0".
     - Traverse through the list:
       - Print each term in the format `coeffx^pow`.
       - Add a " + " separator between terms if applicable.

5. Create Polynomial from User Input:
   Function create_polynomial(poly):
     - Input: Pointer to the polynomial list `poly`.
     - Prompt the user to enter the number of terms.
     - For each term:
       - Prompt the user for the coefficient and power.
       - Insert the term into the polynomial list using `insert_node`.

6. Add Two Polynomials:
   Function polyadd(poly1, poly2, poly):
     - Input: Pointers to the two polynomial lists `poly1` and `poly2`, and a pointer to the result list `poly`.
     - While both `poly1` and `poly2` are not NULL:
       - If `poly1`'s power > `poly2`'s power:
         - Insert `poly1`'s term into `poly` and advance `poly1`.
       - If `poly1`'s power < `poly2`'s power:
         - Insert `poly2`'s term into `poly` and advance `poly2`.
       - Otherwise (same power):
         - Add the coefficients, insert the result into `poly`, and advance both `poly1` and `poly2`.
     - Add any remaining terms from `poly1` or `poly2` to `poly`.

7. Driver Code:
   - Create three polynomials: `poly1`, `poly2`, and `poly_sum`.
   - Call `create_polynomial` for `poly1` and `poly2`.
   - Display `poly1` and `poly2` using `show`.
   - Add `poly1` and `poly2` using `polyadd` to obtain `poly_sum`.
   - Display `poly_sum` using `show`.

8. End.
*/

#include <stdio.h>
#include <stdlib.h>

// Structure to represent each term of the polynomial
typedef struct Node
{
    int coeff;
    int pow;
    struct Node *next;
} N;

// Function to create a new node
N *create_node(int coeff, int pow)
{
    N *new_node = (N *)malloc(sizeof(N));
    new_node->coeff = coeff;
    new_node->pow = pow;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a node at the end of the list
void insert_node(N **poly, int coeff, int pow)
{
    N *new_node = create_node(coeff, pow);
    if (*poly == NULL)
    {
        *poly = new_node;
        return;
    }
    N *temp = *poly;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
}

// Function to print the polynomial
void show(N *node)
{
    if (node == NULL)
    {
        printf("0\n");
        return;
    }
    while (node != NULL)
    {
        printf("%dx^%d", node->coeff, node->pow);
        node = node->next;
        if (node != NULL && node->coeff >= 0)
        {
            printf(" + ");
        }
    }
    printf("\n");
}

// Function to create a polynomial based on user input
void create_polynomial(N **poly)
{
    int num_terms, coeff, pow;
    printf("Enter the number of terms in the polynomial: ");
    scanf("%d", &num_terms);

    for (int i = 0; i < num_terms; i++)
    {
        printf("Enter coefficient and power for term %d: ", i + 1);
        scanf("%d %d", &coeff, &pow);
        insert_node(poly, coeff, pow);
    }
}

// Function to add two polynomials
void polyadd(N *poly1, N *poly2, N **poly)
{
    N *temp = NULL;
    while (poly1 != NULL && poly2 != NULL)
    {
        if (poly1->pow > poly2->pow)
        {
            insert_node(&temp, poly1->coeff, poly1->pow);
            poly1 = poly1->next;
        }
        else if (poly1->pow < poly2->pow)
        {
            insert_node(&temp, poly2->coeff, poly2->pow);
            poly2 = poly2->next;
        }
        else
        {
            insert_node(&temp, poly1->coeff + poly2->coeff, poly1->pow);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    // Add the remaining terms of poly1
    while (poly1 != NULL)
    {
        insert_node(&temp, poly1->coeff, poly1->pow);
        poly1 = poly1->next;
    }

    // Add the remaining terms of poly2
    while (poly2 != NULL)
    {
        insert_node(&temp, poly2->coeff, poly2->pow);
        poly2 = poly2->next;
    }

    *poly = temp;
}

// Driver code
int main()
{
    N *poly1 = NULL, *poly2 = NULL, *poly_sum = NULL;

    printf("Creating first polynomial:\n");
    create_polynomial(&poly1);

    printf("Creating second polynomial:\n");
    create_polynomial(&poly2);

    printf("First polynomial: ");
    show(poly1);

    printf("Second polynomial: ");
    show(poly2);

    // Add the two polynomials
    polyadd(poly1, poly2, &poly_sum);

    printf("Added polynomial: ");
    show(poly_sum);

    return 0;
}