#include <stdio.h>

// Function to swap the values of two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform selection sort
void selectionSort(int arr[], int n) {
    int i, j, min_idx;

    // Move the boundary of the unsorted subarray one by one
    for (i = 0; i < n - 1; i++) {
        // Assume the current element is the minimum
        min_idx = i;

        // Test the remaining unsorted elements to find the actual minimum
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j; // Update index of the lower element
            }
        }

        // Swap the found minimum element with the first unsorted element
        if (min_idx != i) {
            swap(&arr[i], &arr[min_idx]);
        }
    }
}

// Helper function to print array elements
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Driver code to test the algorithm
int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: \n");
    printArray(arr, n);

    selectionSort(arr, n);

    printf("Sorted array: \n");
    printArray(arr, n);

    return 0;
}
