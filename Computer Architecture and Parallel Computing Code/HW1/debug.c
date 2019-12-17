/*
Christopher McGrath
CSCI 230 hw debug.c 
9/3/2019
*/
#include <stdio.h>

int main()
{
    char checkPreceeding = 'a';
    char word[80];
    int i,j;
    
    printf("Enter any word: ");
    scanf("%s",word);
    i = 0;
    j = 0;
    
    while (word[i] != '\0')
      {
        if (word[i] == word[i+1])
          {
            j = 1;
            while(word[i] == word [i+j])
            j++;
            checkPreceeding = word[i-1];
            if(checkPreceeding!=word[i])
            printf("%d consecutive %c\n",j--, word[i]); 
          }
        i++;
      }
       
  return 0;
}
