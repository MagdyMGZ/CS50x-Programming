#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // Check that there is one command-line argument
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // Validate that the key consists only of alphabets
    string key = argv[1];
    for (int i = 0 ; i < strlen(key) ; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }
    }

    // Validate that the key consists of 20 Characters
    if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    // Validate that each alphabet in the key is Unique
    for (int i = 0 ; i < strlen(key) ; i++)
    {
        for (int j = i + 1 ; j < strlen(key) ; j++)
        {
            if (toupper(key[i]) == toupper(key[j]))
            {
                printf("Usage: ./substitution key\n");
                return 1;
            }
        }
    }

    // Prompt user for the Plaintext
    string plaintext = get_string("plaintext: ");

    // Convert all alphabets in the key to Uppercase
    for (int i = 0 ; i < strlen(key) ; i++)
    {
        if (islower(key[i]))
        {
            key[i] = key[i] - 32;
        }
    }

    // Print the Ciphertext
    printf("ciphertext: ");

    // Check for each alphabet in the plaintext
    for (int i = 0 ; i < strlen(plaintext) ; i++)
    {
        if (isupper(plaintext[i]))
        {
            int letter = plaintext[i] - 65;
            printf("%c", key[letter]);
        }
        else if (islower(plaintext[i]))
        {
            int letter = plaintext[i] - 97;
            printf("%c", key[letter] + 32);
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
    return 0;
}