//
// Created by villi on 11/4/2024.
//

#include <stdio.h>

double findMaxAverage(int* nums, int numsSize, int k)
{
    int sum = 0;
    int tempSum = 0;
    for (int i = 0; i < k; i++)
    {
        sum += nums[i];
    }
    tempSum = sum;
    for (int i = 0, j = k; j < numsSize; i++, j++)
    {
        tempSum += nums[j];
        tempSum -= nums[i];
        if (tempSum > sum)
        {
            sum = tempSum;
        }
    }

    return (double)sum/k;
}

int main(void)
{
    int nums[] = {1, 12, -5, -6, 50, 3};
    findMaxAverage(nums, sizeof(nums) / sizeof(int), 4);
    return 0;
}