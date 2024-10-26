//
// Created by villi on 10/26/2024.
//


#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* mergeAlternately(char* word1, char* word2)
{
    char* result = (char*)malloc((strlen(word1) + strlen(word2) + 1) * sizeof(char));

    int k = 0;

    int i;
    for (i = 0; i < (strlen(word1) < strlen(word2) ? strlen(word1) : strlen(word2)); i++)
    {
        result[k++] = word1[i];
        result[k++] = word2[i];
    }
    for (int j = i; j <= (strlen(word1) > strlen(word2) ? strlen(word1) : strlen(word2)); j++)
    {
        result[k++] = (strlen(word1) > strlen(word2) ? word1[j] : word2[j]);
    }

    return result;
}

int main(void)
{
    char word1[] = "abc";
    char word2[] = "pqr";

    char* result = mergeAlternately(word1, word2);

    printf("%s\n", result);

    assert(strcmp(result, "apbqcr") == 0);

    free(result);
}
