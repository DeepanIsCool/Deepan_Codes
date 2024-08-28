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