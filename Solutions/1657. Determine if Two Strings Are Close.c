//
// Created by villi on 11/9/2024.
//

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a , const void *b){
    return *(int*)a - *(int*)b;
}

bool closeStrings(char* word1, char* word2)
{
    int len1 = strlen(word1);
    int len2 = strlen(word2);

    if (len1 != len2)
        return false;

    int alphabetCoverage1[26] = {0};
    int alphabetCoverage2[26] = {0};

    for (int i = 0; i < len1; i++)
        alphabetCoverage1[word1[i] - 'a']++;

    for (int i = 0; i < len2; i++)
        alphabetCoverage2[word2[i] - 'a']++;

    for (int i = 0; i < 26; i++)
    {
        //if (alphabetCoverage1[i] > 0 && alphabetCoverage2[i] == 0)
        //    return false;
        //if (alphabetCoverage1[i] == 0 && alphabetCoverage2[i] > 0)
        //    return false;
        if (alphabetCoverage1[i] > 0 && alphabetCoverage2[i] > 0)
        {
            if (alphabetCoverage1[i] > alphabetCoverage2[i])
            {

            }
            else if (alphabetCoverage1[i] < alphabetCoverage2[i])
            {

            }
        }
    }

    qsort(alphabetCoverage1,26,sizeof(int),cmp);
    qsort(alphabetCoverage2,26,sizeof(int),cmp);
    int i = 0;
    while(i < 26 && alphabetCoverage1[i] == alphabetCoverage2[i]) i++;
    return i == 26;
}

int main(void)
{
    closeStrings("cabbba", "abbccc");
    return 0;
}