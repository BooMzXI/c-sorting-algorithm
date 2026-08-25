#include <stdio.h>

void quick_sort(int arr[], int lenght);
void quick_recursive(int arr[], int left, int right);
int partition(int arr[], int left, int right);
void swap(int *a, int *b);

// int main()
// {
//     int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
//     int lenght = sizeof(arr) / sizeof(arr[0]);
//     quick_sort(arr, lenght);

//     for (int i = 0; i < lenght; i++)
//     {
//         printf("%d", arr[i]);
//     }
//     printf("\n");

//     return (0);
// }

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void quick_sort(int arr[], int lenght)
{
    quick_recursive(arr, 0, lenght - 1);
}
void quick_recursive(int arr[], int left, int right)
{

    if (left < right)
    {
        int pivot = partition(arr, left, right);
        quick_recursive(arr, left, pivot - 1);
        quick_recursive(arr, pivot + 1, right);
    }
}

int partition(int arr[], int left, int right)
{
    int pivot = arr[left];
    int i = left, j = right;
    while (i < j)
    {
        while (i<right&&arr[i] <= pivot)
        {
            i++;
        }
        while (j>left&&arr[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[left], &arr[j]);
    return (j);
}