#include <stdio.h>
#include <cs50.h>
int main(void)
{
    //asking about user name to say hello to him
    string name = get_string("What's your name? ");
    printf("hello, %s\n", name);
}