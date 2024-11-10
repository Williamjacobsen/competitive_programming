//
// Created by villi on 11/10/2024.
//

#include <stdio.h>

int findMin(int* nums, int numsSize)
{
    int l = 0;
    int r = numsSize - 1;
    int m;

    while (l < r)
    {
        m = (l + r) / 2;

        if (nums[m] <= nums[r])
        {
            r = m;
        }
        else if (nums[m] > nums[r])
        {
            l = m + 1;
        }
    }

    return nums[l];
}

int main(void)
{
    int nums[] = {5,1,2,3,4};
    int numsSize = sizeof(nums) / sizeof(int);
    int min = findMin(nums, numsSize);
    printf("\n%d\n", min);
    return 0;
}