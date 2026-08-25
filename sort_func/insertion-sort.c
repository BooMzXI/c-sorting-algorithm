#include <stdio.h>

void InsertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}

// int main() {
//     int mock[10] = {5, 1, 4, 2, 8};
//     InsertionSort(mock, 5);
//     for(int i=0; i<5; i++) {
//         printf("%d ", mock[i]);
//     }
//     return 0;
// }
