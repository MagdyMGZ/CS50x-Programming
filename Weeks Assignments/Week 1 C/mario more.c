#include <stdio.h>
#include <cs50.h>
int main(void)
{
    // variable
    int num;
    // for input value from 1 to 8
    do
    {
        num = get_int("enter a positive number: ");
    }
    while (num <= 0 || num > 8);
    // nested loops
    // first make rows loop
    for (int i = 0 ; i < num ; i++)
    {   
        // second make space loop
        for (int j = num - 1 ; j > i ; j--)
        {
            printf(" ");
        }
        // third make the first pyramid loop
        for (int k = 0 ; k <= i ; k++)
        {
            printf("#");
        }
        // fourth make the gap loop
        printf("  ");
        for (int m = 0 ; m <= i ; m++)
        {
            // fifth make the second pyramid loop
            printf("#");
        }
        printf("\n");
    }
}