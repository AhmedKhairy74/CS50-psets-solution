#include <cs50.h>
#include <stdio.h>
#include <string.h>

void bi_search(int target, int start, int end, int middle, int data[]);
void li_search(int target, int data[], int len);

int main(int argc, string argv[])
{
    // binary search
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    int num = get_int("Enter a number: \n");
    if (strcmp(argv[1], "b"))
    {
        bi_search(num, 0, 15, 7, array);
    }
    else if (strcmp(argv[1], "l"))
    {
        li_search(num, array, 16);
    }
    else
    {
        return 1;
    }

}

void bi_search(int target, int start, int end, int middle, int data[])
{
    if (data[middle] == target)
    {
        printf("element is found at index %i\n", middle);
        return;
    }
    else if (start > end)
    {
        printf("element is not found \n");
        return;
    }
    else if (target < data[middle])
    {
        end = middle - 1;
    }
    else if (target > data[middle])
    {
        start = middle + 1;
    }
    return bi_search(target, start, end, (end + start) / 2, data);
}

void li_search(int target, int data[], int len)
{
    for (int i = 0; i < len; i++)
    {
        if (data[i] == target)
        {
            printf("element is found at index %i\n", i);
            return;
        }
    }
    printf("element is not found \n");
    return;
}



