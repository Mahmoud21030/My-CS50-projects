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
    if (x = !0)
    {
        x--;
        for (int i = x; i = !0; i--){
            printf("-")
        }
        for (int i = x; i = !0; i--){
            printf("-")
        }
    }
    return;
}
