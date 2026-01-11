#include <stdlib.h>
#include <stdio.h>

int a[10], *p, d, size;

int main()
{
    // Divide by the size of the int to get element amount of a
    size = sizeof(a) / sizeof(a[0]);
    // pointer is assigned to the array which is a pointer so this is a pointer to the start of the array
    p = a;
    // setting the value of the first value to 10;
    a[0] = 10;

    // Showing either selecting the dereferenced p pointer at start of arrya or first element in array print the same thing which is 10
    printf("%d\n", a[0]);
    printf("%d\n", *p);

    // Using pointer arithmetic move the pointer P one element down the array and change the value to 14
    *++p = 14;
    // Show by printing that a one element over is 14;
    printf("%d\n", a[1]);

    printf("\n");

    // Bring p back to start of a;
    p--;

    // move through where current p is pointed at until less than the address of a;
    for (; p < &a[size]; p++)
    {
        *p = 4;
    }
    // print out the values;
    for (int i = 0; i < size; i++)
    {
        printf("%d", a[i]);
    }

    return 0;
}