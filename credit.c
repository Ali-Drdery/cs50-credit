#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long card = get_long("Number: ");

    long temp = card;
    int sum1 = 0;
    int sum2 = 0;
    int count = 0;

    // Luhn’s Algorithm
    while (temp > 0)
    {
        // take last digit
        int digit1 = temp % 10;
        sum1 += digit1;
        temp /= 10;
        count++;

        // take second last digit
        if (temp > 0)
        {
            int digit2 = temp % 10;
            digit2 = digit2 * 2;

            // if result has 2 digits
            if (digit2 > 9)
            {
                sum2 += (digit2 % 10) + 1;
            }
            else
            {
                sum2 += digit2;
            }

            temp /= 10;
            count++;
        }
    }

    int total = sum1 + sum2;

    // get first digits
    long first = card;
    while (first >= 100)
    {
        first /= 10;
    }

    // check card type
    if (total % 10 == 0)
    {
        // AMEX
        if ((first == 34 || first == 37) && count == 15)
        {
            printf("AMEX\n");
        }

        // MASTERCARD
        else if ((first >= 51 && first <= 55) && count == 16)
        {
            printf("MASTERCARD\n");
        }

        // VISA
        else if ((first / 10 == 4) && (count == 13 || count == 16))
        {
            printf("VISA\n");
        }

        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}