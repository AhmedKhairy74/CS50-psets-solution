#include <ctype.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    char *infile = argv[1];

    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s\n", infile);
        return 1;
    }

    uint8_t *readJPG = (uint8_t *) malloc(512 * sizeof(char));
    if (readJPG == NULL)
    {
        printf("Could not allocate memory\n");
        fclose(inptr);
        return 1;
    }

    int num = 0;
    char *outfile = (char *) malloc(8 * sizeof(char));

    sprintf(outfile, "%03i.jpg", num);


    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        printf("Could not open %s\n", outfile);
        return 1;
    }

    while (fread(readJPG, sizeof(uint8_t), 512, inptr) == 512)
    {
        if ((readJPG[0]) == 0xff && (readJPG[1]) == 0xd8 && (readJPG[2]) == 0xff && ((readJPG[3]) >= 0xe0 && readJPG[3] <= 0xef))
        {
            if (num == 0)
            {
                fwrite(readJPG, sizeof(uint8_t), 512, outptr);
                num++;
            }
            else
            {

                fclose(outptr);
                sprintf(outfile, "%03i.jpg", num);
                outptr = fopen(outfile, "w");
                if (outptr == NULL)
                {
                    printf("Could not open %s\n", outfile);
                    return 1;
                }
                fwrite(readJPG, sizeof(uint8_t), 512, outptr);
                num++;
            }
        }
        else
        {
            if (num != 0)
            {
                fwrite(readJPG, sizeof(char), 512, outptr);
            }
        }
    }

    free(readJPG);
    free(outfile);
    fclose(inptr);
    fclose(outptr);

    return 0;
}