#include <stdio.h>

#define MAX_SIZE 100 // Maximum capacity of the array

int main() {
    int arr[MAX_SIZE];
    int size, i;
    int smallest, largest;

    // Ask user for the size of the array
    printf("Enter the size of the array (up to %d): ", MAX_SIZE);
    if (scanf("%d", &size) != 1 || size <= 0 || size > MAX_SIZE) {
        printf("Invalid array size.\n");
        return 1;
    }

    // Input array elements from the user
    printf("Enter %d elements:\n", size);
    for (i = 0; i < size; i++) {
        printf("Element [%d]: ", i);
        scanf("%d", &arr[i]);
    }

    // Initialize smallest and largest with the first element
    smallest = arr[0];
    largest = arr[0];

    // Traverse the array to update smallest and largest values
    for (i = 1; i < size; i++) {
        if (arr[i] < smallest) {
            smallest = arr[i]; // New smallest value found
        }
        if (arr[i] > largest) {
            largest = arr[i];  // New largest value found
        }
    }

    // Output the final results
    printf("\nResults:\n");
    printf("Smallest element: %d\n", smallest);
    printf("Largest element: %d\n", largest);

    return 0;
}
