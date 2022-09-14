#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
typedef uint8_t Byte;

int check(Byte block[]);

int main(int argc, char *argv[])
{
    int counter = 0;
    Byte block[512];
    char filen[] = "000.jpg";
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE");
        return 1;
    }

    FILE *input = fopen(argv[1], "r");
    FILE *output = fopen("First", "w");
    while (fread(block, 512, 1, input))
    {
        if (check(block))
        {
            fclose(output);
            sprintf(filen, "%i03.jpg", counter);
            counter++;
            output = fopen(filen, "w");
            fwrite(block,512,1,output);
        }
    }
}

int check(Byte block[])
{
    if (block[0] == 0xff && block[1] == 0xd8 && block[2] == 0xff && (block[3] & 0xf0) == 0xe0)
        return 1;
    return 0;
}
