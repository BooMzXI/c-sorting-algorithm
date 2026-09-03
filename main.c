#include <stdio.h>
#include "sort_func/sort.h"
#include <windows.h>
#include <string.h>
#include "data_set/random_data.c"
#include "data_set/reverse_data.c"
#include "data_set/sorted_data.c"
#include <stdlib.h>
#include <time.h>

int main()
{
    int sizes[6] = {100, 500, 1000, 5000, 10000, 50000};
    char *order_names[3] = {"random", "sorted", "reverse"};
    int *datasets[3][6] = {
        {data_100_random, data_500_random, data_1000_random, data_5000_random, data_10000_random, data_50000_random},
        {data_100_sorted, data_500_sorted, data_1000_sorted, data_5000_sorted, data_10000_sorted, data_50000_sorted},
        {data_100_reverse, data_500_reverse, data_1000_reverse, data_5000_reverse, data_10000_reverse, data_50000_reverse}};
    char *algo_names[6] = {"Insertion", "Selection", "Bubble", "Merge", "Quick","Quick_Random_Pivot"};

    LARGE_INTEGER frequency, start, end;
    double time_taken;
    QueryPerformanceFrequency(&frequency);

    srand(time(NULL));

    for (int type = 0; type < 3; type++)
    { // 3 type

        for (int dataset = 0; dataset < 6; dataset++)
        { // 6 dataset
            int *arr_to_sort = malloc(sizes[dataset] * sizeof(int));
            if (arr_to_sort == NULL)
            {
                printf("Memory allocation failed\n");
                return 1;
            }
            printf("%s %d\n", order_names[type], sizes[dataset]);
            for (int round = 0; round < 6; round++) // 5 sort
            {

                printf("%s\n", algo_names[round]);

                for (int i = 0; i < 10; i++) // 10 round
                {
                    for (int j = 0; j < sizes[dataset]; j++) //copy dataset array to dummy
                    {
                        arr_to_sort[j] = datasets[type][dataset][j];
                    }
                    if (round == 0) // insert
                    {
                        QueryPerformanceCounter(&start);
                        InsertionSort(arr_to_sort, sizes[dataset]);
                    }
                    else if (round == 1) // selection
                    {
                        QueryPerformanceCounter(&start);
                        SelectionSort(arr_to_sort, sizes[dataset]);
                    }
                    else if (round == 2) // bubble
                    {
                        QueryPerformanceCounter(&start);
                        BubbleSort(arr_to_sort, sizes[dataset]);
                    }
                    else if (round == 3) // merge
                    {
                        QueryPerformanceCounter(&start);
                        merge_sort(arr_to_sort, sizes[dataset]);
                    }
                    else if (round == 4) // quick
                    {
                        QueryPerformanceCounter(&start);
                        quick_sort(arr_to_sort, sizes[dataset]);
                    }
                    else if (round == 5) // quick
                    {
                        QueryPerformanceCounter(&start);
                        quick_sort_randomP(arr_to_sort, sizes[dataset]);
                    }
                    
                    QueryPerformanceCounter(&end);
                    time_taken = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;
                    printf("%.9f\n", time_taken * 1000); // millisec
                }
                printf("-------------------------------------------\n");
            }
            free(arr_to_sort);
        }
    }
    return 0;
}