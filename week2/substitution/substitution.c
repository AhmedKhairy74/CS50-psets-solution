#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

string sub(string input, string key);
bool invalid(string key);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    if(invalid(argv[1]))
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    string input = get_string("plaintext: ");
    printf("ciphertext: %s\n", sub(input, argv[1]));
}

string sub(string input, string key)
{
    int n = strlen(input);
    string cipher = input;
    for (int i = 0; i < n; i++)
    {
        if (islower(input[i]))
        {
            cipher[i] = tolower(key[(int) (input[i] - 97)]);
        }
        else if (isupper(input[i]))
        {
            cipher[i] = toupper(key[(int) (input[i] - 65)]);
        }
    }
    return cipher;
}

bool invalid(string key)
{
    int occ = 0;
    for (int i = 0; i < 26; i++)
    {
        occ = 0;
        for(int j = 0; j < 26; j++)
        {
            if (tolower(key[i]) == tolower(key[j]))
            {
                occ++;
            }
        }
        if(occ > 1)
        {
            return true;
        }
        if (!isalpha(key[i]))
        {
            return true;
        }
    }
    return false;
}