#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define isalphab(word) (isalpha(word) && 1)
int numalpha(string code);
int check(int argc, string argv);

int main(int argc, string argv[])
{
    int x = 0;
    if (argc == 2)
    {
        x = check(argc, argv[1]);
    }
    else // For null input
    {
        printf("Usage: ./substitution key");
        return 1;
    }

    if (x == 1)
    {
        string word = get_string("plaintext:  ");
        char original[strlen(word)];

        strcpy(original, word);

        for (int i = 0, n = strlen(argv[1]); i < n; i++) // to lowercase char
        {
            (argv[1])[i] = tolower((argv[1])[i]);
        }

        for (int i = 0, n = strlen(word); i < n; i++) // to lowercase char
        {
            word[i] = tolower(word[i]);
            if (isalphab(word[i]))
            {
                word[i] = (argv[1])[word[i] - 97];
            } // mapping Alpha into 0.1.2
        }
        for (int i = 0, n = strlen(original); i < n; i++) // to lowercase char
        {
            if (!islower(original[i]))
            {
                word[i] = toupper(word[i]);
            }
        }

        printf("ciphertext: %s\n", word);
    }
    else
    {
        return 1;
    }
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
    int counter = 0;
    if (argc == 2) // check if there is number or no
    {
            ///////////////////////////////////////////////////////////////////////////
        if (na > 0)
        {
            if (n == 26)
            {
                if (na == 26)
                {
                    for (int i = 0; i < 26; i++)
                    {
                        // duplcate check
                        for (int y = i + 1; y < 26; y++)
                        {
                            if (argv[i] == argv[y])
                            {
                                counter++;
                            }
                        }
                    }
                    if (counter == 0)
                    {
                        return 1;
                    }
                    else
                    {
                        return 0;
                    }
                }
                else
                {
                    printf("Key must contain 26 characters.\n");
                    return 0;
                }
            }
            else
            {
                printf("Key must contain 26 characters.\n");
                return 0;
            }
        }
        else // For number and alpha
        {
            printf("Usage: ./substitution key\n");
            return 0;
        }
    }

    ////////////////////////////////////////////////////////////////////////////
    else // For null input
    {
        printf("Usage: ./substitution key\n");
        return 0;
    }
}
