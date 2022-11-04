#include <cs50.h>
#include <stdio.h>

// This program verifies a card number and returns the card type

// CARDTYPES
// AMEX - 15 digits - starts with 34 or 37
// MASTERCARD - 16 digits - starts with 51,52,53,54,55
// VISA - 13 or 16 digits - starts with 4

// CHECKSUM
// Multiply every other digit, starting with second to last digit
// Add those products' digits together
// Add the sum to the sum of the digits that weren't multiplied by 2
// if the total's last digit is 0, number is valid

int main(void)
{
    // Prompts for input
    long n = get_long("Enter credit card number: ");

    // Counts digits
    int i = 0;
    long creditCard = n;
    while (creditCard > 0)
    {

        // Divides by 10
        creditCard = creditCard / 10;
        i++;
    }

    // Length Validation
    if (i != 13 && i != 15 && i != 16)
    {
        printf("INVALID\n");
        return 0;
    }

    // Calculates checksum
    int firstDigit;
    int secondDigit;
    int modulo1;
    int modulo2;
    long x = n;
    int sum1 = 0;
    int sum2 = 0;
    int total = 0;

    do
    {
        // Removes last digit then adds to sum1
        modulo1 = x % 10;
        x = x / 10;
        sum1 = sum1 + modulo1;

        // Removes second last digit
        modulo2 = x % 10;
        x = x / 10;

        // Doubles second last digit and then adds to sum2
        modulo2 = modulo2 * 2;
        firstDigit = modulo2 % 10;
        secondDigit = modulo2 / 10;
        sum2 = sum2 + firstDigit + secondDigit;

    }

    while (x > 0);

    total = sum1 + sum2;

    // Checks against Luhn Algorithm
    if (total % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    // Get starting digits
    long start = n;

    do
    {
        start = start / 10;
    }

    while (start > 100);

    // Prints card type
    if ((start / 10 == 5) && (0 < start % 10 && start % 10 < 6))
    {
        printf("MASTERCARD\n");
    }
    else if ((start / 10 == 3) && (start % 10 == 4 || start % 10 == 7))

    {
        printf("AMEX\n");
    }
    else if (start / 10 == 4)

    {
        printf("VISA\n");
    }
    else
    {

        printf("INVALID\n");
    }
}