#include <stdlib.h>
#include <stdio.h>

static int out = 0;

int up(int n)
{
    if (n == 1 || n == 0)
    {
        out++;
        return n;
    }
    out++;
    printf("%d", out);
    return n + up(n - 1);
}

int main()
{
    int q = 5;
    int program = up(q);
    printf("%d", program);
    return 0;
}