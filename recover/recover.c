#include <stdio.h>
#include <stdlib.h>

int check(char array[]);

int main(int argc, char *argv[])
{   char array[512];
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE");
        return 1;
    }

    FILE *input = fopen(argv[1], "r");

    while (feof(input) == 0)
    {
      //  if (check(array))
    }
}

int check(char array[])
{
    if(array[0]==0xff && array[1]==0xd8 && array[2]==0xff && (array[3] & 0xf0)==0xe0)
    return 1;
    return 0;
}
