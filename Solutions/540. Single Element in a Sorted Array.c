//
// Created by villi on 11/16/2024.
//
#include <stdio.h>

int singleNonDuplicate(int* nums, int numsSize)
{
    if (numsSize == 1)
    {
        return nums[0];
    }

    int l = 0, r = numsSize - 1, m = 0;

    while (l < r)
    {
        m = (l + r) / 2;

        //printf("a: %d\n", m+1);
        //printf("b: %d\n", (m+1)%2);

        if (m == 0 || m == numsSize-1 || nums[m] != nums[m-1] && nums[m] != nums[m+1])
        {
            //printf("%d\n", nums[m]);
            return nums[m];
        }

        if ((m+1) % 2 == 1)
        {
            if (nums[m] != nums[m-1])
            {
                l = m + 1;
            }
            else
            {
                r = m;
            }
        }
        else
        {
            if (nums[m] == nums[m-1])
            {
                l = m + 1;
            }
            else
            {
                r = m;
            }
        }
    }

    return nums[r];
}

int main(void)
{
    int nums[] = {1,2,2,3,3};
    int numsSize = sizeof(nums)/sizeof(int);
    int res = singleNonDuplicate(nums, numsSize);
    printf("res: %d\n", res);
    return 0;
}
