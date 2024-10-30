//
// Created by villi on 10/30/2024.
//


#include <stdint.h>
#include <stdio.h>

int reverse(int64_t x)
{
    int64_t rev = 0;
    int digit;
    while (x != 0)
    {
        digit = x % 10;
        rev = rev * 10 + digit;
        x = x / 10;
    }

    if (rev > INT32_MAX || rev < INT32_MIN)
    {
        return 0;
    }

    return rev;
}

int main(void)
{
    int result = reverse(-321);

    printf("\n%d\n", result);

    return 0;
}

