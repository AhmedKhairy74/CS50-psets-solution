#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letter(string input);
int count_word(string input);
int count_sentences(string input);
int grade(int L, int W, int S);

int main(void)
{
    string input = get_string("Text: ");
    int L = count_letter(input);
    int W = count_word(input);
    int S = count_sentences(input);
    int g = grade(L, W, S);
    if (g > 16)
    {
        printf("Grade 16+\n");
    }
    else if (g < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", g);
    }
}

int count_word(string input)
{
    int words = 0;
    int n = strlen(input);
    for (int i = 1; i <= n; i++)
    {
        if (input[i] == 32 && input[i - 1] != 32)
        {
            words++;
        }
        else if (input[i] == '\0' && input[i - 1] != 32)
        {
            words++;
        }
    }
    return words;
}

int count_letter(string input)
{
    int n = strlen(input);
    int letters = 0;
    for (int i = 0; i < n; i++)
    {
        if (tolower(input[i]) < 123 && tolower(input[i]) > 96)
        {
            letters++;
        }
    }
    return letters;
}

int count_sentences(string input)
{
    int n = strlen(input);
    int sent = 0;
    for (int i = 0; i < n; i++)
    {
        if (input[i] == '.' || input[i] == '?' || input[i] == '!')`
        {
            sent++;
        }
    }
    return sent;
}

int grade(int L, int W, int S)
{
    float L_av = ((float) L / (float) W) * 100;
    float S_av = ((float) S / (float) W) * 100;
    int grade = round(0.0588 * L_av - 0.296 * S_av - 15.8);
    return grade;
}