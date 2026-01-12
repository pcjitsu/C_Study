#include <stdio.h>
#include <stdlib.h>
#include "mymath.h"

// gcc mymath.c struct.c -o mathstruct. <- Need t compile all related and dependent files

typedef struct
{
    int i;
    int d;
} test;
int sum;
test out = {3, 5};

int main()
{
    sum = add(out.i, out.d);
    printf("%d %d\n", out.i, out.d);
    printf("%d", sum);
    return 0;
}