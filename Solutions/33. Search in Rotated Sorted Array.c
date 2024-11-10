//
// Created by villi on 11/10/2024.
//

#include <stdio.h>

int search(int* nums, int numsSize, int target)
{
    int l = 0;
    int r = numsSize - 1;

    while (l <= r)
    {
        int m = (l + r) / 2;
        printf("%d ", nums[m]);

        if (nums[m] == target)
            return m;

        if (nums[l] <= nums[m])
        {
            if (nums[l] <= target && target <= nums[m])
            {
                r = m - 1;
            }
            else
            {
                l = m + 1;
            }
        }
        else
        {
            if (nums[m] <= target && target <= nums[r])
            {
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }
    }

    return -1;
}

int main(void)
{
    int nums[] = {4,5,6,7,0,1,2};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int target = 0;
    int result = search(nums, numsSize, target);
    printf("\n%d\n", result);
    return 0;
}
