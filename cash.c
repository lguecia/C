// generate change owed from purchase and deliver in fewest number of coins

#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main()
{
    // Prompt user for valid input (amount of change owed) and convert it to number of cents
    float n;
    do
    {
        n = get_float("Change owed: ");
    }
    while (n < 0);

    int number_of_coins = 0;
    int cents = (int) round(n * 100);

    // Always use largest coin possible and keep track of coins used
    number_of_coins += cents / 25;
    cents %= 25;

    number_of_coins += cents / 10;
    cents %= 10;

    number_of_coins += cents / 5;
    cents %= 5;

    number_of_coins += cents / 1;
    cents %= 1;

    // Print final number of coins
    printf("%d\n", number_of_coins);
}