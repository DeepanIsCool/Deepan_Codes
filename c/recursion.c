#include <stdio.h>

int factorial(int num)
{
    if (num == 0 || num == 1)
        return 1;
    else
        return num * factorial(num - 1);
}

int add(int n)
{
    if (n == 1)
        return 1;
    else
        return n + add(n - 1);
}

double expo(int x, int y)
{
    if (y == 0)
        return 1;
    else if (y < 0)
        return 1 / expo(x, -y);
    else
        return x * expo(x, y - 1);
}

int fibonacci(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

int gcd(int x, int y)
{
    if (y == 0)
        return x;
    else
        return gcd(y, x % y);
}

int main()
{
    int x, y, choice = 1;

    while (choice != 0)
    {
        printf("\nMenu Driven Program using Recursion:\n");
        printf("1. Factorial.\n");
        printf("2. Sum up-to n natural numbers.\n");
        printf("3. Fibonacci Series up-to n terms.\n");
        printf("4. GCD of two no.s.\n");
        printf("5. Value of a^b.\n");
        printf("0. Exit.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
            printf("Exiting...\n");
            break;

        case 1:
            printf("Enter a number: ");
            scanf("%d", &x);
            if (x < 0)
                printf("Input should be a positive number\n");
            else
                printf("Factorial of %d: %d\n", x, factorial(x));
            break;

        case 2:
            printf("Enter the number of terms: ");
            scanf("%d", &x);
            printf("Sum of first %d natural numbers is %d\n", x, add(x));
            break;

        case 3:
            printf("Enter the number of terms: ");
            scanf("%d", &x);
            if (x < 0)
                printf("Input Should be a positive number.\n");
            else
            {
                printf("Fibonacci Series up-to %dth term is: \n", x);
                for (int i = 0; i < x; i++)
                {
                    printf("%d\t", fibonacci(i));
                }
            }
            printf("\n");
            break;

        case 4:
            printf("Enter the two numbers: ");
            scanf("%d %d", &x, &y);
            printf("GCD of the two no.s is: %d\n", gcd(x, y));
            break;

        case 5:
            printf("Enter the coefficient and its power: ");
            scanf("%d %d", &x, &y);
            printf("%d^%d is: %.5lf\n", x, y, expo(x, y));
            break;

        default:
            printf("Invalid Choice\n");
        }
    }
    return 0;
}