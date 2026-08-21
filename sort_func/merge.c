#include <stdio.h>
void merge_sort(int arr[], int lenght);
void merge_recursive(int arr[], int left, int right);
void final_merge(int arr[], int left, int middle, int right);


int main()
{

    int arr[] = {0, 2, 4, 5, 9, 7, 1};
    int lenght = sizeof(arr) / sizeof(arr[0]);
    merge_sort(arr, lenght);

    for (int i = 0; i < lenght; i++)
    {
        printf("%d", arr[i]);
    }
    printf("\n");

    return (0);
}

void merge_sort(int arr[], int lenght)
{ // send index
    merge_recursive(arr, 0, lenght - 1);
}
void merge_recursive(int arr[], int left, int right)
{
    if (left < right)
    {
        int middle = left + (right - left) / 2;

        merge_recursive(arr, left, middle);
        merge_recursive(arr, middle + 1, right);

        final_merge(arr, left, middle, right);
    }
}

void final_merge(int arr[], int left, int middle, int right)
{
    int left_lenght = middle - left + 1;
    int right_lenght = right - middle;

    int temp_left[left_lenght], temp_right[right_lenght];
    int i, j, k;

    for (int i = 0; i < left_lenght; i++)
    {
        temp_left[i] = arr[left+i];
    }
    for (int i = 0; i < right_lenght; i++)
    {
        temp_right[i] = arr[middle + 1 + i];
    }

    for (i = 0, j = 0, k = left; k <= right; k++)
    {
        if (i < left_lenght && (j >= right_lenght || temp_left[i] < temp_right[j]))
        {
            arr[k] = temp_left[i];
            i++;
        }
        else{
            arr[k] = temp_right[j];
            j++;
        }
    }
}
