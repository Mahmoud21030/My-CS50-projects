#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
typedef uint8_t Byte;

int check(Byte array[]);

int main(int argc, char *argv[])
{
    int counter = 0;
    Byte array[512];
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE");
        return 1;
    }

    FILE *input = fopen(argv[1], "r");
    FILE *output = fopen("First", "write");
    while (fread(array, 512, 1, in))
    {
        if (check(array))
        {
            fclose(output);
            
        }
    }
}

int check(Byte array[])
{
    if (array[0] == 0xff && array[1] == 0xd8 && array[2] == 0xff && (array[3] & 0xf0) == 0xe0)
        return 1;
    return 0;
}
