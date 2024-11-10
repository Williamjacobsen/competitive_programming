//
// Created by villi on 11/10/2024.
//

#include <stdio.h>

int search(int* nums, int numsSize, int target)
{
    int l = 0;
    int r = numsSize;
    int m = 0;

    while (l < r)
    {
        m = (l + r)/2;
        if (nums[m] > target)
        {
            r = m;
        }
        else if (nums[m] < target)
        {
            l = m + 1;
        }
        else
        {
            return m;
        }
    }
    return -1;
}

int main(void)
{
    int nums[] = {-1,0,3,5,9,12};
    search(nums, sizeof(nums)/sizeof(int), 9);
    return 0;
}
