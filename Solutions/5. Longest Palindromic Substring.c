//
// Created by villi on 10/30/2024.
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*char* reverseString(char* s, int len)
{
    char* temp = (char*)malloc((len + 2) * sizeof(char));
    int tempIndex = 0;
    for (int i = len; i >= 0; i--)
    {
        temp[tempIndex++] = s[i];
    }
    temp[tempIndex] = '\0';
    return temp;
}

int isPalindrome(char* s, int len)
{
    char* reversed = reverseString(s, len);
    //printf("\ns: %s\n", s);
    //printf("r: %s\n", reversed);
    int isSame = strcmp(s, reversed) == 0;
    free(reversed);
    return isSame;
}

char* longestPalindrome(char* s)
{
    int len = strlen(s);

    char temp[len+1];
    int tempIndex = 0;
    memset(temp, 0, sizeof(temp));

    //int count = 0;
    int result = 0;
    char* resultString = (char*)malloc((len+1)*sizeof(char));

    for (int i = 0; i < len; i++)
    {
        for (int j = i; j < len; j++)
        {
            temp[tempIndex++] = s[j];
            temp[tempIndex] = '\0';
            //count++;

            if (isPalindrome(temp, j-i))
            {
                //printf("%s\n", temp);


                //printf("%d\n", strlen(temp) > strlen(resultString));
                if (j-i > result)
                {
                    //printf("%d\n", result);
                    result = j-i;
                    strcpy(resultString, temp);
                }
            }
        }
        //count = 0;
        tempIndex = 0;
        memset(temp, 0, sizeof(temp));
    }

    return resultString;
}*/

void expandingWindow(int l, int r, int len, char* s, int *longest, int *bestL, int *bestR)
{
    int count = 0;

    while (l >= 0 && r < len && s[l] == s[r])
    {
        if (l != r)
        {
            count += 2;
        }
        else
        {
            count++;
        }
        l--;
        r++;
    }

    if (count > *longest)
    {
        *longest = count;
        *bestL = l++;
        *bestR = r--;
    }
}


char* longestPalindrome(char* s)
{
    int len = strlen(s);

    int longest = 0;
    int bestL = 0;
    int bestR = 0;

    for (int i = 0; i < len; i++)
    {
        expandingWindow(i, i, len, s, &longest, &bestL, &bestR);
        expandingWindow(i, i+1, len, s, &longest, &bestL, &bestR);
    }

    char* result = (char*)malloc(sizeof(char) * (bestR - bestL+1 + 1));
    int i;
    for (i = bestL+1; i < bestR; i++)
    {
        result[i - bestL-1] = s[i];
    }
    result[i-bestL-1] = '\0';

    return result;
}



int main(void)
{
    clock_t start, end;
    double time_taken;

    start = clock();
    char* result = longestPalindrome("tfekavrnnptlawqponffseumswvdtjhrndkkjppgiajjhklqpskuubeyofqwubiiduoylurzlorvnfcibxcjjzvlzfvsvwknjkzwthxxrowidmyudbtquktmyunoltklkdvzplxnpkoiikfijgulbxfxhaxnldvwmzpgaiumnvpdirlrutsqenwtihptnhghobrmmzcsrhqgdgzrvvitzgsolsxjxfeencvpnltxeetmtzlwnhlvgtbhkicivylfjhhfqteyxewmnewhmsnfdyneqoywgsgptwdlzbraksgajciebdchindegdfmayvfkwwkkfyxqjcv");
    end = clock();

    printf("\n\n%s\n", result);

    time_taken = ((double)(end - start) / CLOCKS_PER_SEC) * 1000.0;

    printf("Time taken by function: %.2f ms\n", time_taken);


    free(result);

    return 0;
}





