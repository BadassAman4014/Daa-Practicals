#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
void printBoard(int board[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%c ", board[i] == j ? 'Q' : '.');
        }
        printf("\n");
    }
    printf("\n");
}
bool isSafe(int board[], int row, int col)
{
    for (int i = 0; i < col; i++)
    {
        if (board[i] == row || abs(board[i] - row) == abs(i - col))
        {
            return false;
        }
    }
    return true;
}
bool solve(int board[], int col, int size, int *count)
{
    if (col == size)
    {
        (*count)++;
        printBoard(board, size);
        return true;
    }
    bool res = false;
    for (int i = 0; i < size; i++)
    {
        if (isSafe(board, i, col))
        {
            board[col] = i;
            res = solve(board, col + 1, size, count) || res;
        }
    }
    return res;
}
int main()
{
    int size;
    printf("Enter the size of the board: ");
    scanf("%d", &size);
    int *board = (int *)malloc(size * sizeof(int));
    int count = 0;
    solve(board, 0, size, &count);
    printf("Number of solutions: %d\n", count);
    free(board);
    return 0;
}
