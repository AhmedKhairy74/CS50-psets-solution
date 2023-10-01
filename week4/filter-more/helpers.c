#include "helpers.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int total = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            total = image[i][j].rgbtGreen + image[i][j].rgbtRed + image[i][j].rgbtBlue;
            image[i][j].rgbtGreen = round(total / 3.0);
            image[i][j].rgbtBlue = round(total / 3.0);
            image[i][j].rgbtRed = round(total / 3.0);
        }
    }
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
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            int hit = 1, wid = 1, start_h = -1, start_d = -1;
            double avg = 0;
            int red = 0, green = 0, blue = 0;

            if (i == (height - 1))
            {
                hit = 0;
            }
            else if (i == 0)
            {
                start_h = 0;
            }

            if (j == (width - 1))
            {
                wid = 0;
            }
            else if (j == 0)
            {
                start_d = 0;
            }

            for (int h = start_h; h <= hit; h++)
            {
                for (int d = start_d; d <= wid; d++)
                {

                    avg++;
                    red += image[i + h][j + d].rgbtRed;
                    green += image[i + h][j + d].rgbtGreen;
                    blue += image[i + h][j + d].rgbtBlue;
                }
            }

            temp[i][j].rgbtRed = round(red / (avg));
            temp[i][j].rgbtGreen = round(green / (avg));
            temp[i][j].rgbtBlue = round(blue / (avg));
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
        }
    }

    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{

    RGBTRIPLE temp[height][width];
    int x_w[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int y_w[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            int hit = 1, wid = 1, start_h = -1, start_d = -1;
            int y_red = 0, y_green = 0, y_blue = 0, x_red = 0, x_green = 0, x_blue = 0;
            ;

            if (i == (height - 1))
            {
                hit = 0;
            }
            else if (i == 0)
            {
                start_h = 0;
            }

            if (j == (width - 1))
            {
                wid = 0;
            }
            else if (j == 0)
            {
                start_d = 0;
            }

            // loop for Gx
            for (int h = start_h; h <= hit; h++)
            {
                for (int d = start_d; d <= wid; d++)
                {
                    x_red += image[i + h][j + d].rgbtRed * x_w[h + 1][d + 1];
                    x_green += image[i + h][j + d].rgbtGreen * x_w[h + 1][d + 1];
                    x_blue += image[i + h][j + d].rgbtBlue * x_w[h + 1][d + 1];
                }
            }

            // loop for Gy
            for (int h = start_h; h <= hit; h++)
            {
                for (int d = start_d; d <= wid; d++)
                {
                    y_red += image[i + h][j + d].rgbtRed * y_w[h + 1][d + 1];
                    y_green += image[i + h][j + d].rgbtGreen * y_w[h + 1][d + 1];
                    y_blue += image[i + h][j + d].rgbtBlue * y_w[h + 1][d + 1];
                }
            }

            if (round(sqrt((x_red * x_red) + (y_red * y_red))) < 256)
            {
                temp[i][j].rgbtRed = round(sqrt((x_red * x_red) + (y_red * y_red)));
            }
            else
            {
                temp[i][j].rgbtRed = 255;
            }
            if (round(sqrt((x_green * x_green) + (y_green * y_green))) < 256)
            {
                temp[i][j].rgbtGreen = round(sqrt((x_green * x_green) + (y_green * y_green)));
            }
            else
            {
                temp[i][j].rgbtGreen = 255;
            }
            if (round(sqrt((x_blue * x_blue) + (y_blue * y_blue))) < 256)
            {
                temp[i][j].rgbtBlue = round(sqrt((x_blue * x_blue) + (y_blue * y_blue)));
            }
            else
            {
                temp[i][j].rgbtBlue = 255;
            }
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
        }
    }

    return;
}
