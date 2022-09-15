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
            temp = round((image[rows][column].rgbtBlue +
                    image[rows][column].rgbtRed +
                    image[rows][column].rgbtGreen) /
                   3.0);
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
        for (int column = 0; column < floor((width ) / 2); column++)
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
            if (column > 0 && rows > 0 && column < (width - 1) && rows < (height-1)) // first type-1 all sides
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
                image[rows][column].rgbtBlue = (copy[rows - 1][column].rgbtBlue+ //above
                                            copy[rows ][column+1].rgbtBlue+//side
                                            copy[rows +1][column].rgbtBlue+ //down
                                            copy[rows - 1][column+1].rgbtBlue+ //above side
                                            copy[rows +1][column+1].rgbtBlue)/6; //down side

                 image[rows][column].rgbtRed = (copy[rows - 1][column].rgbtRed+ //above
                                            copy[rows ][column+1].rgbtRed+//side
                                            copy[rows +1][column].rgbtRed+ //down
                                            copy[rows - 1][column+1].rgbtRed+ //above side
                                            copy[rows +1][column+1].rgbtRed)/6; //down side
                 image[rows][column].rgbtGreen = (copy[rows - 1][column].rgbtGreen+ //above
                                            copy[rows ][column+1].rgbtGreen+//side
                                            copy[rows +1][column].rgbtGreen+ //down
                                            copy[rows - 1][column+1].rgbtGreen+ //above side
                                            copy[rows +1][column+1].rgbtGreen)/6; //down side
            }
            else if ((rows != 0 && rows != (height-1)) && column == (width-1) )
            {
                image[rows][column].rgbtBlue = (copy[rows - 1][column].rgbtBlue+ //above
                                            copy[rows ][column-1].rgbtBlue+//side
                                            copy[rows +1][column].rgbtBlue+ //down
                                            copy[rows - 1][column-1].rgbtBlue+ //above side
                                            copy[rows +1][column-1].rgbtBlue)/6 ;//down side
                image[rows][column].rgbtRed = (copy[rows - 1][column].rgbtRed+ //above
                                            copy[rows ][column-1].rgbtRed+//side
                                            copy[rows +1][column].rgbtRed+ //down
                                            copy[rows - 1][column-1].rgbtRed+ //above side
                                            copy[rows +1][column-1].rgbtRed)/6 ;//down side
                image[rows][column].rgbtGreen = (copy[rows - 1][column].rgbtGreen+ //above
                                            copy[rows ][column-1].rgbtGreen+//side
                                            copy[rows +1][column].rgbtGreen+ //down
                                            copy[rows - 1][column-1].rgbtGreen+ //above side
                                            copy[rows +1][column-1].rgbtGreen)/6 ;//down side
            }

            else if ((column != 0 && column != (width-1)) && rows == 0  )
            {
                image[rows][column].rgbtBlue =( copy[rows ][column-1].rgbtBlue+ //sideleft
                                            copy[rows ][column+1].rgbtBlue+ //sideright
                                            copy[rows +1][column].rgbtBlue+ //down
                                            copy[rows + 1][column-1].rgbtBlue+ //down left
                                            copy[rows +1][column+1].rgbtBlue)/6; //down right
                image[rows][column].rgbtRed =( copy[rows ][column-1].rgbtRed+ //sideleft
                                            copy[rows ][column+1].rgbtRed+ //sideright
                                            copy[rows +1][column].rgbtRed+ //down
                                            copy[rows + 1][column-1].rgbtRed+ //down left
                                            copy[rows +1][column+1].rgbtRed)/6; //down right
                image[rows][column].rgbtGreen =( copy[rows ][column-1].rgbtGreen+ //sideleft
                                            copy[rows ][column+1].rgbtGreen+ //sideright
                                            copy[rows +1][column].rgbtGreen+ //down
                                            copy[rows + 1][column-1].rgbtGreen+ //down left
                                            copy[rows +1][column+1].rgbtGreen)/6; //down right


            }
            else if ((column != 0 && column != (width-1)) && rows == (height-1)  )
            {
                image[rows][column].rgbtBlue = (copy[rows ][column-1].rgbtBlue+ //sideleft
                                            copy[rows ][column+1].rgbtBlue+ //sideright
                                            copy[rows -1][column].rgbtBlue+ //up
                                            copy[rows - 1][column-1].rgbtBlue+ //up left
                                            copy[rows -1][column+1].rgbtBlue)/6; //up right
                image[rows][column].rgbtRed = (copy[rows ][column-1].rgbtRed+ //sideleft
                                            copy[rows ][column+1].rgbtRed+ //sideright
                                            copy[rows -1][column].rgbtRed+ //up
                                            copy[rows - 1][column-1].rgbtRed+ //up left
                                            copy[rows -1][column+1].rgbtRed)/6; //up right
                image[rows][column].rgbtGreen = (copy[rows ][column-1].rgbtGreen+ //sideleft
                                            copy[rows ][column+1].rgbtGreen+ //sideright
                                            copy[rows -1][column].rgbtGreen+ //up
                                            copy[rows - 1][column-1].rgbtGreen+ //up left
                                            copy[rows -1][column+1].rgbtGreen)/6; //up right
            }
            else if ((column == 0 && rows == 0 )
            {    image[rows][column].rgbtBlue =
                                            copy[rows ][column+1].rgbtBlue+//side
                                            copy[rows +1][column].rgbtBlue+ //down
                                            copy[rows +1][column+1].rgbtBlue)/3; //down side

                 image[rows][column].rgbtRed = (
                                            copy[rows ][column+1].rgbtRed+//side
                                            copy[rows +1][column].rgbtRed+ //down

                                            copy[rows +1][column+1].rgbtRed)/3; //down side
                 image[rows][column].rgbtGreen = (
                                            copy[rows ][column+1].rgbtGreen+//side
                                            copy[rows +1][column].rgbtGreen+ //down
                                            
                                            copy[rows +1][column+1].rgbtGreen)/6; //down side

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
