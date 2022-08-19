#include <cs50.h>
#include <stdio.h>
#include <math.h>

#define NELEMS(x) (sizeof(x) / sizeof((x)[0]))

void checksum(int x);
int getlen(int y);

int Mas[16];
int Am[15];
int vis16[16];
int vis[13];

int main(void)
{
    int card = get_int("enter Card number");
    checksum(card);

    printf("%i\n",getlen(card));

   
}

void checksum(int x)
{

    return;
}

int getlen(int y){
    return ceil(log10(y));
}