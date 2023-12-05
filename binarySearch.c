#include <stdio.h>

// Function to perform binary search
int binarySearch(int arr[], int left, int right, int key)
{
    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key)
        {
            return mid; // Return the index if key is found
        }

        if (arr[mid] < key)
        {
            left = mid + 1; // If key is greater, ignore the left half
        }
        else
        {
            right = mid - 1; // If key is smaller, ignore the right half
        }
    }

    return -1; // Return -1 if key is not found
}

int main()
{
    int size;

    // Get the size of the array from the user
    printf("Enter the size of the sorted array: ");
    scanf("%d", &size);

    int arr[size];

    // Get sorted array elements from the user
    printf("Enter the sorted elements of the array:\n");
    for (int i = 0; i < size; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    int key;

    // Get the key to search from the user
    printf("Enter the element to search: ");
    scanf("%d", &key);

    // Perform binary search
    int index = binarySearch(arr, 0, size - 1, key);

    // Display the result
    if (index != -1)
    {
        printf("Element %d found at index %d.\n", key, index);
    }
    else
    {
        printf("Element %d not found in the array.\n", key);
    }

    return 0;
}
