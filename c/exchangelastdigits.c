#include <stdio.h>
int main() {
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