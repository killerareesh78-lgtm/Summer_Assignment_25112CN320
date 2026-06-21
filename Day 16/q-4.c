#include <stdio.h>

#define MAX_SIZE 100

int main() {
    int arr[MAX_SIZE];
    int size;
    int i, j, k;

    // Input the total number of elements
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Guard against invalid size input
    if (size <= 0 || size > MAX_SIZE) {
        printf("Invalid array size.\n");
        return 1;
    }

    // Input individual elements into the array
    printf("Enter %d elements: ", size);
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Logic to find and delete duplicate elements
    for (i = 0; i < size; i++) {
        for (j = i + 1; j < size; j++) {
            // Check if a duplicate is found
            if (arr[i] == arr[j]) {
                // Shift all subsequent elements one position to the left
                for (k = j; k < size - 1; k++) {
                    arr[k] = arr[k + 1];
                }
                
                // Reduce the logical size of the array
                size--;
                
                // Decrement j so we don't skip checking the newly shifted element
                j--; 
            }
        }
    }

    // Print the unique elements of the array
    printf("\nArray after removing duplicates: ");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
