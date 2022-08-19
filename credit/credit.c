#include <cs50.h>
#include <stdio.h>
#include <math.h>

#define NELEMS(x) (sizeof(x) / sizeof((x)[0]))

void sum(int x);
int getlen(int y);
void digitize(int card);
int array[16];

int main(void)
{
    int card = get_int("enter Card number");

    digitize(card);
    printf("%i\n", array[0]);
    sum(card);
}

void sum(int x)
{
    int sum = 0;
    int l = getlen(x);
    for (int i = l - 1; i >= 0; i -= 1)
    {
        sum += array[i];

    }

 printf("%i\n", sum);
    return;
}



int getlen(int y)
{
    if (y < 1)
        return 1;
    else
    {
        return ceil(log10(y + 0.0001));
    }
}



void digitize(int card)
{
    int l = getlen(card);
    for (int i = 0; i < l; i++)
    {
        array[i] = card / pow(10, (l - i - 1));
        card = card - array[i] * pow(10, (l - i - 1));
    }
}