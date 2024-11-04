//
// Created by villi on 11/4/2024.
//

#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return (*(int*)a - *(int*)b);
}

int maxOperations(int* nums, int numsSize, int k)
{
    qsort(nums, numsSize, sizeof(int), compare);

    int l = 0, r = numsSize - 1, count = 0;
    while (l < r)
    {
        if (nums[l] + nums[r] == k)
        {
            l++;
            r--;
            count++;
        }
        else if (nums[l] + nums[r] > k)
        {
            r--;
        }
        else
        {
            l++;
        }
    }
    return count;
}

int main(void)
{
    int nums[] = {1,2,3,4};
    maxOperations(nums, sizeof(nums) / sizeof(int), 5);
    return 0;
}