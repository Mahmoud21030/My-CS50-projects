#include <cs50.h>
#include <stdio.h>

int main(void)
{
    while (1)
    {
        int num = get_int("Enter the Hight: ");
        if (num < 9 && num > 0)
        {
            printf("hello world\n");
        }
    }
}