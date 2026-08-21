#include <stdio.h> 

void SelectionSort(int arr[], int n) {
    for (int i=0;i<n;i++) {
        int minIndex = i;
        for (int j=i+1;j<n;j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }   
    }
}

int main() {
    int mock[10] = {1, 5, 7, 3, 8, 4, 0, 9, 1};
    SelectionSort(mock, 9);
    for(int i=0; i<9; i++) {
        printf("%d ", mock[i]);
    }
    return 0;
}