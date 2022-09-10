#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define isalphab(word) (isalpha(word) && 1)
int numalpha(string code);
char Sub[26] = "abcdefghijklmnopqrstuvwxyz";

int main(int argc, string argv[])
{
    argv[1] = "YTNSHKVEFXRBAUQZCLWDMIPGJO";
    argc = 2;
   int n = strlen(argv[1]);
   int na = numalpha(argv[1]);
    if (argc == 2) // check if there is number or no
    {              ///////////////////////////////////////////////////////////////////////////
        if (na > 0)
        {
            if (n == 26)
            {
                if (na == 26)
                {
                }
                else
                {
                    printf("Key must contain 26 characters.");
                }
            }
            else
            {
                printf("Key must contain 26 characters.");
            }
        }
        else // For number and alpha
        {
            printf("Usage: ./substitution key");
        }
    }

    ////////////////////////////////////////////////////////////////////////////
    else // For null input
    {
        printf("Usage: ./substitution key");
    }
    return 0;
}

int numalpha(string code){
    int c=0;
    for (int i = 0; i < 26; i++) // check all alpha
    {
        c += isalphab(code[i]);
    }
    return c;
}
