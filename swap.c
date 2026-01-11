#include <stdlib.h>
#include <stdio.h>

void swap(int, int);

int main()
{
    int a = 21;
    int b = 22;
    swap(a, b);
    printf("main: a = %d, b = %d\n", a, b);
    return EXIT_SUCCESS
};