/*

Created by Bhaumik Shah

CS50 Week 1 assignment
Used codeblocks with GCC compiler
To make it C99 standard
goto-> Project -> Build properties -> Compiler -> Other
add "-std=c99"
To include CS50 library
Go under linker and add the lib manually

*/


#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>


int main()
{   int height;
    do  {
        printf("Enter an integer, whoes value is in between 0 to 9. \n");  //ask for the the height
        height = GetInt();                                                 //get user specified height
        printf("Value of a is %d\n", height);                              // printing the height
        } while (height<0 || height>9);                                    // Checking if it is within the boundries

    for (int row=1; row <= height; row++)                                  // Foop to create the pyramid, for loop iterates from 1 to height
    {
        for (int spaces=0; spaces <= height - row; spaces++)               // Number of spaces is equal to Height-Current row number
            printf (" ");
        for (int hashes =1; hashes <= row; hashes++)                       // Number of hash are equal to number of row
            printf ("#");
        printf("   ");
        for (int inv_hashes =1; inv_hashes <= row; inv_hashes++)          // Number of inv_hash are equal to number of row
            printf ("#");
    printf("\n");                                                         // Next line
    }
    return 0;

}
