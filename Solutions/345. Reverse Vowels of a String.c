//
// Created by villi on 11/4/2024.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* reverseVowels(char* s)
{
    int len = strlen(s);
    int l = 0;
    int r = len-1;
    char* result = (char*)malloc((len+1)*sizeof(char));

    while (l <= r)
    {
        //printf("%d %d %c %c\n", l, r, s[l], s[r]);
        result[l] = s[l];
        result[r] = s[r];
        if (
            s[l] != 'a' && s[l] != 'A' &&
            s[l] != 'e' && s[l] != 'E' &&
            s[l] != 'i' && s[l] != 'I' &&
            s[l] != 'o' && s[l] != 'O' &&
            s[l] != 'u' && s[l] != 'U'
            )
        {
            l++;
        }
        else if (
            s[r] != 'a' && s[r] != 'A' &&
            s[r] != 'e' && s[r] != 'E' &&
            s[r] != 'i' && s[r] != 'I' &&
            s[r] != 'o' && s[r] != 'O' &&
            s[r] != 'u' && s[r] != 'U'
            )
        {
            r--;
        }
        else
        {
            result[l] = s[r];
            result[r] = s[l];
            l++;
            r--;
        }
    }
    result[len] = '\0';

    printf("%s\n", result);

    return result;
}

int main(void)
{
    reverseVowels("IceCreAm");
    return 0;
}
