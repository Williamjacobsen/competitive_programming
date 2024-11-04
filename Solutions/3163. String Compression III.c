//
// Created by villi on 11/4/2024.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* compressedString(char* word)
{
    int len = strlen(word);
    char* compressedString = (char*)malloc((2 * len + 1) * sizeof(char));
    int k = 0;

    int count = 1;
    char prevChar = word[0];
    for (int i = 1; i < len; i++)
    {
        if (count < 9 && word[i] == prevChar)
        {
            count++;
        }
        else
        {
            compressedString[k++] = count + '0';
            compressedString[k++] = prevChar;
            prevChar = word[i];
            count = 1;
        }
    }
    compressedString[k++] = count + '0';
    compressedString[k++] = prevChar;
    compressedString[k] = '\0';

    //printf("\n%s\n", compressedString);

    return compressedString;
}

int main(void)
{
    compressedString("aaaaaaaaaaaaaabb");
    return 0;
}
