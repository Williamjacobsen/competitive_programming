//
// Created by villi on 10/25/2024.
//


#include <stdio.h>
#include <string.h>

int main(void)
{
    int q;
    scanf("%d", &q);

    int res[q];

    for (int i = 0; i < q; i++)
    {
        char s[101], t[101];
        scanf("%s", s);
        scanf("%s", t);

        int temp = 0;

        int j;
        for (j = 0; j < (strlen(s) < strlen(t) ? strlen(s) : strlen(t)); j++)
        {
            if (s[j] == t[j])
            {
                temp++;
            }
            else
            {
                if (j == 0)
                {
                    temp--;
                }
                break;
            }
        }
        temp += strlen(s) - j + strlen(t) - j + 1;

        res[i] = temp;
    }

    for (int i = 0; i < q; i++)
    {
        printf("%d\n", res[i]);
    }

    return 0;
}

