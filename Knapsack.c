#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapSack(int capacity, int wt[], int val[], int n) {
    if (n == 0 || capacity == 0) return 0;
    return max(val[n-1] + knapSack(capacity-wt[n-1], wt, val, n-1),
               knapSack(capacity, wt, val, n-1));
}

int main() {
    int capacity, s;
    printf("Enter Capacity and size of array:\n");
    scanf("%d%d", &capacity, &s);
    int profit[s], weight[s];
    printf("Enter %d Profit and Weight values:\n", s);
    for (int i = 0; i < s; ++i) scanf("%d%d", &profit[i], &weight[i]);
    printf("Max Profit = %d", knapSack(capacity, weight, profit, s));
    return 0;
}
