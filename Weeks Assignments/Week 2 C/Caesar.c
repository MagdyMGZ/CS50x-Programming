#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


// main function takes 2 arguments, first one takes number of arguments, and the second one takes an array of strings (KEY)
int main(int argc, string argv[])
{
    if (argc != 2)
    {
        // Check that there is one command-line argument
        printf("Usage: ./ceasar Key\n");
        return 1;
    }
    // Check that the input is a Digit
    // checking if one of the arguments isalpha (we need an integer) - Looping through the string of integers
    for (int key = 0; key < strlen(argv[1]); key++)
    {
        if (isalpha(argv[1][key]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    // Define The Key
    int key = atoi(argv[1]) % 26; // converts the ASCII to an integer from "20" to 20 as an interger

    // takes the plaintext from the user
    string plaintext = get_string("plaintext: ");

    printf("ciphertext: ");
    // Optain Ciphertext
    // iterates over the plain text with a for loop
    for (int i = 0 ; i < strlen(plaintext) ; i++)
    {
        if (isupper(plaintext[i]))
        {
            printf("%c", (((plaintext[i] - 65) + key) % 26) + 65);
        }
        else if (islower(plaintext[i]))
        {
            printf("%c", (((plaintext[i] - 97) + key) % 26) + 97);
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
    return 0;
}