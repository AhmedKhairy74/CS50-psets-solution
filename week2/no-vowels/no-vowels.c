// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>

string replace(string input);

int main(int argc, string argv[])
{
    if (argc < 2)
    {
        printf("Usage: ./no-vowels word\n");
        return 1;
    }

    for (int i = 1; i < argc; i++)
    {
        printf("%s ", replace(argv[i]));
    }

    printf("\n");
}

string replace(string input)
{
    int n = strlen(input);
    for (int i = 0; i < n; i++)
    {
        switch (input[i])
        {
            case ('i'):
                input[i] = '1';
                break;
            case ('a'):
                input[i] = '6';
                break;
            case ('o'):
                input[i] = '0';
                break;
            case ('e'):
                input[i] = '3';
                break;
        }
    }
    return input;
}
