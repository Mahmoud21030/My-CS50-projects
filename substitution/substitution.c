#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int Sub[26]={a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,f,w,x,y,z};

int main(int argc, string argv[])
{
    if (argc == 2) // check if there is number or no
    {
        if (strlen(argv[1]) == 26)
        {
            

        }
        else
        {
            printf("Key must contain 26 characters.");

            printf("%i %s\n", argc, argv[1]);
        }
    }
    else // For null input
    {
        printf("Usage: ./substitution key");
    }
}