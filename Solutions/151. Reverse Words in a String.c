//
// Created by villi on 10/27/2024.
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* reverseWords(char* s) {
    int len = strlen(s);
    int m = 0;

    char** words = (char**)malloc((len + 1) * sizeof(char*));
    int k = 0;

    char* word = (char*)malloc((len + 1) * sizeof(char));
    int c = 0;

    int newLen = 0;

    for (int i = 0; i < len; i++)
    {
        if (s[i] != ' ')
        {
            word[c++] = s[i];
            if (i != len-1)
            {
                continue;
            }
        }
        if (c != 0)
        {
            word[c] = '\0';
            words[k] = (char*)malloc((c + 1) * sizeof(char));
            strcpy(words[k++], word);
            newLen += c;
            c = 0;
        }
    }
    free(word);

    int j = k-1;
    for (int i = 0; i < k/2; i++)
    {
        char* temp = words[j];
        words[j--] = words[i];
        words[i] = temp;
    }

    int total_length = 0;
    for (int i = 0; i < k; i++) {
        total_length += strlen(words[i]);
    }
    total_length += k - 1;
    char* result = (char*)malloc((total_length + 1) * sizeof(char));
    result[0] = '\0';

    for (int i = 0; i < k; i++) {
        strcat(result, words[i]);
        if (i < k - 1) {
            strcat(result, " ");
        }
    }

    free(words);
    return result;
}

int main(void)
{

    char* input = "    the   sky is   blue    ";

    char* result = reverseWords(input);

    printf("%s\n", result);
    free(result);
    return 0;
}