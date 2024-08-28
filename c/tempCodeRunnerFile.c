// C++ program for addition of two polynomials
// using Linked Lists
#include <stdio.h>
#include <stdlib.h>

// Node structure containing power and coefficient of
// variable
struct Node
{
    int coeff;
    int pow;
    struct Node *next;
};

// Function to create new node
struct Node *create_node(int x, int y)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->coeff = x;
    new_node->pow = y;
    new_node->next = NULL;
    return new_node;
}

void create_polynomial(struct Node **poly)
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

// Function to insert a node at the end of the list
void insert_node(struct Node **poly, int coeff, int pow)
{
    struct Node *new_node = create_node(coeff, pow);
    if (*poly == NULL)
    {
        *poly = new_node;
        return;
    }
    struct Node *temp = *poly;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
}

// Function Adding two polynomial numbers
void polyadd(struct Node *poly1, struct Node *poly2,
             struct Node *poly)
{
    while (poly1->next && poly2->next)
    {
        // If power of 1st polynomial is greater then 2nd,
        // then store 1st as it is and move its pointer
        if (poly1->pow > poly2->pow)
        {
            poly->pow = poly1->pow;
            poly->coeff = poly1->coeff;
            poly1 = poly1->next;
        }

        // If power of 2nd polynomial is greater then 1st,
        // then store 2nd as it is and move its pointer
        else if (poly1->pow < poly2->pow)
        {
            poly->pow = poly2->pow;
            poly->coeff = poly2->coeff;
            poly2 = poly2->next;
        }

        // If power of both polynomial numbers is same then
        // add their coefficients
        else
        {
            poly->pow = poly1->pow;
            poly->coeff = poly1->coeff + poly2->coeff;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }

        // Dynamically create new node
        poly->next = (struct Node *)malloc(sizeof(struct Node));
        poly = poly->next;
        poly->next = NULL;
    }
    while (poly1->next || poly2->next)
    {
        if (poly1->next)
        {
            poly->pow = poly1->pow;
            poly->coeff = poly1->coeff;
            poly1 = poly1->next;
        }
        if (poly2->next)
        {
            poly->pow = poly2->pow;
            poly->coeff = poly2->coeff;
            poly2 = poly2->next;
        }
        poly->next = (struct Node *)malloc(sizeof(struct Node));
        poly = poly->next;
        poly->next = NULL;
    }
}

// Display Linked list
void show(struct Node *node)
{
    while (node->next != NULL)
    {
        printf("%dx^%d", node->coeff, node->pow);
        node = node->next;
        if (node->coeff >= 0)
        {
            if (node->next != NULL)
                printf("+");
        }
    }
}

// Driver code
int main()
{
    struct Node *poly1 = NULL, *poly2 = NULL, *poly = NULL;

    printf("Creating first polynomial:\n");
    create_polynomial(&poly1);

    printf("Creating second polynomial:\n");
    create_polynomial(&poly2);

    printf("First polynomial: ");
    show(poly1);

    printf("Second polynomial: ");
    show(poly2);

    poly = (struct Node *)malloc(sizeof(struct Node));

    // Function add two polynomial numbers
    polyadd(poly1, poly2, poly);

    // Display resultant List
    printf("\nAdded polynomial: ");
    show(poly);
    printf("\n");

    return 0;
}
