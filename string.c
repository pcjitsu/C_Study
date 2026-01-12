#include <stdlib.h>
#include <stdio.h>

char str[] = "ARE WE THERE YET";
char *sp = str;

int size = sizeof(str) / sizeof(str[0]);

int main()
{
    printf("%s\n", str);

    for (; sp < &str[size]; sp++)
    {
        printf("%c", *sp);
    }
}