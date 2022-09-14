#include "helpers.h"
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
                    image[rows][column].rgbtGreen)/3 ;
            image[rows][column].rgbtBlue=temp;
            image[rows][column].rgbtRed=temp;
            image[rows][column].rgbtGreen=temp;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
