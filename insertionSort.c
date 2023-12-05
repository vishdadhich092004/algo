#include<stdio.h>
#include<stdlib.h>

void insertionSort(int a[],int n)
{
    int i,j,key;

    for (i = 1; i < n; i++) {  
        key = a[i];  
        j = i - 1;  
  
        while(j>=0 && key <= a[j]){
            a[j+1] = a[j];     
            j = j-1;    
        }    
        a[j+1] = key;    
    }  
}

int main(){
    int n, i;
    printf("Enter the size of the array : ");
    scanf("%d", &n);
    printf("The random array is : \n");
    int a[n];
    for (i = 0; i < n; i++)
    {
        a[i] = rand() % 100;
        printf("%d ", a[i]);
    }
    insertionSort(a, n);
    printf("\nThe sorted array is : \n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}