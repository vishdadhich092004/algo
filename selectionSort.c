#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int a[], int n)
{
    int i, j, min;

    for (i = 0; i <= n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
                min = j;
        }
        swap(&a[min], &a[i]);
    }
}

int main()
{
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
    selectionSort(a, n);
    printf("\nThe sorted array is : \n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}