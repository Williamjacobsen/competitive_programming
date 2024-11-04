//
// Created by villi on 11/4/2024.
//

#include <stdio.h>

int isVowel(char ch)
{
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

int maxVowels(char* s, int k)
{
    int l = 0;
    int r = k;

    int count = 0;
    int maxCount = 0;

    for (int i = 0; i < k; i++)
    {
        if (isVowel(s[i]))
        {
            count++;
        }
    }

    maxCount = count;
    if (maxCount == k)
    {
        return k;
    }

    while (s[l] != '\0' && s[r] != '\0')
    {
        if (isVowel(s[l]))
        {
            count--;
        }

        if (isVowel(s[r]))
        {
            count++;
        }

        l++;
        r++;

        if (count > maxCount)
        {
            maxCount = count;
            if (maxCount == k)
                return k;
        }
    }

    return maxCount;
}

int main(void)
{
    maxVowels("abciiidef", 3);
    return 0;
}