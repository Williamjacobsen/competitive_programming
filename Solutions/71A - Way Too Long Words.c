//
// Created by villi on 10/25/2024.
//

#include <stdio.h>
#include <string.h>

int main(void)
{
    int n;
    scanf("%d", &n);

    char result[n][11];

    for (int i = 0; i < n; i++)
    {
        char input[100];
        scanf("%s", &input);
        if (strlen(input) > 10)
        {
            char temp[100];
            snprintf(temp, 100, "%c%d%c", input[0], strlen(input)-2, input[strlen(input)-1]);
            strcpy(result[i], temp);
            continue;
        }
        strcpy(result[i], input);
    }

    for (int i = 0; i < n; i++)
    {
        printf("%s\n", result[i]);
    }

    return 0;
}
