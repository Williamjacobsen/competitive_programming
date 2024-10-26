//
// Created by villi on 10/26/2024.
//


#include <stdio.h>
#include <string.h>

int main(void)
{
    int n;
    scanf("%d", &n);

    int x = 0;

    for (int i = 0; i < n; i++)
    {
        char statement[4];
        scanf("%s", &statement);

        for (int j = 0; j < strlen(statement) - 1; j++)
        {
            if (statement[j] == '+' && statement[j+1] == '+')
            {
                x++;
            }
            else if (statement[j] == '-' && statement[j+1] == '-')
            {
                x--;
            }
        }
    }

    printf("%d", x);

    return 0;
}
