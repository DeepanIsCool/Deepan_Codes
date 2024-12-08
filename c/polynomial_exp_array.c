/*
Pseudocode for Polynomial Addition Program

1. Data Structure:
   - Define a structure `Polynomial` with:
     - coeff: Coefficient of the term.
     - exp: Exponent of the term.

2. Display Polynomial:
   Function display(poly[], terms):
     - Input: Array `poly[]` with `terms` elements.
     - For each term:
       - Print `coeff` and `exp` in the format `coeffX^exp`.

3. Read Polynomial Expression:
   Function readExpression(poly[]):
     - Input: Array `poly[]`.
     - Prompt user to enter the number of terms (`terms`).
     - For each term:
       - Read `coeff` and `exp` and store them in `poly[]`.
     - Return the number of terms (`terms`).

4. Add Two Polynomial Expressions:
   Function addExpressions(firstCount, secondCount):
     - Input: Number of terms in the first (`firstCount`) and second (`secondCount`) polynomials.
     - Initialize pointers `i`, `j`, and `k` to 0 for traversing the `first`, `second`, and `result` arrays.
     - While both polynomials have unprocessed terms:
       - If exponents are equal:
         - Add coefficients and store in `result[k]`.
         - Copy exponent from either polynomial to `result[k]`.
         - Increment `i`, `j`, and `k`.
       - If the exponent of the current term in `first` is greater:
         - Copy the term from `first` to `result[k]`.
         - Increment `i` and `k`.
       - Otherwise:
         - Copy the term from `second` to `result[k]`.
         - Increment `j` and `k`.
     - Copy any remaining terms from `first` or `second` to `result`.
     - Return the total number of terms in `result` (`k`).

5. Main Function:
   - Read the first polynomial into `first[]` using `readExpression`.
   - Read the second polynomial into `second[]` using `readExpression`.
   - Display both polynomials using `display`.
   - Add the two polynomials using `addExpressions` and store the count in `resultCount`.
   - Display the resultant polynomial using `display`.

6. End.
*/

#include <stdio.h>
#include <stdlib.h>

struct Polynomial
{
    int coeff;
    int exp;
};

struct Polynomial first[15], second[15], result[15];

void display(struct Polynomial poly[], int terms)
{
    int i;
    printf("\n");
    for (i = 0; i < terms; i++)
    {
        printf("%dX^%d+ ", poly[i].coeff, poly[i].exp);
    }
}

int readExpression(struct Polynomial poly[])
{
    int terms, i;
    printf("\nNumber of terms: ");
    scanf("%d", &terms);
    printf("\nEnter the coeffecients and exponents in DESCENDING order");
    for (i = 0; i < terms; i++)
    {
        printf("\nCoeffecient :");
        scanf("%d", &poly[i].coeff);
        printf("Exponent :");
        scanf("%d", &poly[i].exp);
    }
    return terms;
}

int addExpressions(int firstCount, int secondCount)
{
    int i, j, k;
    i = 0;
    j = 0;
    k = 0;
    while (i < firstCount && j < secondCount)
    {
        if (first[i].exp == second[j].exp)
        {
            result[k].coeff = first[i].coeff + second[j].coeff;
            result[k].exp = first[i].exp;
            i++;
            j++;
            k++;
        }
        else if (first[i].exp > second[j].exp)
        {
            result[k].coeff = first[i].coeff;
            result[k].exp = first[i].exp;
            i++;
            k++;
        }
        else
        {
            result[k].coeff = second[i].coeff;
            result[k].exp = second[j].exp;
            j++;
            k++;
        }
    }

    while (i < firstCount)
    {
        result[k].coeff = first[i].coeff;
        result[k].exp = first[i].exp;
        k++;
        i++;
    }

    while (j < secondCount)
    {
        result[k].coeff = second[j].coeff;
        result[k].exp = second[j].exp;
        k++;
        j++;
    }
    return k;
}

int main()
{
    int firstCount, secondCount, resultCount;
    printf("\nFirst Expression:\n");
    firstCount = readExpression(first);
    printf("\nSecond Expression:\n");
    secondCount = readExpression(second);
    printf("\nFirst Expression");
    display(first, firstCount);
    display(second, secondCount);
    resultCount = addExpressions(firstCount, secondCount);
    printf("\nResultant Expression:\n");
    display(result, resultCount);
    return 0;
}