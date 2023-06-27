#include <stdio.h>

int main() {
    int n = 6, count = 0, ccount = 0;
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min_index]) {
                min_index = j;
            }
            ccount++;
        }
        if (min_index != i) {
            int temp = a[i];
            a[i] = a[min_index];
            a[min_index] = temp;
            count++;
        }
    }
    printf("Sorted Array:");
    for (int i = 0; i < n; i++) {
        printf(" %d", a[i]);
    }
    printf("\nNo of swappings: %d\nNo of comparisons: %d", count, ccount);
    return 0;
}
