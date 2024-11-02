//
// Created by villi on 11/2/2024.
//

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool isCircularSentence(char* sentence)
{
    int len = strlen(sentence);

    char endChar = '\0';

    char currChar;
    char prevChar = '\0';

    for (int i = 0; i < len; i++)
    {
        currChar = sentence[i];

        if (endChar == '\0')
        {
            if (currChar == ' ' || currChar == '\0')
            {
                endChar = prevChar;
            }
        }
        else if (prevChar == ' ')
        {
            if (currChar == endChar)
            {
                //printf("end %c\n", endChar);
                //printf("curr %c\n", currChar);
                endChar = '\0';
            }
            else
            {
                return false;
            }
        }

        prevChar = currChar;
    }

    if (sentence[0] != sentence[len - 1])
    {
        return false;
    }

    return true;
}

int main(void)
{

    bool result = isCircularSentence("leetcode exercises sound delightful");

    printf("%d\n", result);

    return 0;
}