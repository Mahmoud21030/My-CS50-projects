#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define isalphab(word) (isalpha(word) && 1)
int check(string code, int count);
char Sub[26] = "abcdefghijklmnopqrstuvwxyz";

int main(int argc, string argv[])
{
    argv[1] = "YTNSHKVEFXRBAUQZCLWDMIPGJ";
    argc = 2;
    n = strlen(argv);

    if (argc == 2) // check if there is number or no
    {///////////////////////////////////////////////////////////////////////////

        if (n == 26)
        {
            printf("Key must contain 26 characters.");


        }
        else {
            printf("Key must contain 26 characters.");
        }



    }




    ////////////////////////////////////////////////////////////////////////////
    else // For null input
    {
        printf("Usage: ./substitution key");
    }
    return 0;
}

int numalpha(string code, int count)
{
    for (int i = 0; i < 26; i++) // check all alpha
    {
        c += isalphab(code[i]);
    }
    return c;
}
