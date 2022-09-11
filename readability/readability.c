#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#define isalphap(c) (isalpha(c) && 1)
int letters(string message);
int sent(string message);
int word(string message);

int main(void)
{
    string message = get_string("Text: "); // getting an input from user
    int index=0;
    float l=(float)letters(message)/word(message) * 100.0;
    float s=(float)sent(message)/word(message) * 100.0;
    printf("letters is %i\n  sent is %i\n word is %i\n L=%0.2f \n S= %0.2f\n",letters(message),sent(message),word(message),l,s);
}

int letters(string message) // searching for letters in message
{
    int n = 0;
    for (int i = 0; i < strlen(message); i++)
    {
        if (isalphap(message[i]))
        {
            n++;
        }
    }
    return n;
}

int sent(string message) // sentence searcher
{
    int n = 0;
    for (int i = 0; i < strlen(message); i++)
    {
        if (message[i]=='!' || message[i]=='.')
        {
            n++;
        }
    }
    return n;
}

int word(string message) // for words searching for "spaces"
{
    int n = 0;
    for (int i = 0; i < strlen(message); i++)
    {
        if (message[i]==' ')
        {
            n++;
        }
    }
    return n+1;
}