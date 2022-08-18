#include <cs50.h>
#include <stdio.h>
void printer(int x ,int y);
int main(void)
{
    while (1)
    {
        int num = get_int("Enter the Hight: ");
        if (num < 9 && num > 0)
        {
            printer(num,0);
        }
        else
        {
            break;
        }
    }
}

void printer(int x ,int y)
{
    if (x  != 0)
    {
        x--;
        y++;
        for (int i = x; i  != 0; i--){
            printf("-");
        }
        for (int i = y; i  != 0; i--){
            printf("#\n");
        }

        printer( x, y);

    }
    else{
    return;}
}
