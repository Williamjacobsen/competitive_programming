//
// Created by villi on 11/10/2024.
//

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target)
{
    int len = matrixSize * *matrixColSize;

    int colSize = *matrixColSize;

    int l = 0;
    int r = len-1;
    int m = 0;

    while (l <= r)
    {
        m = (l + r) / 2;

        int row = m / colSize;
        int col = m % colSize;

        //printf("m=%d, l=%d, r=%d\n", m, l, r);
        if (matrix[row][col] > target)
        {
            r = m - 1;
        }
        else if (matrix[row][col] < target)
        {
            l = m + 1;
        }
        else
        {
            return true;
        }
    }
    return false;
}

int main(void)
{
    int** matrix = (int**)malloc(3 * sizeof(int*));
    matrix[0] = (int*)malloc(4 * sizeof(int));
    matrix[1] = (int*)malloc(4 * sizeof(int));
    matrix[2] = (int*)malloc(4 * sizeof(int));
    matrix[0][0] = 1;
    matrix[0][1] = 3;
    matrix[0][2] = 5;
    matrix[0][3] = 7;
    matrix[1][0] = 10;
    matrix[1][1] = 11;
    matrix[1][2] = 16;
    matrix[1][3] = 20;
    matrix[2][0] = 23;
    matrix[2][1] = 30;
    matrix[2][2] = 34;
    matrix[2][3] = 60;
    int matrixColSize = 4;
    int res = searchMatrix(matrix, 3, &matrixColSize, 13);
    printf("%d\n", res);
    return 0;
}
