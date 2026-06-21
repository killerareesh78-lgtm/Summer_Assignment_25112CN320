#include <stdio.h>

// Function to shift all zeros to the end
void moveZeroesToEnd(int arr[], int size) {
    int count = 0; // Tracks the position for the next non-zero element

    // Step 1: Travel through the array. If an element is non-zero,
    // move it to the 'count' index and advance 'count'.
    for (int i = 0; i < size; i++) {
        if (arr[i] != 0) {
            arr[count] = arr[i];
            count++;
        }
    }

    // Step 2: Fill the remaining positions of the array with zeroes.
    while (count < size) {
        arr[count] = 0;
        count++;
    }
}

// Function to print the array elements
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {1, 2, 0, 4, 3, 0, 5, 0};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, size);

    // Call the function to reorder elements
    moveZeroesToEnd(arr, size);

    printf("Modified array: ");
    printArray(arr, size);

    return 0;
}
