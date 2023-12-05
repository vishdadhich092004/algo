#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void BubbleSort(int a[], int n)
{
    int i, j;

    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
                swap(&a[i], &a[j]);
        }
    }
}

int main()
{
    int n, i;
    printf("Enter the size of the array : ");
    scanf("%d", &n);

    int a[n];
    printf("The random array generated is : \n");
    for (i = 0; i < n; i++)
    {
        a[i] = rand() % 100;
        printf("%d ", a[i]);
    }
    BubbleSort(a, n);
    printf("\nThe sorted array is : \n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
}