/*
Christopher McGrath
CSCI 230 hw prime_generate.c
9/2/2019
*/

#include <stdio.h>

int main(void)
{
    
    int lowerBound = 0, upperBound = 0;
    
    printf("Enter lower bound:\n");
    scanf("%d",&lowerBound);
    
    printf("Enter upper bound:\n");
    scanf("%d",&upperBound);
    
    int flag = 0, i = 0, check = 2;
    
    printf("The prime numbers between %d and %d are:", lowerBound, upperBound);
    for(i = lowerBound+1; i < upperBound; i++)
    {
        flag = 0;                           //flag is set to zero for every new value of i
        for(check = 2; check < i; check++)
        {                                   //iterates through every number from two to (i-1)
        
            if(i%check==0)                  //if i is divisible by a number from two to (i-1)  
            break;                          //Then i isn't prime, the for loop is exited, and i is increased 
            flag++;                         //if i is not divisible by a number from two to (i-1)
                                            //then flag is incremented
        }
        if(flag==i-2)                       //if i was not divisible by any of the numbers from two to (i-1)
        printf("%d, ",i);                   //then i is prime, and we print it
    }    
    printf("\n");
    return 0;
}
