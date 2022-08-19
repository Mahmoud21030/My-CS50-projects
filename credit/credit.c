#include <cs50.h>
#include <stdio.h>
#include <math.h>

#define NELEMS(x) (sizeof(x) / sizeof((x)[0]))

void checksum(double x);
int sumf(int x);
int getlen(double y);
void digitize(double card);
void bank(double card);
int array[16];

int main(void)
{
    double  card = get_double("enter Card number");

    digitize(card);
   // printf("%i\n", array[0]);
    checksum(card);


}

// =checking valid or not
void checksum(double x)
{
    int sum = 0;
    int l = getlen(x);
    for (int i = l - 2; i >= 0; i -= 2)
    {
        sum += sumf(2*array[i]);
//printf("%i\n", sum);
    }
    for (int i = l - 1; i >= 0; i -= 2)
    {
        sum += (array[i]);

    }
    if(sum % 10 != 0){ printf("INVALID\n");}
    else{bank(x);}

    return;
}




int getlen(double y)
{
    if (y < 1)
        return 1;
    else
    {
        return ceil(log10(y + 0.0001));
    }
}

void digitize(double card)
{
    int l = getlen(card);
    for (int i = 0; i < l; i++)
    {
        array[i] = card / pow(10, (l - i - 1));
        card = card - array[i] * pow(10, (l - i - 1));
    }
}


int sumf(int x)
{   int remainder=0;
    int sum = 0;
    while (x != 0)
   {
      remainder = x % 10;
      sum       = sum + remainder;
      x         = x / 10;
   }

 //printf("%i\n", sum);
    return sum;
}



//kind of card
void bank(double card){
    int l = getlen(card);
    if (l==16 ){
        if(array[0]==4)
        printf("VISA\n");
        else if (array[0]==3 && (array[1]==7 || array[1]== 4))
        printf("MASTERCARD\n");

    }
    else if (l==15 && array[0]==5 &&(array[1]<6 && array[1]>0)){
        printf("AMEX\n");

    }
    else if (l==13 && array[0]==4){
         printf("VISA\n");

    }
    else{printf("INVALID\n");}

}