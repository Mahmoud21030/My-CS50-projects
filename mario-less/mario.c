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
    }
}

void printer(int x ,int y)
{
    if (x  != 0)
    {
        x--;
        y++;
       // printf("%i %i",x,y);
        for (int i = x; i  != 0; i--){
            printf(" ");
        }
        for (int z = y; z  != 0; z--){
            printf("#");
        }
        printf("\n");
        printer( x, y);

    }
    else{
    return;}
}
