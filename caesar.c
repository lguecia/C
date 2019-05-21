// encryption

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    // Check if the user did not enter a command line argument
    if (argc <= 1)
    {
        printf("You did not enter a command line argument\n");
        return 1;
    }
    // Check if the user entered more than 1 command line argument
    else if (argc > 2)
    {
        printf("You entered too many command line arguments\n");
        return 1;
    }
    else
    {
        // If argc = 2, convert string to an integer k
        int k = atoi(argv[1]);
        printf("plaintext: ");

        // Prompt user for plaintext to encrypt
        string p = get_string();
        printf("ciphertext: ");

        int n = strlen(p);
        int i = 0;

        for (i = 0; i < n; i++)
        {
            // Encipher plaintext. If alphabetic, preserve case and shift it by the key
            if (islower(p[i]))
            {
                printf("%c", (((p[i] - 97) + k) % 26) + 97);
            }
            else if (isupper(p[i]))
            {
                printf("%c", (((p[i] - 65) + k) % 26) + 65);
            }
            else
            {
                printf("%c", p[i]);
            }
        }
        printf("\n");
        return 0;
    }
}