//
// Created by villi on 10/30/2024.
//

#include <stdio.h>

void moveZeroes(int* nums, int numsSize)
{
    // beats 10%
    /*for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] != 0)
        {
            continue;
        }
        int k = i;
        for (int j = i + 1; j < numsSize; j++)
        {
            if (nums[j] == 0)
            {
                continue;
            }
            int temp = nums[k];
            nums[k] = nums[j];
            nums[j] = temp;
            k = j;
        }
    }*/

    // beats 100%
    int j = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] != 0)
        {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            j++;
        }
    }
}

int main(void)
{
    int nums[] = {0,0,1};
    int numsSize = sizeof(nums) / sizeof(int);
    moveZeroes(nums, numsSize);

    for (int i = 0; i < numsSize; i++)
    {
        printf("%d ", nums[i]);
    }

    return 0;
}
