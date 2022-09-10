#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define isalphab(word) (isalpha(word) && 1)
int numalpha(string code);
int check(int argc, string argv);
char Sub[26] = "abcdefghijklmnopqrstuvwxyz";

int main(int argc, string argv[])
{
    int x = check(argc, argv[1]);
    printf("%d", x);

    string word = get_string("plaintext:  ");
    char original[strlen(word)];

    strcpy(original, word);
    original[1]='a';

    for (int i = 0, n = strlen(argv[1]); i < n; i++) // to lowercase char
    {
       (argv[1])[i] = tolower((argv[1])[i]);
        (argv[1])[i] -= 97; // mapping Alpha into 0.1.2
    }

    for (int i = 0, n = strlen(word); i < n; i++) // to lowercase char
    {
        word[i] = tolower(word[i]);
       word[i] = (argv[1])[word[i] - 97]; // mapping Alpha into 0.1.2

    }

    printf("%s %s", original , word);
}






int numalpha(string code)
{
    int c = 0;
    for (int i = 0; i < 26; i++) // check all alpha
    {
        c += isalphab(code[i]);
    }
    return c;
}

int check(int argc, string argv)
{
    int n = strlen(argv);
    int na = numalpha(argv);
    if (argc == 2) // check if there is number or no
    {              ///////////////////////////////////////////////////////////////////////////
        if (na > 0)
        {
            if (n == 26)
            {
                if (na == 26)
                {
                    return 1;
                }
                else
                {
                    printf("Key must contain 26 characters.");
                    return 0;
                }
            }
            else
            {
                printf("Key must contain 26 characters.");
                return 0;
            }
        }
        else // For number and alpha
        {
            printf("Usage: ./substitution key");
            return 0;
        }
    }

    ////////////////////////////////////////////////////////////////////////////
    else // For null input
    {
        printf("Usage: ./substitution key");
        return 0;
    }
}
