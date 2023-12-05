#include <stdio.h>

// Function to perform linear search
int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i; // Return the index if key is found
        }
    }
    return -1; // Return -1 if key is not found
}

int main() {
    int size;

    // Get the size of the array from the user
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];

    // Get array elements from the user
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    int key;

    // Get the key to search from the user
    printf("Enter the element to search: ");
    scanf("%d", &key);

    // Perform linear search
    int index = linearSearch(arr, size, key);

    // Display the result
    if (index != -1) {
        printf("Element %d found at index %d.\n", key, index);
    } else {
        printf("Element %d not found in the array.\n", key);
    }

    return 0;
}
