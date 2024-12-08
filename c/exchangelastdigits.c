/*
Pseudocode for Exchanging Last Digits of Two Numbers

1. Input:
   - Prompt the user to enter two numbers `a` and `b`.
   - Read the integers `a` and `b`.

2. Isolate the Last Digits:
   - Store the last digit of `a` in a temporary variable: `temp = a % 10`.
   - Update `a` by removing its last digit: `a = a / 10`.

3. Swap Last Digits:
   - Append the last digit of `b` to `a`:
     - `a = a * 10 + (b % 10)`.
   - Update `b` by removing its last digit: `b = b / 10`.
   - Append the original last digit of `a` (stored in `temp`) to `b`:
     - `b = b * 10 + temp`.

4. Output:
   - Print the modified values of `a` and `b` with their last digits exchanged.

5. End.
*/

#include <stdio.h>
int main()
{
  int a, b;
  printf("Enter the first number: ");
  scanf("%d", &a);
  printf("Enter the second number: ");
  scanf("%d", &b);
  int temp;
  temp = a % 10;
  a = a / 10;
  a = a * 10 + b % 10;
  b = b / 10;
  b = b * 10 + temp;
  printf("The first number after exchanging last digits is: %d\n", a);
  printf("The second number after exchanging last digits is: %d\n", b);
  return 0;
}