#include <stdio.h>

int main() {
    int size, i, j, count;

    printf("Enter the number of elements: ");
    scanf("%d", &size);

    int arr[size];
    int visited[size]; // Array to track processed elements

    printf("Enter %d elements:\n", size);
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
        visited[i] = 0; // Initialize all elements as not visited (0)
    }

    printf("\nDuplicate elements in the array are:\n");
    int hasDuplicates = 0;

    // Nested loops to find duplicates
    for (i = 0; i < size; i++) {
        // If the element is already processed, skip it
        if (visited[i] == 1) {
            continue;
        }

        count = 1; // Count total occurrences of arr[i]
        for (j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                count++;
                visited[j] = 1; // Mark the duplicate element as visited
            }
        }

        // If count is greater than 1, it's a duplicate
        if (count > 1) {
            printf("Element %d is repeated %d times\n", arr[i], count);
            hasDuplicates = 1;
        }
    }

    if (!hasDuplicates) {
        printf("No duplicate elements found in the array.\n");
    }

    return 0;
}