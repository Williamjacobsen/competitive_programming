//
// Created by villi on 10/25/2024.
//

#include <stdio.h>

int main(void)
{
    int w;
    scanf("%d", &w);
    printf("%s\n", (w > 2 && w % 2 == 0) ? "YES" : "NO");
    return 0;
}
