#include <stdio.h>

void BubbleSort(int a[], int n) {
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-i-1; j++) {
            if(a[j]>a[j+1]) {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

int main() {
    int mock[10] = {5, 1, 4, 2, 8};
    BubbleSort(mock, 5);
    for(int i=0; i<5; i++) {
        printf("%d ", mock[i]);
    }
    return 0;
}