//
// Created by villi on 11/6/2024.
//

#include <stdio.h>

int longestSubarray(int* nums, int numsSize)
{
    int l;
    for (l = 0; l < numsSize; l++)
    {
        if (nums[l] == 1)
        {
            break;
        }
    }
    if (l == numsSize)
    {
        return 0;
    }

    int r = l + 1;

    int count = 1;
    int maxCount = count;
    int lastZeroIndex = -1;

    while (r < numsSize)
    {
        if (nums[r] == 1)
        {
            count++;
            r++;
        }
        else if (nums[r] == 0)
        {
            if (lastZeroIndex == -1)
            {
                lastZeroIndex = r;
                r++;
            }
            else
            {
                l = lastZeroIndex;
                r = l + 1;
                lastZeroIndex = -1;
                count = 0;
            }
        }
        if (maxCount < count)
        {
            maxCount = count;
        }
    }
    if (maxCount == numsSize)
    {
        return maxCount - 1;
    }
    return maxCount;
}


int main(void)
{
    int nums[] = {1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,0,1,0,1,1,1,1,1,1,0,1,1,1,1,0,1,1,1,1,1};
    int numsSize = sizeof(nums)/sizeof(int);
    int result = longestSubarray(nums, numsSize);
    printf("%d\n", result);
    return 0;
}