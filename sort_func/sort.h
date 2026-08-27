#ifndef SORT_H
#define SORT_H

#include "bubble-sort.c"
#include "insertion-sort.c"
#include "merge.c"
#include "quick.c"
#include "selection-sort.c"

void merge_sort(int arr[], int lenght);
void quick_sort(int arr[], int lenght);
void SelectionSort(int arr[], int n);
void InsertionSort(int a[], int n);
void BubbleSort(int a[], int n);

#endif