#include <cs50.h>
#include <stdio.h>
void printer(int x);
int main(void)
{
    while (1)
    {
        int num = get_int("Enter the Hight: ");
        if (num < 9 && num > 0)
        {
            printer(num);
        }
        else
        {
            break;
        }
    }
}

void printer(int x)
{
    else if (x == 1)
    {
        printf(" ");
    }
    else
    {
        x--;
        printer( x);
    }
    return;
}
