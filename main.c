
#ifndef bool
#define bool int
#define true 1
#define false 0
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

bool uniqueOccurrences(int* arr, int arrSize)
{
    const int offset = 1000;
    int count[2001] = {0};
    for (int i = 0; i < arrSize; i++) {
        count[arr[i] + offset]++;
    }

    qsort(count, 2001, sizeof(int), compare);

    for (int i = 0; i < 2001 - 1; i++) {
        if (count[i] > 0) {
            if (count[i] == count[i+1]) {
                return false;
            }
        }
    }

    return true;
}

#include <stdlib.h>

int cmpf(const void* a, const void* b){
    return (*(int*)a - *(int*)b);
}

bool somehowFaster(int* arr, int arrSize) {
    qsort(arr, arrSize, sizeof(int), cmpf);

    int counts[arrSize];
    int countsSize = 0;

    for (int i = 0; i < arrSize;) {
        int count = 1;
        while (i + 1 < arrSize && arr[i] == arr[i + 1]) {
            count++;
            i++;
        }
        counts[countsSize++] = count;
        i++;
    }

    qsort(counts, countsSize, sizeof(int), cmpf);
    for (int i = 1; i < countsSize; i++) {
        if (counts[i] == counts[i - 1]) {
            return false;
        }
    }
    return true;
}

int main(void)
{
    int arr[] = {-3,0,1,-3,1,1,1,-3,10,0};
    uniqueOccurrences(arr, sizeof(arr) / sizeof(int));
    return 0;
}