#include <cs50.h>
#include <stdio.h>
#include <math.h>

#define NELEMS(x) (sizeof(x) / sizeof((x)[0]))

void checksum(int x);
int getlen(int y);
void digitize(int card);
int array[16];


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
    if (y<1 )
    return 1;
    else{
    return ceil(log10(y+0.0001));}
}

void digitize(int card){
    int l = getlen(card);
    for(int i =0; i< l;i++){
        array[i]=
    }

}