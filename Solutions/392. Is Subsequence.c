//
// Created by villi on 11/4/2024.
//

#include <stdbool.h>

bool isSubsequence(char* s, char* t)
{
    int p = 0;
    int q = 0;

    while (s[p] != '\0' && t[q] != '\0')
    {
        if (s[p] == t[q])
        {
            p++;
        }
        q++;
    }
    return s[p] == '\0';
}

int main(void)
{
    isSubsequence("abc", "ahbgdc");
    return 0;
}
