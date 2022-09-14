#include "helpers.h"
#include <math.h>
// BYTE  rgbtBlue;
//  BYTE  rgbtGreen;
//  BYTE  rgbtRed;
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int temp = 0;
    for (int rows = 0; rows < height; rows++)
    {
        for (int column = 0; column < width; column++)
        {
            temp = (image[rows][column].rgbtBlue +
                    image[rows][column].rgbtRed +
                    image[rows][column].rgbtGreen) /
                   3;
            image[rows][column].rgbtBlue = temp;
            image[rows][column].rgbtRed = temp;
            image[rows][column].rgbtGreen = temp;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp;
    for (int rows = 0; rows < height; rows++)
    {
        for (int column = 0; column < floor((width - 1) / 2); column++)
        {
            temp = image[rows][column];
            image[rows][column] = image[rows][width - column - 1];
            image[rows][width - column - 1] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int x = 0; x < height; x++)
    {
        for (int y = 0; y < width; y++)
        {
            copy[x][y] = image[x][y];
        }
    }

    for (int rows = 0; rows < height; rows++)
    {
        for (int column = 0; column < width; column++)
        {
            if (column > 0 && rows > 0 && column < (width - 1) && rows < (height)) // first type-1 all sides
            {
                image[rows][column].rgbtBlue = (copy[rows - 1][column - 1].rgbtBlue +
                                                copy[rows + 1][column + 1].rgbtBlue +
                                                copy[rows][column - 1].rgbtBlue +
                                                copy[rows - 1][column].rgbtBlue +
                                                copy[rows][column + 1].rgbtBlue +
                                                copy[rows + 1][column].rgbtBlue +
                                                copy[rows - 1][column + 1].rgbtBlue +
                                                copy[rows + 1][column - 1].rgbtBlue) /
                                               8;

                image[rows][column].rgbtRed = (copy[rows - 1][column - 1].rgbtRed +
                                               copy[rows + 1][column + 1].rgbtRed +
                                               copy[rows][column - 1].rgbtRed +
                                               copy[rows - 1][column].rgbtRed +
                                               copy[rows][column + 1].rgbtRed +
                                               copy[rows + 1][column].rgbtRed +
                                               copy[rows - 1][column + 1].rgbtRed +
                                               copy[rows + 1][column - 1].rgbtRed) /
                                              8;

                image[rows][column].rgbtGreen = (copy[rows - 1][column - 1].rgbtGreen +
                                                 copy[rows + 1][column + 1].rgbtGreen +
                                                 copy[rows][column - 1].rgbtGreen +
                                                 copy[rows - 1][column].rgbtGreen +
                                                 copy[rows][column + 1].rgbtGreen +
                                                 copy[rows + 1][column].rgbtGreen +
                                                 copy[rows - 1][column + 1].rgbtGreen +
                                                 copy[rows + 1][column - 1].rgbtGreen) /
                                                8;
            }
            else if ((rows != 0 && rows != (height-1)) && column == 0  )
            {
                image[rows][column].rgbtBlue = copy[rows - 1][column].rgbtBlue+ //above
                                            copy[rows ][column+1].rgbtBlue+//side
                                            copy[rows +1][column].rgbtBlue+ //down
                                            copy[rows - 1][column+1].rgbtBlue+ //above side
                                            copy[rows +1][column+1].rgbtBlue+ //down side
            }
            else if ((rows != 0 && rows != (height-1)) && column == (width-1) )
            {
                image[rows][column].rgbtBlue = copy[rows - 1][column].rgbtBlue+ //above
                                            copy[rows ][column-1].rgbtBlue+//side
                                            copy[rows +1][column].rgbtBlue+ //down
                                            copy[rows - 1][column-1].rgbtBlue+ //above side
                                            copy[rows +1][column-1].rgbtBlue+ //down side
            }
            }
            else if ((column != 0 && column != (width-1)) && rows == 0  )
            {
            else if ((column != 0 && column != (width-1)) && rows == (height-1)  )
            {
            }
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
