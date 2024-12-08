/*
Pseudocode for Tower of Hanoi:

1. Function: TOWER(n, from, to, aux)
   Input:
      - n: Number of disks.
      - from: The source rod.
      - to: The destination rod.
      - aux: The auxiliary rod.
   Steps:
      a. Base Case:
         - If n == 1:
           - Print "Move disk 1 from {from} to {to}".
           - Return.
      b. Recursive Case:
         - Call TOWER(n - 1, from, aux, to) to move (n - 1) disks from `from` to `aux` using `to`.
         - Print "Move disk n from {from} to {to}".
         - Call TOWER(n - 1, aux, to, from) to move (n - 1) disks from `aux` to `to` using `from`.

2. MAIN Program:
   a. Call TOWER(3, 'A', 'C', 'B') to solve the problem for 3 disks:
      - A: Source rod.
      - C: Destination rod.
      - B: Auxiliary rod.

3. Output:
   - Sequence of moves to transfer all disks from the source rod to the destination rod following the rules:
      - Only one disk can be moved at a time.
      - Larger disks cannot be placed on smaller disks.

4. End.
*/

#include <stdio.h>

void tower(int n, char from, char to, char aux)
{
    if (n == 1)
    {
        printf("Move disk 1 from %c to %c\n", from, to);
        return;
    }
    tower(n - 1, from, aux, to);
    printf("Move disk %d from %c to %c\n", n, from, to);
    tower(n - 1, aux, to, from);
}

int main()
{
    tower(3, 'A', 'C', 'B');
    return 0;
}
