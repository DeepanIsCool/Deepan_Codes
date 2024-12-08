/*
Pseudocode for Extracting Last Digit and Remaining Number

1. Input:
   - Prompt the user to enter a number `n`.
   - Read the integer `n`.

2. Compute the Last Digit:
   - Calculate `ld = n - ((n / 10) * 10)`.
     - This subtracts the integer division result of `n / 10` multiplied by 10 from `n`.
     - This effectively isolates the last digit.

3. Compute the Remaining Number:
   - Calculate `newNumber = (n - ld) / 10`.
     - This removes the last digit by subtracting it from `n` and dividing by 10.

4. Output:
   - Print the last digit `ld`.
   - Print the remaining number `newNumber`.

5. End.
*/

#include <stdio.h>

int main()
{
   int n;
   printf("Enter a num: ");
   scanf("%d", &n);
   int ld = n - ((n / 10) * 10);
   printf("Last Digit: %d\n", ld);
   printf("New Numer: %d\n", (n - ld) / 10);
   return 0;
}