#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define isalphap(char c) (isalpha(c) && 1)
int letters(string message);

int main(void)
{
    string message = get_string("Text: "); // getting an input from user
    printf("letters is %i",letters(string message));
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
}