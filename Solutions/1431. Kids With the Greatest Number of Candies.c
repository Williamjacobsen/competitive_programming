//
// Created by villi on 10/27/2024.
//

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
/**
* Note: The returned array must be malloced, assume caller calls free().
 */
bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize) {
    bool* result = malloc(sizeof(bool) * candiesSize);

    int max = 0;
    for (int i = 0; i < candiesSize; i++)
    {
        if (candies[i] > max)
        {
            max = candies[i];
        }
    }

    for (int i = 0; i < candiesSize; i++)
    {
        if (candies[i] + extraCandies >= max)
        {
            result[i] = true;
        }
        else
        {
            result[i] = false;
        }
    }

    *returnSize = candiesSize;
    return result;
}

int main(void)
{
    int candies[] = {2,3,5,1,3};
    int size = sizeof(candies) / sizeof(int);
    int extraCandies = 3;
    int returnSize;

    bool* result = kidsWithCandies(candies, size, extraCandies, &returnSize);

    for (int i = 0; i < returnSize; i++)
    {
        printf("%d\n", result[i]);
    }

    free(result);
    return 0;
}