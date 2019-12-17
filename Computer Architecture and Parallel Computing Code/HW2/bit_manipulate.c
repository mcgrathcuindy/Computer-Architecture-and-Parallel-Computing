/*
Christopher McGrath
CSCI 230 HW bit_manipulate.c
9/23/2019
*/

#include <stdio.h>


int main()
{
int num = 0, i;
int position = 0;
int userChoice;

while(1)
{
    printf("Your number in binary is ");

    for(i = 31; i >= 0; i--)
    {
        printf("%i", ((num & (1 << i))?1:0));
    }


    printf("\nSelect an option: (1) Set a bit, (2) Clear a bit, (3) Exit\n");
    scanf("%d", &userChoice);

    if(userChoice == 3)
        break;

    if(userChoice==1||userChoice==2)
    {
        printf("Which bit?\n");
        scanf("%d", &position);
    }
    if(userChoice ==1)
	num |= 1 << position;
    else if(userChoice ==2)
	num &= ~(1 << position);
    else
    {
	printf("Select a valid option please\n\n");
    }
}

    return 0;
}
