#include <cs50.h>
#include <stdio.h>
#include <math.h>

#define size(x) (sizeof(x) / sizeof((x)[0]))

int main(void)
{
    double  card = get_int("enter Card number");

    //digitize(card);
    printf("%lf\n", card);
   //  checksum(card);

}