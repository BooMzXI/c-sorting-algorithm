#include <stdio.h>
#include "sort_func/sort.h"
#include <windows.h>
#include <string.h>
#include "data_set/random_data.c"
#include "data_set/reverse_data.c"
#include "data_set/sorted_data.c"

int main()
{
    // test array random 1000 size
    char name[5][20] = {"Insertion", "Selection", "Bubble", "Merge", "Quick"} ;
    int *arr = data_200000_random;
    int lenght = len_200000_random;

    int *arr_to_sort = malloc(lenght * sizeof(int));
    if (arr_to_sort == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    LARGE_INTEGER frequency, start, end;
    double time_taken;
    QueryPerformanceFrequency(&frequency);
    for (int round = 0; round < 5; round++)
    {
        printf("%s\n", name[round]);

        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < lenght; j++)
            {
                arr_to_sort[j] = arr[j];
            }
            if (round == 0)
            {
                QueryPerformanceCounter(&start);
                InsertionSort(arr_to_sort, lenght);
            }
            else if (round == 1)
            {
                QueryPerformanceCounter(&start);
                SelectionSort(arr_to_sort, lenght);
            }
            else if (round == 2)
            {
                QueryPerformanceCounter(&start);
                BubbleSort(arr_to_sort, lenght);
            }
            else if (round == 3)
            {
                QueryPerformanceCounter(&start);
                merge_sort(arr_to_sort, lenght);
            }
            else if (round == 4)
            {
                QueryPerformanceCounter(&start);
                quick_sort(arr_to_sort, lenght);
            }

            QueryPerformanceCounter(&end);
            time_taken = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;
            printf("%.9f\n", time_taken*1000); //millisec
        }
        printf("-------------------------------------------\n");
    }

    return 0;
}