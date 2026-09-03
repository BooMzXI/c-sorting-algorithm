#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void quick_sort(int arr[], int lenght);
void quick_recursive(int arr[], int left, int right);
int partition(int arr[], int left, int right);
void swap(int *a, int *b);
void quick_sort_randomP(int arr[], int lenght);
void quick_recursive_randomP(int arr[], int left, int right);

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

void quick_sort_randomP(int arr[], int lenght)
{
    quick_recursive_randomP(arr, 0, lenght - 1);
}
void quick_recursive_randomP(int arr[], int left, int right)
{
    if (left < right)
    {
        srand(time(NULL));
        // ----------------------------------------------------
        // ส่วนที่เพิ่มเข้ามา: สุ่ม Pivot
        // สุ่ม index ให้อยู่ในช่วง [left, right]
        int random_index = left + rand() % (right - left + 1);

        // สลับค่าที่สุ่มได้ ไปไว้ตำแหน่งซ้ายสุด (left)
        // เพื่อให้ฟังก์ชัน partition ทำงานได้ตามปกติเหมือนเดิม
        swap(&arr[left], &arr[random_index]);

        if (left < right)
        {
            int pivot = partition(arr, left, right);
            quick_recursive_randomP(arr, left, pivot - 1);
            quick_recursive_randomP(arr, pivot + 1, right);
        }
    }
}