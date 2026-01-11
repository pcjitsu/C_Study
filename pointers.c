#include <stdlib.h>
#include <stdio.h>

int main()
{
    int x = 5;
    int *y = &x;
    printf("%x\n", *y);
    printf("/n");
    printf("-----------\n");
    printf("%p", y);
}