#include<stdio.h>
#include<stdlib.h>
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quickSort(int a[],int low, int high){
    int i,j,pivot;
    if(high<=low)
    return ;

    pivot = low;
    i = low + 1;
    j = high; 
    while(i<=j)
    {
        while(a[i]<=a[pivot])
        i+=1;
        while(a[j]>a[pivot])
        j-=1;
        if(i<j)
        swap(&a[i],&a[j]);
    }
    swap(&a[pivot],&a[j]);
    quickSort(a, low, j-1);
    quickSort(a, j+1, high);
}

void main(){
    int n, a[1000],k;
    
    printf("Enter the length of the array : ");
    scanf("%d",&n);
    printf("The original array is : \n");
    for(k=1;k<=n;k++)
    {
        a[k]= rand()%50;
        printf("%d ",a[k]);
    }
    quickSort(a,1,n);
    printf("\nThe Sorted array is : \n");
    for(k=1;k<=n;k++)
    printf("%d ",a[k]);
}