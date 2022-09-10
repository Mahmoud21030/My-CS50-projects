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
    
    int x = check( argc,  argv[1]);
    printf("%d",x);
}

int numalpha(string code){
    int c=0;
    for (int i = 0; i < 26; i++) // check all alpha
    {
        c += isalphab(code[i]);
    }
    return c;
}

int check(int argc, string argv){
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
