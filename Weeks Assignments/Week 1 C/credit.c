Old (2021)

#include <stdio.h>
#include <cs50.h>
int main(void)
{
    long credit;
    long credit_copy;
    int total_sum = 0, pos = 0, total_length = 0;
    do
    {
        credit = get_long("Enter Card Number : ");
        credit_copy = credit;
        while (credit != 0)
        {
            if (pos % 2 != 0)
            {
                // every other digit
                int temp = 2 * (credit % 10);
                if (temp > 9)
                {
                    total_sum += (temp % 10 + temp / 10);
                    // 12 => 1+2
                }
                else
                {
                    total_sum += temp;
                }
            }
            else
            {
                total_sum += credit % 10;
            }
            credit = credit / 10;
            pos++;
            total_length++;
        }
    }
    while (credit != 0);
    if (total_sum % 10 == 0)
    {
        // might be valid
        // 510510510510510
        // American express numbers start with 34 or 37, uses 15-digit numbers
        // mastercard numbers start with 52,52,53,54, or 55, uses 16-digit numbers
        // visa numbers start with 4, 13- and 16-digit numbers
        long amex_start = credit_copy / 10000000000000;
        // AMEX
        if ((amex_start == 34 || amex_start == 37) && total_length == 15)
        {
            printf("AMEX\n");
            return 0;
        }
        // Mastercards
        long master_card_start = credit_copy / 100000000000000;
        // printf("master_card_start = %ld", master_card_start);
        if ((total_length == 16) && (master_card_start >= 51 && master_card_start <= 55))
        {
            printf("MASTERCARD\n");
            return 0;
        }
        // VISA
        long visa_start = credit_copy / 1000000000000;
        // printf("visa_start = %ld", visa_start);
        if ((total_length == 16 || total_length == 13) && (visa_start == 4 || master_card_start / 10 == 4))
        {
            printf("VISA\n");
            return 0;
        }
        printf("INVALID\n");
    }
    else
    {
        printf("INVALID\n");
    }
}


New (2022)

#include <stdio.h>
#include <cs50.h>
int main(void)
{
    long card;
    do
    {
        card = get_long("Enter your card number: ");
    }
    while (card < 0); // card number must be greater than 0

    // select every alternate number, starting from the second - last digit
    // multiply each of these numbers by 2 then add these digits together
    // largest number of digits is 16

    int card1, card2, card3, card4, card5, card6, card7, card8;
    card1 = ((card % 100) / 10) * 2;
    card2 = ((card % 10000) / 1000) * 2;
    card3 = ((card % 1000000) / 100000) * 2;
    card4 = ((card % 100000000) / 10000000) * 2;
    card5 = ((card % 10000000000) / 1000000000) * 2;
    card6 = ((card % 1000000000000) / 100000000000) * 2;
    card7 = ((card % 100000000000000) / 10000000000000) * 2;
    card8 = ((card % 10000000000000000) / 1000000000000000) * 2;

    card1 = ((card1 % 100) / 10) + (card1 % 10);
    card2 = ((card2 % 100) / 10) + (card2 % 10);
    card3 = ((card3 % 100) / 10) + (card3 % 10);
    card4 = ((card4 % 100) / 10) + (card4 % 10);
    card5 = ((card5 % 100) / 10) + (card5 % 10);
    card6 = ((card6 % 100) / 10) + (card6 % 10);
    card7 = ((card7 % 100) / 10) + (card7 % 10);
    card8 = ((card8 % 100) / 10) + (card8 % 10);

    int sum1 = card1 + card2 + card3 + card4 + card5 + card6 + card7 + card8;

    // add this the sum of digits that werenot multiplied by 2 we need to find these numbers now

    int card9, card10, card11, card12, card13, card14, card15, card16;
    card9 = (card % 10);
    card10 = ((card % 1000) / 100);
    card11 = ((card % 100000) / 10000);
    card12 = ((card % 10000000) / 1000000);
    card13 = ((card % 1000000000) / 100000000);
    card14 = ((card % 100000000000) / 10000000000);
    card15 = ((card % 10000000000000) / 1000000000000);
    card16 = ((card % 1000000000000000) / 100000000000000);

    int sum2 = card9 + card10 + card11 + card12 + card13 + card14 + card15 + card16;

    int sum3 = sum1 + sum2;

    // if the last digit in sum3 is 0, the card is valid
    if ((sum3 % 10) != 0)
    {
        printf("%s\n", "INVALID");
        return 0;
    }
    // if valid, identify the type of credit card used
    // now we need to differentiate between VISA, Master And Amex

    int length = 0;
    long visa = card;
    long amex = card;
    long master = card;

    // count the number of digits in the card
    while (card > 0)
    {
        card = card / 10;
        length++;
    }
    // identify if the card is a VISA
    // get the first digit in VISA
    while (visa >= 10)
    {
        visa = visa / 10;
    }
    if (visa == 4 && (length == 13 || length == 16))
    {
        printf("%s\n", "VISA");
        return 0;
    }
    // identify if the card is an AMEX
    while (amex >= 10000000000000)
    {
        amex = amex / 10000000000000;
    }
    if (length == 15 && (amex == 34 || amex == 37))
    {
        printf("%s\n", "AMEX");
        return 0;
    }
    // identify if the card is a Mastercard
    while (master >= 100000000000000)
    {
        master = master / 100000000000000;
    }
    if ((length == 16) && (master == 51 || master == 52 || master == 53 || master == 54 || master == 55))
    {
        printf("%s\n", "MASTERCARD");
        return 0;
    }
    else
    {
        printf("%s\n", "INVALID");
    }
    return 0;
}