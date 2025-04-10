/*function solveSudoku(board):
    // Loop through each cell in the board
    for row from 0 to 8:
        for col from 0 to 8:

            // Check if the current cell is empty (contains 0)
            if board[row][col] == 0:

                // Try placing digits 1 through 9 in the empty cell
                for digit from 1 to 9:

                    // Check if placing 'digit' at board[row][col] is valid
                    if isValid(board, row, col, digit):

                        // Place the digit temporarily
                        board[row][col] = digit

                        // Recursively attempt to solve the rest of the board
                        if solveSudoku(board) == true:
                            return true  // Success: solution found

                        // If it leads to an invalid state, backtrack
                        board[row][col] = 0  // Remove digit

                // If no valid digit can be placed, trigger backtracking
                return false

    // If all cells are filled correctly, return true
    return true
*/

#include <stdio.h>
#include <stdbool.h>

#define SIZE 9

void printBoard(int board[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

bool isValid(int board[SIZE][SIZE], int row, int col, int num)
{

    for (int i = 0; i < SIZE; i++)
    {
        if (board[row][i] == num || board[i][col] == num)
        {
            return false;
        }
    }

    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[startRow + i][startCol + j] == num)
            {
                return false;
            }
        }
    }

    return true;
}

bool solveSudoku(int board[SIZE][SIZE])
{
    for (int row = 0; row < SIZE; row++)
    {
        for (int col = 0; col < SIZE; col++)
        {
            if (board[row][col] == 0)
            {
                for (int num = 1; num <= 9; num++)
                {
                    if (isValid(board, row, col, num))
                    {
                        board[row][col] = num;

                        if (solveSudoku(board))
                        {
                            return true;
                        }

                        board[row][col] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int board[SIZE][SIZE] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}};

    printf("Original Sudoku Puzzle:\n");
    printBoard(board);

    if (solveSudoku(board))
    {
        printf("\nSolved Sudoku Puzzle:\n");
        printBoard(board);
    }
    else
    {
        printf("No solution exists for the given Sudoku puzzle.\n");
    }

    return 0;
}