#include<stdio.h>
#include<conio.h>

void printArray(int arr[], int n) {
    printf("Sorted array\n");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void insertionsort(int arr[],int n)
{
int i, j, temp,scount=0,ccount=0;  
    for (i = 1; i < n; i++) {  
        temp = arr[i];  
        j = i - 1;  
  
        while(j>=0 && temp <= arr[j]) 
        {    
            arr[j+1] = arr[j];     
            j = j-1; 
            scount++;   
        }    
        arr[j+1] = temp;  
        ccount++;
    } 
    printArray(arr, n);
    printf("No of swappings %d\n",scount);
    printf("No of comparisons %d",ccount);
}

int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    for (int i = 0; i < n; i++) 
    {
        scanf("%d",&arr[i]);
    }
    insertionsort(arr,n);

}