//
// Created by villi on 11/16/2024.
//

#include <stdio.h>

unsigned long long canKokoEatPiles(int* piles, int pilesSize, int h, int speed)
{
    //printf("speed: %d\n", speed);
    unsigned long long eaten = 0;
    for (int i = 0; i < pilesSize; i++)
    {
        eaten += (piles[i] + speed - 1) / speed;
    }
    return eaten;
}

int minEatingSpeed(int* piles, int pilesSize, int h)
{
    int max = 0;
    for (int i = 0; i < pilesSize; i++)
        if (piles[i] > max)
            max = piles[i];
    //printf("max = %d\n", max);


    int l = 0, r = max, m = 0;
    while (l < r)
    {
        int m = (l + r) / 2;

        if (m == 0)
        {
            return 1;
        }

        unsigned long long state = canKokoEatPiles(piles, pilesSize, h, m);

        //printf("%llu, %d\n", state, m);

        if (state <= h)
        {
            r = m;
        }
        else
        {
            l = m + 1;
        }
    }

    //printf("%d\n", l);
    return l;
}

int main(void)
{
    int piles[] = {805306368,805306368,805306368};
    int pilesSize = sizeof(piles) / sizeof(piles[0]);
    int res = minEatingSpeed(piles, pilesSize, 1000000000);
    return res;
}