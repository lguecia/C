// create pyramid using spaces and hashes

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt user for a number between 0 and 23
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 0 || n > 23);

    // Print out this many spaces and hashes per row (i)
    for (int i = 0; i < n; i++)
    {
        // Print out this many spaces (s)
        for (int s = n - i; s > 1; s--)
        {
            printf(" ");
        }
        // Print out this many hashes
        for (int h = 0; h < i + 2; h++)
        {
            printf("#");
        }
        printf("\n");
    }
}