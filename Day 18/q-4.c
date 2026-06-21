#include <stdio.h>

int main() {
    int arr[100];
    int size, i, j, temp;

    // Get the size of the array from the user
    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);

    // Get the array elements from the user
    printf("Enter %d elements:\n", size);
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Bubble Sort logic for descending order
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            // Change < to > if you want ascending order instead
            if (arr[j] < arr[j + 1]) {
                // Swap the elements
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Print the sorted array
    printf("\nArray sorted in descending order:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
