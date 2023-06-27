#include <stdio.h>
void swap(int* a, int* b) { int t = *a; *a = *b; *b = t; }
void heapify(int arr[], int n, int i) {
    int l = 2 * i + 1, r = 2 * i + 2, largest = i;
    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;
    if (largest != i) swap(&arr[i], &arr[largest]), heapify(arr, n, largest);
}
void heapSortAsc(int arr[], int n) {
    for (int i = n/2 - 1; i >= 0; i--) heapify(arr, n, i);
    for (int i = n-1; i >= 0; i--) swap(&arr[0], &arr[i]), heapify(arr, i, 0);
}
void heapSortDesc(int arr[], int n) {
    for (int i = n/2 - 1; i >= 0; i--) heapify(arr, n, i);
    for (int i = 0; i < n-1; i++) swap(&arr[0], &arr[n-i-1]), heapify(arr, n-i-1, 0);
}
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
 
    printf("Original array: ");
    for (int i = 0; i < n; ++i) printf("%d ", arr[i]); printf("\n");

    heapSortAsc(arr, n);
    printf("Ascending order sorted array: ");
    for (int i = 0; i < n; ++i) printf("%d ", arr[i]); printf("\n");

    heapSortDesc(arr, n);
    printf("Descending order sorted array: ");
    for (int i = 0; i < n; ++i) printf("%d ", arr[i]); printf("\n");

    return 0;
}
