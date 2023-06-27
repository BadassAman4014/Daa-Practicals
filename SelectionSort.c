#include <stdio.h>
int main()
{
    int n = 6;
    int count=0;
    int ccount=0;
    int a[n];
    for (int i = 0; i < n; i++) 
    {
        scanf("%d",&a[i]);
    }
    int min_index;
    for(int i = 0; i < n - 1; i++) {
        min_index = i;
        for(int j = i + 1; j < n; j++) {
            if(a[min_index] > a[j]) {
                min_index = j;
            }
        }
        if(min_index != i)
        {
            int temp = a[i];
            a[i] = a[min_index];
            a[min_index] = temp;
            count++;
        }
        ccount++;
    }
    printf("Sorted Array: ");
    for(int i = 0; i < n; i++)  {
        printf(" %d", a[i]);
    }
    printf("\n");
    printf("No of swappings %d\n",count);
    printf("No of comparisons %d",ccount);
    return 0;
}
