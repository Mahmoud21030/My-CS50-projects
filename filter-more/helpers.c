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

    for (int x = 0; x < height; x++)
    {
        for (int y = 0; y < width; y++)
        {
            image[x][y] = image[x][y];
        }
    }

    for (int rows = 0; rows < height; rows++)
    {
        for (int column = 0; column < width; column++)
        {
            if (column > 0 && rows > 0 && column < (width - 1) && rows < (height-1)) // first type-1 all sides
            {
                image[rows][column].rgbtBlue = round((image[rows][column].rgbtBlue+
                                                image[rows - 1][column - 1].rgbtBlue +
                                                image[rows + 1][column + 1].rgbtBlue +
                                                image[rows][column - 1].rgbtBlue +
                                                image[rows - 1][column].rgbtBlue +
                                                image[rows][column + 1].rgbtBlue +
                                                image[rows + 1][column].rgbtBlue +
                                                image[rows - 1][column + 1].rgbtBlue +
                                                image[rows + 1][column - 1].rgbtBlue) /
                                               9.0);

                image[rows][column].rgbtRed = round(( image[rows][column].rgbtRed+
                                               image[rows - 1][column - 1].rgbtRed +
                                               image[rows + 1][column + 1].rgbtRed +
                                               image[rows][column - 1].rgbtRed +
                                               image[rows - 1][column].rgbtRed +
                                               image[rows][column + 1].rgbtRed +
                                               image[rows + 1][column].rgbtRed +
                                               image[rows - 1][column + 1].rgbtRed +
                                               image[rows + 1][column - 1].rgbtRed )/
                                              9.0);

                image[rows][column].rgbtGreen = round((image[rows][column].rgbtGreen+
                                                image[rows - 1][column - 1].rgbtGreen +
                                                 image[rows + 1][column + 1].rgbtGreen +
                                                 image[rows][column - 1].rgbtGreen +
                                                 image[rows - 1][column].rgbtGreen +
                                                 image[rows][column + 1].rgbtGreen +
                                                 image[rows + 1][column].rgbtGreen +
                                                 image[rows - 1][column + 1].rgbtGreen +
                                                 image[rows + 1][column - 1].rgbtGreen )/9.0);
            }
            else if ((rows != 0 && rows != (height-1)) && column == 0  )
            {
                image[rows][column].rgbtBlue =round((image[rows][column].rgbtBlue+
                                            image[rows - 1][column].rgbtBlue+ //above
                                            image[rows ][column+1].rgbtBlue+//side
                                            image[rows +1][column].rgbtBlue+ //down
                                            image[rows - 1][column+1].rgbtBlue+ //above side
                                            image[rows +1][column+1].rgbtBlue)/6.0); //down side

                 image[rows][column].rgbtRed = round(( image[rows][column].rgbtRed+
                                            image[rows - 1][column].rgbtRed+ //above
                                            image[rows ][column+1].rgbtRed+//side
                                            image[rows +1][column].rgbtRed+ //down
                                            image[rows - 1][column+1].rgbtRed+ //above side
                                            image[rows +1][column+1].rgbtRed)/6.0); //down side

                 image[rows][column].rgbtGreen =round ((image[rows][column].rgbtGreen+
                                            image[rows - 1][column].rgbtGreen+ //above
                                            image[rows ][column+1].rgbtGreen+//side
                                            image[rows +1][column].rgbtGreen+ //down
                                            image[rows - 1][column+1].rgbtGreen+ //above side
                                            image[rows +1][column+1].rgbtGreen)/6.0); //down side
            }
            else if ((rows != 0 && rows != (height-1)) && column == (width-1) )
            {
                image[rows][column].rgbtBlue = round((image[rows][column].rgbtBlue+
                                             image[rows - 1][column].rgbtBlue+ //above
                                            image[rows ][column-1].rgbtBlue+//side
                                            image[rows +1][column].rgbtBlue+ //down
                                            image[rows - 1][column-1].rgbtBlue+ //above side
                                            image[rows +1][column-1].rgbtBlue)/6.0) ;//down side

                image[rows][column].rgbtRed = round((image[rows][column].rgbtRed+
                                            image[rows - 1][column].rgbtRed+ //above
                                            image[rows ][column-1].rgbtRed+//side
                                            image[rows +1][column].rgbtRed+ //down
                                            image[rows - 1][column-1].rgbtRed+ //above side
                                            image[rows +1][column-1].rgbtRed)/6.0) ;//down side
                image[rows][column].rgbtGreen = round((image[rows][column].rgbtGreen+
                                            image[rows - 1][column].rgbtGreen+ //above
                                            image[rows ][column-1].rgbtGreen+//side
                                            image[rows +1][column].rgbtGreen+ //down
                                            image[rows - 1][column-1].rgbtGreen+ //above side
                                            image[rows +1][column-1].rgbtGreen)/6.0) ;//down side
            }

            else if ((column != 0 && column != (width-1)) && rows == 0  )
            {
                image[rows][column].rgbtBlue =round((image[rows][column].rgbtBlue+
                                            image[rows ][column-1].rgbtBlue+ //sideleft
                                            image[rows ][column+1].rgbtBlue+ //sideright
                                            image[rows +1][column].rgbtBlue+ //down
                                            image[rows + 1][column-1].rgbtBlue+ //down left
                                            image[rows +1][column+1].rgbtBlue)/6.0); //down right
                image[rows][column].rgbtRed =round((image[rows][column].rgbtRed+
                                            image[rows ][column-1].rgbtRed+ //sideleft
                                            image[rows ][column+1].rgbtRed+ //sideright
                                            image[rows +1][column].rgbtRed+ //down
                                            image[rows + 1][column-1].rgbtRed+ //down left
                                            image[rows +1][column+1].rgbtRed)/6.0); //down right
                image[rows][column].rgbtGreen =round((image[rows][column].rgbtGreen+
                                            image[rows ][column-1].rgbtGreen+ //sideleft
                                            image[rows ][column+1].rgbtGreen+ //sideright
                                            image[rows +1][column].rgbtGreen+ //down
                                            image[rows + 1][column-1].rgbtGreen+ //down left
                                            image[rows +1][column+1].rgbtGreen)/6.0); //down right


            }
            else if ((column != 0 && column != (width-1)) && rows == (height-1)  )
            {
                image[rows][column].rgbtBlue = round((image[rows][column].rgbtBlue+
                                            image[rows ][column-1].rgbtBlue+ //sideleft
                                            image[rows ][column+1].rgbtBlue+ //sideright
                                            image[rows -1][column].rgbtBlue+ //up
                                            image[rows - 1][column-1].rgbtBlue+ //up left
                                            image[rows -1][column+1].rgbtBlue)/6.0); //up right

                image[rows][column].rgbtRed = round((image[rows][column].rgbtRed+
                                            image[rows ][column-1].rgbtRed+ //sideleft
                                            image[rows ][column+1].rgbtRed+ //sideright
                                            image[rows -1][column].rgbtRed+ //up
                                            image[rows - 1][column-1].rgbtRed+ //up left
                                            image[rows -1][column+1].rgbtRed)/6.0); //up right

                image[rows][column].rgbtGreen = round((image[rows][column].rgbtGreen+
                                            image[rows ][column-1].rgbtGreen+ //sideleft
                                            image[rows ][column+1].rgbtGreen+ //sideright
                                            image[rows -1][column].rgbtGreen+ //up
                                            image[rows - 1][column-1].rgbtGreen+ //up left
                                            image[rows -1][column+1].rgbtGreen)/6.0); //up right
            }
            else if (column == 0 && rows == 0 )
            {    image[rows][column].rgbtBlue =
                                            round((image[rows][column].rgbtBlue+
                                                image[rows ][column+1].rgbtBlue+//side
                                            image[rows +1][column].rgbtBlue+ //down
                                            image[rows +1][column+1].rgbtBlue)/4.0); //down side

                 image[rows][column].rgbtRed =round((image[rows][column].rgbtRed+
                                            image[rows ][column+1].rgbtRed+//side
                                            image[rows +1][column].rgbtRed+ //down

                                            image[rows +1][column+1].rgbtRed)/4.0); //down side
                 image[rows][column].rgbtGreen = round((image[rows][column].rgbtGreen+
                                            image[rows ][column+1].rgbtGreen+//side
                                            image[rows +1][column].rgbtGreen+ //down

                                            image[rows +1][column+1].rgbtGreen)/4.0); //down side

            }
            else if (column == (width -1) && rows == 0 )
            {    image[rows][column].rgbtBlue =
                                            round((image[rows][column].rgbtBlue+
                                            image[rows ][column-1].rgbtBlue+//side
                                            image[rows +1][column].rgbtBlue+ //down
                                            image[rows +1][column-1].rgbtBlue)/4.0); //down side

                 image[rows][column].rgbtRed = round((image[rows][column].rgbtRed+
                                            image[rows ][column-1].rgbtRed+//side
                                            image[rows +1][column].rgbtRed+ //down

                                            image[rows +1][column-1].rgbtRed)/4.0); //down side
                 image[rows][column].rgbtGreen = round((image[rows][column].rgbtGreen+
                                            image[rows ][column-1].rgbtGreen+//side
                                            image[rows +1][column].rgbtGreen+ //down

                                            image[rows +1][column-1].rgbtGreen)/4.0); //down side

            }
            else if (column == 0 && rows == (height -1))
            {    image[rows][column].rgbtBlue =
                                           round((image[rows][column].rgbtBlue+
                                             image[rows ][column+1].rgbtBlue+//side
                                            image[rows -1][column].rgbtBlue+ //down
                                            image[rows -1][column+1].rgbtBlue)/4.0); //down side

                 image[rows][column].rgbtRed = round((image[rows][column].rgbtRed+
                                            image[rows ][column+1].rgbtRed+//side
                                            image[rows -1][column].rgbtRed+ //down

                                            image[rows -1][column+1].rgbtRed)/4.0);//down side

                 image[rows][column].rgbtGreen = round((image[rows][column].rgbtGreen+
                                            image[rows ][column+1].rgbtGreen+//side
                                            image[rows -1][column].rgbtGreen+ //down

                                            image[rows -1][column+1].rgbtGreen)/4.0); //down side

}
            else if (column == (width -1) && rows == (height -1) )
            {    image[rows][column].rgbtBlue =
                                            round((image[rows][column].rgbtBlue+
                                                image[rows ][column+1].rgbtBlue+//side
                                            image[rows -1][column].rgbtBlue+ //down
                                            image[rows -1][column+1].rgbtBlue)/4.0); //down side

                 image[rows][column].rgbtRed = round((image[rows][column].rgbtBlue+
                                            image[rows ][column+1].rgbtRed+//side
                                            image[rows -1][column].rgbtRed+ //down

                                            image[rows -1][column+1].rgbtRed)/4.0); //down side
                 image[rows][column].rgbtGreen = round((image[rows][column].rgbtBlue+
                                            image[rows ][column+1].rgbtGreen+//side
                                            image[rows -1][column].rgbtGreen+ //down

                                            image[rows -1][column+1].rgbtGreen)/4.0); //down side
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
