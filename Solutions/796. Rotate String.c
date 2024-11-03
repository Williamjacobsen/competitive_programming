//
// Created by villi on 11/3/2024.
//
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool rotateString(char* s, char* goal)
{
    int len = strlen(s)*2;
    if (strlen(goal) != len/2)
        return false;

    char temp[len+1];
    strcpy(temp, s);
    strcat(temp, s);

    int i = 0;
    int j = 0;
    int streakStart = -1;

    while (i < len)
    {
        if (temp[i] == goal[j])
        {
            if (streakStart == -1)
            {
                streakStart = i;
            }
            j++;
        }
        else
        {
            if (j != 0)
            {
                if (j == len/2)
                {
                    return true;
                }
                i = streakStart;
                streakStart = -1;
                j = 0;
            }
        }
        i++;
    }

    return false;
}


int main(void)
{
    bool result = rotateString("cccdd", "ccddc");

    // bbbacddceeb * 2 =
    // bbbacddceebbbbacddceeb
    //        ceebbbbacdd

    // defdefabcabcdefdefdefabcabcdef
    //                defdefabcabcdef

    // cccddcccdd
    //  ccddc

    printf("\n\n%d\n", result);

    return 0;
}

