#include <stdio.h>
#include <stdlib.h>

int b[50001];

void Merge(int a[], int low, int mid, int high)
{
    int i, j, k;
    i = low;
    j = mid + 1;
    k = low;

    // Merging the two arrays
    while (i <= mid && j <= high)
    {
        if (a[i] <= a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }
    // Copying the rest elements
    while (i <= mid)
        b[k++] = a[i++];
    while (j <= high)
        b[k++] = a[j++];

    for (int l = low; l <= high; l++)
        a[l] = b[l];
}

void MergeSort(int a[], int low, int high)
{
    int mid;
    if (low >= high)
        return;
    mid = (low + high) / 2;
    MergeSort(a, low, mid);
    MergeSort(a, mid + 1, high);
    Merge(a, low, mid, high);
}

int main()
{
    int n;
    int a[50000];
    printf("Enter the size of the array : ");
    scanf("%d", &n);
    printf("The random array created is : \n");
    for (int i = 1; i <= n; i++)
    {
        a[i] = rand() % 100;
        printf("%d ", a[i]);
    
    }
    printf("\n");

    MergeSort(a, 1, n);
    printf("The sorted array is : \n");
    for (int i = 1; i <= n; i++)
        printf("%d ", a[i]);

    return 0;
}
