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
    index = 0.0588 * l - 0.296 * s - 15.8;
    printf("Grade %i\n"
    ,index);

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
        if (message[i]=='!' || message[i]=='.'|| message[i]==',')
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