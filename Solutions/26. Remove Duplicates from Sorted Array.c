//
// Created by villi on 10/30/2024.
//

#include <stdio.h>
#include <stdlib.h>

int removeDuplicates(int* nums, int numsSize)
{
    int k = 1;
    for (int i = 1; i < numsSize; i++)
    {
        if (nums[i-1] != nums[i])
        {
            nums[k++] = nums[i];
        }
    }

    return k;
}

int main(void)
{
    int nums[] = {0,0,1,1,1,2,2,3,3,4};
    int numsSize = sizeof(nums) / sizeof(int);

    int result = removeDuplicates(nums, numsSize);

    printf("%d\n", result);
    for (int i = 0; i < numsSize; i++)
    {
        printf("%d ", nums[i]);
    }

    return 0;
}

