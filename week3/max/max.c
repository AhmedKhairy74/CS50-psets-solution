// Practice writing a function to find a max value

#include <cs50.h>
#include <stdio.h>

void sort(int array[], int n);
int max(int array[], int n);

int main(void)
{
    int n;
    do
    {
        n = get_int("Number of elements: ");
    }
    while (n < 1);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = get_int("Element %i: ", i);
    }

    sort(arr, n);

    for (int i = 0; i < n; i++)
    {
        printf("%i\n", arr[i]);
    }
    printf("The max value is %i.\n", max(arr, n));
}

void sort(int array[], int n)
{
    // if there is one elemet then array is already sorted
    if (n == 1)
    {
        return;
    }

    // divide array into two halfs
    int left = n / 2, right = n - (n / 2);
    int left_arr[left];
    int right_arr[right];
    printf("this is left: \n");
    for (int i = 0; i < left; i++)
    {
        left_arr[i] = array[i];
        printf(" %i ", left_arr[i]);
    }
    printf("\n");
    printf("this is right: \n");
    for (int i = 0; i < right; i++)
    {
        right_arr[i] = array[i + left];
        printf(" %i ", right_arr[i]);
    }
    printf("\n");

    // sort left half
    sort(left_arr, left);

    // sort right half
    sort(right_arr, right);

    // Merge
    int j = 0, k = 0, i = 0;

    while (i < n)
    {
        if (j < left && (k >= right || left_arr[j] < right_arr[k]))
        {
            array[i] = left_arr[j];
            j++;
        }
        else
        {
            array[i] = right_arr[k];
            k++;
        }
        i++;
    }

    return;
}

// TODO: return the max value
int max(int array[], int n)
{
    int max = array[0];
    for (int i = 0; i < n; i++)
    {
        if (max < array[i])
        {
            max = array[i];
        }
    }
    return max;
}
