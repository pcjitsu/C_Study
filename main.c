#include <stdio.h>
#include "bss.h"

int main()
{
    int myFavoriteNumber = strong;
    int myFavoriteNum;
    printf("Please enter your fav number");
    scanf("%d", &myFavoriteNum);
    printf("You entered : %d and also %d \n", myFavoriteNumber, myFavoriteNum);
    return 0;
}