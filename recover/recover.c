#include <stdio.h>
#include <stdlib.h>

int check(char array[]);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE");
        return 1;
    }

    FILE *input = fopen(argv[1], "r");

    while (feof(input) == 0)
    {
        if (check)
    }
}

int check(char array[])
{
}
