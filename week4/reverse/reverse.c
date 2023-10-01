#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "wav.h"

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    // TODO #1
    if (argc != 3)
    {
        printf("Usage: ./reverse INPUT OUTPUT\n");
        return 1;
    }

    // Open input file for reading
    // TODO #2
    char *infile = argv[1];
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open file\n");
        return 1;
    }

    // Read header
    // TODO #3
    WAVHEADER *wh = (WAVHEADER *) malloc(sizeof(WAVHEADER));
    fread(wh, sizeof(WAVHEADER), 1, inptr);

    // Use check_format to ensure WAV format
    // TODO #4
    if (check_format(*wh))
    {
        printf("wave\n");
    }

    // Open output file for writing
    // TODO #5
    char *output = argv[2];
    FILE *outptr = fopen(output, "w");
    if (outptr == NULL)
    {
        printf("Could not open file\n");
        return 1;
    }

    // Write header to file
    // TODO #6
    fwrite(wh, sizeof(WAVHEADER), 1, outptr);

    // Use get_block_size to calculate size of block
    // TODO #7
    int block_size = get_block_size(*wh);

    // Write reversed audio to file
    // TODO #8
    long long int i = 1;
    int *block_out = (int *) malloc(block_size);
    while (fread(&block_out[i - 1], block_size, 1, inptr) == 1)
    {
        i++;
        block_out = (int *) realloc(block_out, (block_size) *i);
    }

    for (long long int j = i - 2; j >= 0; j--)
    {
        fwrite(&block_out[j], (block_size), 1, outptr);
    }

    // free(block_in);
    free(block_out);
    free(wh);
    fclose(outptr);
    fclose(inptr);
}

int check_format(WAVHEADER header)
{
    // TODO #4
    if (header.format[0] == 'W' && header.format[1] == 'A' && header.format[2] == 'V' && header.format[3] == 'E')
    {
        return 1;
    }
    return 0;
}

int get_block_size(WAVHEADER header)
{
    // TODO #7
    return (header.numChannels * (header.bitsPerSample / 8));
}