#include <stdio.h>
#include <stdlib.h>

int d;
int m;
int y;
char in;

int main()
{
    printf("Enter a date: (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &m, &d, &y);
    getchar(); // Consume the leftover newline
    printf("\n");
    printf("You entered the date %d/%d/%d\n", m, d, y);
    in = getchar(); // Now this will wait for actual input
    printf("%c", in);
    return 0;
}