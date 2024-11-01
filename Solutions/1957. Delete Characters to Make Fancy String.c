//
// Created by villi on 11/1/2024.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* makeFancyString(char* s)
{
    int len = strlen(s);
    char* result = (char*)malloc((len + 1) * sizeof(char));
    int j = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (j-2 >= 0 && result[j-2] == s[i] && result[j-1] == s[i])
        {
            continue;
        }
        result[j++] = s[i];
    }
    result[j] = '\0';

    return result;
}

int main(void)
{
    char* result = makeFancyString("aaabaaaa");

    printf("%s\n", result);

    free(result);
    return 0;
}