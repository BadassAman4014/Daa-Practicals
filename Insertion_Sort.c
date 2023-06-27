#include<stdio.h>

void insertionSort(int arr[], int n) {
    int i, j, temp, swaps = 0, comps = 0;
    for (i = 1; i < n; i++) {
        temp = arr[i];
        for (j = i - 1; j >= 0 && temp < arr[j]; j--) {
            arr[j + 1] = arr[j];
            swaps++;
            comps++;
        }
        arr[j + 1] = temp;
        swaps++;
    }
    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nNo of swappings: %d\nNo of comparisons: %d\n", swaps, comps);
}

int main() {
    int n, i;
    scanf("%d", &n);
    int arr[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    insertionSort(arr, n);
    return 0;
}
