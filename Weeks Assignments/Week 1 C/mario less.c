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
    for (int i = 0 ; i < num ; i++)
    {
        for (int j = num - 1 ; j > i ; j--)
        {
            printf(" ");
        }
        for (int k = 0 ; k <= i ; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}