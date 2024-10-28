//
// Created by villi on 10/28/2024.
//


#include <stdbool.h>
#include <stdio.h>

bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    if (flowerbedSize >= 2)
    {
        if (flowerbed[0] == 0 && flowerbed[1] == 0)
        {
            n--;
            flowerbed[0] = 1;
        }
        if (flowerbed[flowerbedSize-2] == 0 && flowerbed[flowerbedSize-1] == 0)
        {
            n--;
            flowerbed[flowerbedSize-1] = 1;
        }
    }
    else if (flowerbedSize == 1 && flowerbed[0] == 0)
    {
        return true;
    }

    for (int i = 1; i < flowerbedSize-1; i++)
    {
        if (flowerbed[i] == 0 && flowerbed[i-1] == 0 && flowerbed[i+1] == 0)
        {
            n--;
            flowerbed[i] = 1;
        }
    }
    return n <= 0;
}

int main(void)
{
    int flowerbed[] = {0, 0, 1, 0, 1};
    int flowerbedSize = sizeof(flowerbed) / sizeof(flowerbed[0]);
    int n = 1;

    bool result = canPlaceFlowers(flowerbed, flowerbedSize, n);

    printf("%d\n", result);

    return 0;
}