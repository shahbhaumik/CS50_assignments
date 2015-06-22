/*
Created by Bhaumik Shah

CS50 Week 2 assignment Vigenere's cipher
Used codeblocks with GCC compiler
To make it C99 standard
goto-> Project -> Build properties -> Compiler -> Other
add "-std=c99"
To include CS50 library
Go under linker and add the lib manually

This project expects user to enter key, while starting the program,
In code blocks its is under program-> Program argument.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>

/* The name of the variable argc stands for "argument count"; argc contains the number of arguments passed to the program.
The name of the variable argv stands for "argument vector".
A vector is a one-dimensional array, and argv is a one-dimensional array of strings.
Each string is one of the arguments that was passed to the program.*/

int main(int argc, string argv[])   // Asking user to to pass an argument while callling this program to run
{

  if (argc != 2)                    // Check if argument is valid
    {
        printf("Usage : %s <Key>\n", argv[0]); // agrv[0] is the 1st fixed argument, which is calling the function
        return 1;                   // return 2 if the argument is not present
    }
    string Key = argv[1];

    for (int i=0, k = strlen(Key); i<k;i++)      //Checking if key is valid, a valid key is alphabetic
    {
        int j = isalpha(Key[i]);            //isalpha is to check if the key is alphabetic
        if (j == false){
        printf("Key invalid");
        return 2;                       //Return 2 if the key was not valid
        }

    }
    printf("Key is valid\n");

    printf("Enter your text and press enter \n");

     string Usertxt;                //Get a valid string from the user
     do
     {
     Usertxt=GetString();

     }while (Usertxt==NULL);
    int l =0;                       // just so k[i] does not increment with i.
      for (int i=0, len= strlen(Usertxt); i<len;i++){         //Encrypt the given text
       int j;
       int k = strlen(Key);
       j = l %  k;
       if (islower(Usertxt[i]) && islower(Key[j]))  {                         //check if the user txt is upper case or lower case and adjusting the key accordingly, all the 4 cases are listed
            Usertxt[i]= ( (Usertxt[i] - 'a'+ Key[j] - 'a') % 26) + 'a';  // Normalise the character as Ascii numbers are not from 0
            l++;
            }
        else if (isupper(Usertxt[i]) && isupper(Key[j])){
             Usertxt[i]= ( (Usertxt[i] - 'A'+ Key[j] - 'A') % 26) + 'A';
             l++;
             }
        else if (islower(Usertxt[i]) && isupper(Key[j])) {
             Usertxt[i]= ( (Usertxt[i] - 'a'+ Key[j] - 'A') % 26) + 'a';
             l++;
             }
        else if (isupper(Usertxt[i]) && islower(Key[j])) {
             Usertxt[i]= ( (Usertxt[i] - 'A'+ Key[j] - 'a') % 26) + 'A';
             l++;
             }
        else
            Usertxt[i] = Usertxt[i];                // print numbers and symbol as it is
    }

    printf("%s\n", Usertxt);                        // print the encrpted txt
    return 0;

    }

