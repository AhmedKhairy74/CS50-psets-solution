#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int total = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            total = image[i][j].rgbtGreen + image[i][j].rgbtRed + image[i][j].rgbtBlue;
            image[i][j].rgbtGreen = total / 3;
            image[i][j].rgbtBlue = total / 3;
            image[i][j].rgbtRed = total / 3;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE temp;
            temp = image[i][width - j - 1];
            image[i][width - j - 1] = image[i][j];
            image[i][j] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            int hei = 1, wid = 1, avg = 0, end_h = -1, end_d = -1;
            RGBTRIPLE temp = image[i][j];
            image[i][j].rgbtRed = 0; image[i][j].rgbtBlue = 0; image[i][j].rgbtGreen = 0;

            if (i == height)
            {
                hei = 0;
            }
            else if (i == 0)
            {
                end_h = 0;
            }

            if (j == width)
            {
                wid = 0;
            }
            else if (j == 0)
            {
                end_h = 0;
            }

            for (int h = hei; h >= end_h; h--)
            {
                for (int d = wid; d >= end_d; d--)
                {
                    avg++;
                    image[i][j].rgbtRed += image[i + h][j + d].rgbtRed; image[i][j].rgbtGreen += image[i + h][j + d].rgbtGreen; image[i][j].rgbtBlue += image[i + h][j + d].rgbtBlue;
                }
            }
            image[i][j].rgbtRed += temp.rgbtRed; image[i][j].rgbtGreen += temp.rgbtGreen; image[i][j].rgbtBlue += temp.rgbtBlue;
            image[i][j].rgbtRed /= (avg); image[i][j].rgbtGreen /= (avg); image[i][j].rgbtBlue /= (avg);

        }
    }
    return;
}
