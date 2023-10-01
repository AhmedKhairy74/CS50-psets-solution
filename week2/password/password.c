// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    int count_low = 0, count_up = 0, count_sy = 0, count_num = 0;
    int n = strlen(password);
    for (int i = 0; i < n; i++)
    {
        if (islower(password[i]))
        {
            count_low++;
        }
        else if (isupper(password[i]))
        {
            count_up++;
        }
        else if (isdigit(password[i]))
        {
            count_num++;
        }
        else
        {
            count_sy++;
        }
    }

    if (count_low >= 1 && count_up >= 1 && count_num >= 1 && count_sy >= 1)
    {
        return true;
    }
    return false;
}
