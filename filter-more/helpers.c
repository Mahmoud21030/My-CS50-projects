#include "helpers.h"
#include <math.h>
#define sqr(x) (x) * (x)
typedef struct
{
   unsigned int rgbtBlue;
   unsigned  int rgbtGreen;
   unsigned int rgbtRed;
} RGBint;
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
        for (int column = 0; column < floor((width) / 2); column++)
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
            if (column > 0 && rows > 0 && column < (width - 1) && rows < (height - 1)) // first type-1 all sides
            {
                image[rows][column].rgbtBlue = round((image[rows][column].rgbtBlue +
                                                      copy[rows - 1][column - 1].rgbtBlue +
                                                      copy[rows + 1][column + 1].rgbtBlue +
                                                      copy[rows][column - 1].rgbtBlue +
                                                      copy[rows - 1][column].rgbtBlue +
                                                      copy[rows][column + 1].rgbtBlue +
                                                      copy[rows + 1][column].rgbtBlue +
                                                      copy[rows - 1][column + 1].rgbtBlue +
                                                      copy[rows + 1][column - 1].rgbtBlue) /
                                                     9.0);

                image[rows][column].rgbtRed = round((image[rows][column].rgbtRed +
                                                     copy[rows - 1][column - 1].rgbtRed +
                                                     copy[rows + 1][column + 1].rgbtRed +
                                                     copy[rows][column - 1].rgbtRed +
                                                     copy[rows - 1][column].rgbtRed +
                                                     copy[rows][column + 1].rgbtRed +
                                                     copy[rows + 1][column].rgbtRed +
                                                     copy[rows - 1][column + 1].rgbtRed +
                                                     copy[rows + 1][column - 1].rgbtRed) /
                                                    9.0);

                image[rows][column].rgbtGreen = round((image[rows][column].rgbtGreen +
                                                       copy[rows - 1][column - 1].rgbtGreen +
                                                       copy[rows + 1][column + 1].rgbtGreen +
                                                       copy[rows][column - 1].rgbtGreen +
                                                       copy[rows - 1][column].rgbtGreen +
                                                       copy[rows][column + 1].rgbtGreen +
                                                       copy[rows + 1][column].rgbtGreen +
                                                       copy[rows - 1][column + 1].rgbtGreen +
                                                       copy[rows + 1][column - 1].rgbtGreen) /
                                                      9.0);
            }
            else if ((rows != 0 && rows != (height - 1)) && column == 0)
            {
                image[rows][column].rgbtBlue = round((image[rows][column].rgbtBlue +
                                                      copy[rows - 1][column].rgbtBlue +     // above
                                                      copy[rows][column + 1].rgbtBlue +     // side
                                                      copy[rows + 1][column].rgbtBlue +     // down
                                                      copy[rows - 1][column + 1].rgbtBlue + // above side
                                                      copy[rows + 1][column + 1].rgbtBlue) /
                                                     6.0); // down side

                image[rows][column].rgbtRed = round((image[rows][column].rgbtRed +
                                                     copy[rows - 1][column].rgbtRed +     // above
                                                     copy[rows][column + 1].rgbtRed +     // side
                                                     copy[rows + 1][column].rgbtRed +     // down
                                                     copy[rows - 1][column + 1].rgbtRed + // above side
                                                     copy[rows + 1][column + 1].rgbtRed) /
                                                    6.0); // down side

                image[rows][column].rgbtGreen = round((image[rows][column].rgbtGreen +
                                                       copy[rows - 1][column].rgbtGreen +     // above
                                                       copy[rows][column + 1].rgbtGreen +     // side
                                                       copy[rows + 1][column].rgbtGreen +     // down
                                                       copy[rows - 1][column + 1].rgbtGreen + // above side
                                                       copy[rows + 1][column + 1].rgbtGreen) /
                                                      6.0); // down side
            }
            else if ((rows != 0 && rows != (height - 1)) && column == (width - 1))
            {
                image[rows][column].rgbtBlue = round((image[rows][column].rgbtBlue +
                                                      copy[rows - 1][column].rgbtBlue +     // above
                                                      copy[rows][column - 1].rgbtBlue +     // side
                                                      copy[rows + 1][column].rgbtBlue +     // down
                                                      copy[rows - 1][column - 1].rgbtBlue + // above side
                                                      copy[rows + 1][column - 1].rgbtBlue) /
                                                     6.0); // down side

                image[rows][column].rgbtRed = round((image[rows][column].rgbtRed +
                                                     copy[rows - 1][column].rgbtRed +     // above
                                                     copy[rows][column - 1].rgbtRed +     // side
                                                     copy[rows + 1][column].rgbtRed +     // down
                                                     copy[rows - 1][column - 1].rgbtRed + // above side
                                                     copy[rows + 1][column - 1].rgbtRed) /
                                                    6.0); // down side
                image[rows][column].rgbtGreen = round((image[rows][column].rgbtGreen +
                                                       copy[rows - 1][column].rgbtGreen +     // above
                                                       copy[rows][column - 1].rgbtGreen +     // side
                                                       copy[rows + 1][column].rgbtGreen +     // down
                                                       copy[rows - 1][column - 1].rgbtGreen + // above side
                                                       copy[rows + 1][column - 1].rgbtGreen) /
                                                      6.0); // down side
            }

            else if ((column != 0 && column != (width - 1)) && rows == 0)
            {
                image[rows][column].rgbtBlue = round((image[rows][column].rgbtBlue +
                                                      copy[rows][column - 1].rgbtBlue +     // sideleft
                                                      copy[rows][column + 1].rgbtBlue +     // sideright
                                                      copy[rows + 1][column].rgbtBlue +     // down
                                                      copy[rows + 1][column - 1].rgbtBlue + // down left
                                                      copy[rows + 1][column + 1].rgbtBlue) /
                                                     6.0); // down right
                image[rows][column].rgbtRed = round((image[rows][column].rgbtRed +
                                                     copy[rows][column - 1].rgbtRed +     // sideleft
                                                     copy[rows][column + 1].rgbtRed +     // sideright
                                                     copy[rows + 1][column].rgbtRed +     // down
                                                     copy[rows + 1][column - 1].rgbtRed + // down left
                                                     copy[rows + 1][column + 1].rgbtRed) /
                                                    6.0); // down right
                image[rows][column].rgbtGreen = round((image[rows][column].rgbtGreen +
                                                       copy[rows][column - 1].rgbtGreen +     // sideleft
                                                       copy[rows][column + 1].rgbtGreen +     // sideright
                                                       copy[rows + 1][column].rgbtGreen +     // down
                                                       copy[rows + 1][column - 1].rgbtGreen + // down left
                                                       copy[rows + 1][column + 1].rgbtGreen) /
                                                      6.0); // down right
            }
            else if ((column != 0 && column != (width - 1)) && rows == (height - 1))
            {
                image[rows][column].rgbtBlue = round((image[rows][column].rgbtBlue +
                                                      copy[rows][column - 1].rgbtBlue +     // sideleft
                                                      copy[rows][column + 1].rgbtBlue +     // sideright
                                                      copy[rows - 1][column].rgbtBlue +     // up
                                                      copy[rows - 1][column - 1].rgbtBlue + // up left
                                                      copy[rows - 1][column + 1].rgbtBlue) /
                                                     6.0); // up right

                image[rows][column].rgbtRed = round((image[rows][column].rgbtRed +
                                                     copy[rows][column - 1].rgbtRed +     // sideleft
                                                     copy[rows][column + 1].rgbtRed +     // sideright
                                                     copy[rows - 1][column].rgbtRed +     // up
                                                     copy[rows - 1][column - 1].rgbtRed + // up left
                                                     copy[rows - 1][column + 1].rgbtRed) /
                                                    6.0); // up right

                image[rows][column].rgbtGreen = round((image[rows][column].rgbtGreen +
                                                       copy[rows][column - 1].rgbtGreen +     // sideleft
                                                       copy[rows][column + 1].rgbtGreen +     // sideright
                                                       copy[rows - 1][column].rgbtGreen +     // up
                                                       copy[rows - 1][column - 1].rgbtGreen + // up left
                                                       copy[rows - 1][column + 1].rgbtGreen) /
                                                      6.0); // up right
            }
            else if (column == 0 && rows == 0)
            {
                image[rows][column].rgbtBlue =
                    round((image[rows][column].rgbtBlue +
                           copy[rows][column + 1].rgbtBlue + // side
                           copy[rows + 1][column].rgbtBlue + // down
                           copy[rows + 1][column + 1].rgbtBlue) /
                          4.0); // down side

                image[rows][column].rgbtRed = round((image[rows][column].rgbtRed +
                                                     copy[rows][column + 1].rgbtRed + // side
                                                     copy[rows + 1][column].rgbtRed + // down

                                                     copy[rows + 1][column + 1].rgbtRed) /
                                                    4.0); // down side
                image[rows][column].rgbtGreen = round((image[rows][column].rgbtGreen +
                                                       copy[rows][column + 1].rgbtGreen + // side
                                                       copy[rows + 1][column].rgbtGreen + // down

                                                       copy[rows + 1][column + 1].rgbtGreen) /
                                                      4.0); // down side
            }
            else if (column == (width - 1) && rows == 0)
            {
                image[rows][column].rgbtBlue =
                    round((image[rows][column].rgbtBlue +
                           copy[rows][column - 1].rgbtBlue + // side
                           copy[rows + 1][column].rgbtBlue + // down
                           copy[rows + 1][column - 1].rgbtBlue) /
                          4.0); // down side

                image[rows][column].rgbtRed = round((image[rows][column].rgbtRed +
                                                     copy[rows][column - 1].rgbtRed + // side
                                                     copy[rows + 1][column].rgbtRed + // down

                                                     copy[rows + 1][column - 1].rgbtRed) /
                                                    4.0); // down side
                image[rows][column].rgbtGreen = round((image[rows][column].rgbtGreen +
                                                       copy[rows][column - 1].rgbtGreen + // side
                                                       copy[rows + 1][column].rgbtGreen + // down

                                                       copy[rows + 1][column - 1].rgbtGreen) /
                                                      4.0); // down side
            }
            else if (column == 0 && rows == (height - 1))
            {
                image[rows][column].rgbtBlue =
                    round((image[rows][column].rgbtBlue +
                           copy[rows][column + 1].rgbtBlue + // side
                           copy[rows - 1][column].rgbtBlue + // down
                           copy[rows - 1][column + 1].rgbtBlue) /
                          4.0); // down side

                image[rows][column].rgbtRed = round((image[rows][column].rgbtRed +
                                                     copy[rows][column + 1].rgbtRed + // side
                                                     copy[rows - 1][column].rgbtRed + // down

                                                     copy[rows - 1][column + 1].rgbtRed) /
                                                    4.0); // down side

                image[rows][column].rgbtGreen = round((image[rows][column].rgbtGreen +
                                                       copy[rows][column + 1].rgbtGreen + // side
                                                       copy[rows - 1][column].rgbtGreen + // down

                                                       copy[rows - 1][column + 1].rgbtGreen) /
                                                      4.0); // down side
            }
            else if (column == (width - 1) && rows == (height - 1))
            {
                image[rows][column].rgbtBlue =
                    round((image[rows][column].rgbtBlue +
                           copy[rows][column - 1].rgbtBlue + // side
                           copy[rows - 1][column].rgbtBlue + // down
                           copy[rows - 1][column - 1].rgbtBlue) /
                          4.0); // down side

                image[rows][column].rgbtRed = round((image[rows][column].rgbtRed +
                                                     copy[rows][column - 1].rgbtRed + // side
                                                     copy[rows - 1][column].rgbtRed + // down

                                                     copy[rows - 1][column - 1].rgbtRed) /
                                                    4.0); // down side
                image[rows][column].rgbtGreen = round((image[rows][column].rgbtGreen +
                                                       copy[rows][column - 1].rgbtGreen + // side
                                                       copy[rows - 1][column].rgbtGreen + // down

                                                       copy[rows - 1][column - 1].rgbtGreen) /
                                                      4.0); // down side
            }
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    /*int gx_s_rgbtRed = 0;
    int gx_s_rgbtBlue = 0;
    int gx_s_rgbtGreen = 0;
    int gy_s_rgbtRed = 0;
    int gy_s_rgbtBlue = 0;
    int gy_s_rgbtGreen = 0;*/
    RGBint gx_s;
    RGBint gy_s;

    RGBTRIPLE copy[height][width];
    for (int x = 0; x < height; x++)
    {
        for (int y = 0; y < width; y++)
        {
            copy[x][y] = image[x][y];
        }
    }
    int gx[3][3] = {{-1, 0, 1},
                    {-2, 0, 2},
                    {-1, 0, 1}};

    int gy[3][3] = {{-1, -2, -1},
                    {0, 0, 0},
                    {1, 2, 1}};

    for (int rows = 0; rows < height; rows++)
    {
        for (int columns = 0; columns < width; columns++)
        {
            int x = 0;
            for (int r = (rows - 1); r <= (rows + 1); r++)
            {
                int y = 0;
                for (int c = (columns - 1); c <= (columns + 1); c++)
                {
                    if (r >= 0 && r < height && c >= 0 && c < width)
                    {
                        // getting gx*pixel

                        gx_s.rgbtRed += gx[x][y] * copy[r][c].rgbtRed;
                        gx_s.rgbtGreen += gx[x][y] * copy[r][c].rgbtGreen;
                        gx_s.rgbtBlue += gx[x][y] * copy[r][c].rgbtBlue;
                        // getting gy*pixel
                        gy_s.rgbtRed += gy[x][y] * copy[r][c].rgbtRed;
                        gy_s.rgbtGreen += gy[x][y] * copy[r][c].rgbtGreen;
                        gy_s.rgbtBlue += gy[x][y] * copy[r][c].rgbtBlue;
                    }
                    y++;
                }

                x++;
                if (round(sqrt(sqr(gx_s.rgbtGreen) + sqr(gy_s.rgbtGreen))) > 0xff)
                {
                    image[rows][columns].rgbtGreen = 0xff;
                }
                else
                {
                    image[rows][columns].rgbtGreen = round(sqrt(sqr(gx_s.rgbtGreen) + sqr(gy_s.rgbtGreen)));
                }

               if ((BYTE)round(sqrt(sqr(gx_s.rgbtRed) + sqr(gy_s.rgbtRed))) > 0xff)
                {
                    image[rows][columns].rgbtRed = 0xff;
                }
                else
                {
                    image[rows][columns].rgbtRed = round(sqrt(sqr(gx_s.rgbtRed) + sqr(gy_s.rgbtRed)));
                }

                if (round(sqrt(sqr(gx_s.rgbtBlue) + sqr(gy_s.rgbtBlue) )) > 0xff)
                {
                    image[rows][columns].rgbtBlue = 0xff;
                }
                else
                {
                    image[rows][columns].rgbtBlue = round(sqrt(sqr(gx_s.rgbtBlue) + sqr(gy_s.rgbtBlue)));
                }
            }
            gx_s.rgbtRed = 0;
            gx_s.rgbtGreen = 0;
            gx_s.rgbtBlue = 0;
            gy_s.rgbtRed = 0;
            gy_s.rgbtBlue = 0;
            gy_s.rgbtGreen = 0;
        }
    }

    return;
}
