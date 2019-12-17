/*
Christopher McGrath
CSCI 230 hw convert.c
9/3/2019
*/
#include <stdio.h>
#include <string.h> //needed for strings and strtol function

long int strtol(const char *string, char **endpointer, int baseNum); //Declaration of strtol function used later

char returnCharacter(int num) //return a character for a number i.e. '2' for 2
{ 
    if (num >= 0 && num <= 9) //Make sure the number is only a digit, so that a character can be returned
        return (char)(num + '0'); 
} 

void reverseString(char *string) //Function to reverse a string, reverse the remainders gathered into "conversion" from the while loop
{ 
    int length = strlen(string); //use of strlen to initialize length
    int j; 
    for (j = 0; j < length/2; j++) //for loop used to reverse string
    { 
        char temp = string[j]; 		 //store each element of the string into temp
        string[j] = string[length-j-1];  //each element of string is assigned the element of corresponding length from the end of the string
        string[length-j-1] = temp; 	 //Starting at the back of the orignal string, the elements are assigned the corresponding elements
    } 					 //from the start of the orignal string, stored in temp
} 


int main( int argc, char *argv[] )
{
    
    char conversion[100]; 
    int baseTen = 0, baseX = 0,i = 0,storebaseTen=0,storebaseX=0;
    
    baseTen = strtol(argv[1], NULL, 10);	//strtol function used to make the arguments from the command line integers
    baseX = strtol(argv[2], NULL, 10);
    storebaseTen = baseTen;			//store the value for the first argument from the command line
    storebaseX = baseX;				//store the value for the second argument from the command line

    if((baseTen<0)||(baseX<0)){			//check to make sure the arguments are positive
    printf("Output:  Error! You entered the negative number!\n");
    return 0;
    }
    
    while (baseTen > 0) 					//while baseTen can still be divided by baseX
    {
        conversion[i++] = returnCharacter(baseTen % baseX);     //add the remainder from baseTen/baseX to the string conversion
        baseTen = baseTen / baseX; 				//set baseTen to the quotient of itself divided by baseX
    }
    conversion[i] = '\0'; 		//Set the last element of conversion as the terminating character
    reverseString(conversion);		//reverse the string of remainders, equation for diving a number by baseTen calls for this
    
    printf("Output:  (%d)10=(%s)%d\n", storebaseTen, conversion, storebaseX); //print the desired output
    return 0;
}
   
