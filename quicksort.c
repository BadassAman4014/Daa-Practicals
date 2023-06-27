#include <stdio.h>
#include <stdlib.h>

#define SWAP(x, y) { int temp = x; x = y; y = temp; }
// Function to partition the array using the last element as pivot
int partition(int arr[], int low, int high, int* swaps) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            SWAP(arr[i], arr[j]);
            (*swaps)++;
        }
    }
    SWAP(arr[i + 1], arr[high]);
    (*swaps)++;
    return (i + 1);
}
// Function to perform Quick Sort on the array
void quickSort(int arr[], int low, int high, int* swaps, int* iterations) {
    if (low >= high) {
        return;
    }
    (*iterations)++;
    // Partition the array and get the partition index
    int pi = partition(arr, low, high, swaps);

    // Recur for the left and right subarrays
    quickSort(arr, low, pi - 1, swaps, iterations);
    quickSort(arr, pi + 1, high, swaps, iterations);
}

int main() {
    int n, *arr, swaps = 0, iterations = 0;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    arr = (int*) malloc(n * sizeof(int));

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Input Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    quickSort(arr, 0, n - 1, &swaps, &iterations);
    printf("\n");

    printf("Sorted Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Number of Swaps: %d\n", swaps);
    printf("Number of Iterations: %d\n", iterations);

    free(arr);
    return 0;
}
