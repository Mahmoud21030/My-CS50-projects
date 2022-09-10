#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define isalphab(word) (isalpha(word)&&1)

char Sub[26] = "abcdefghijklmnopqrstuvwxyz";

int main(int argc, string argv[])
{
}

int check(string code, int count)
{
    int c = 0;
    if (count == 2) // check if there is number or no
    {
        if (strlen(code) == 26) // check 26 char
        {
            for (int i = 0; i < 26; i++) // check all alpha
            {
                c += isalphab(code[i]);

            }
            printf("%d",c);
        }
        else
        {
            printf("Key must contain 26 characters.");

            printf("%i %s\n", count, code);
        }
    }
    else // For null input
    {
        printf("Usage: ./substitution key");
    }
    return 0;
}