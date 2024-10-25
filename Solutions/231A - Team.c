//
// Created by villi on 10/25/2024.
//


#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);

    int res = 0;

    for (int i = 0; i < n; i++)
    {
        int temp = 0;

        int participants[3];
        scanf("%d %d %d", &participants[0], &participants[1], &participants[2]);

        for (int j = 0; j < 3; j++)
        {
            temp += participants[j];
        }
        if (temp >= 2)
        {
            res++;
        }
    }

    printf("%d\n", res);

    return 0;
}
