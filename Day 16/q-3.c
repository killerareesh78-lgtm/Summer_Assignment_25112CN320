#include <stdio.h>

// Function to find and print all pairs with the given sum
void findPairsWithSum(int arr[], int size, int targetSum) {
    int found = 0;

    printf("Pairs with sum %d are:\n", targetSum);

    // Outer loop picks the first element of the pair
    for (int i = 0; i < size - 1; i++) {
        // Inner loop checks the remaining elements for the complement
        for (int j = i + 1; j < size; j++) {
            if (arr[i] + arr[j] == targetSum) {
                printf("(%d, %d)\n", arr[i], arr[j]);
                found = 1;
            }
        }
    }

    if (!found) {
        printf("No pairs found with the given sum.\n");
    }
}

int main() {
    // Example array and target sum
    int arr[] = {1, 5, 7, -1, 5, 2, 4};
    int targetSum = 6;
    
    // Calculate the total number of elements in the array
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Given Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    // Call the function to find the pairs
    findPairsWithSum(arr, size, targetSum);

    return 0;
}
