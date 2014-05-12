/**************************************************
*caesar.c
*
*Written by Chris Gunby
*
*Write a program that encrypts using Caesar Cypher
***************************************************/



#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



 
 int main(int argc, string argv[])
 {
    //Verify the user has inputed only two command line arguments.
    if (argc != 2 )
    {
        printf("\nPlease re-run and enter only one positive integer as a key at the command line. \n\n");
        return 1;
    }
    
    //Convert user Key into an integer and declare string. 
    int k = atoi(argv[1]);
    string plainText;
    
    //Promt the user for the text they wish to cypher.
    do
    {
        //printf("Enter cypher text: ");
        plainText = GetString();
    }
    while(strlen (plainText) < 1); 
    
    
    // This loop repeats upto the length of the users input preserving case.
    for(int i = 0; i < strlen(plainText); i++)
    {
        if(isalpha(plainText[i]) && isupper(plainText[i]))
        {
  
            //Change individual letters into integers
            int aski = (char) plainText[i];
            //Convert ascii value into alphabetical index
            int alphIn = aski - 65;
            //Modulo each character to wrap around alphabet
            int cyI = (alphIn + k) % 26;
            //Convert back into ascii value for printing
            char cypherText = (int) cyI + 65;
            //Print final Cypher text
            printf("%c", cypherText);
        }
        else if (isalpha(plainText[i]) && islower(plainText[i]))
        {
             //Change individual letters into integers
            int aski = (char) plainText[i];
            //Convert ascii value into alphabetical index
            int alphIn = aski - 97;
            //Modulo each character to wrap around alphabet
            int cyI = (alphIn + k) % 26;
            //Convert back into ascii value for printing
            char cypherText = (int) cyI + 97;
            //Print final Cypher text
            printf("%c", cypherText); 
        }
        else
        {
            printf("%c", plainText[i]);
        }
    
    }
    
    printf("\n");
 
}
