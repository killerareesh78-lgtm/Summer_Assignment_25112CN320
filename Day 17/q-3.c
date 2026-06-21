#include <stdio.h>

// Function to check if an element is already present in the intersection array
int isDuplicate(int arr[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            return 1; // Found a duplicate
        }
    }
    return 0; // Not a duplicate
}

// Function to find the intersection of two arrays
int findIntersection(int arr1[], int size1, int arr2[], int size2, int result[]) {
    int k = 0; // Index tracker for the result array

    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            // If elements match, verify it's not a duplicate in our final list
            if (arr1[i] == arr2[j]) {
                if (!isDuplicate(result, k, arr1[i])) {
                    result[k] = arr1[i];
                    k++;
                }
                break; // Break the inner loop to save execution time
            }
        }
    }
    return k; // Return total number of items in intersection
}

int main() {
    int arr1[] = {4, 9, 5, 4, 1};
    int arr2[] = {9, 4, 9, 8, 4, 2};
    
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    
    // The maximum possible size of intersection is the size of the smaller array
    int maxIntersectionSize = (size1 < size2) ? size1 : size2;
    int result[maxIntersectionSize];
    
    // Find intersection elements
    int intersectionSize = findIntersection(arr1, size1, arr2, size2, result);
    
    // Display results
    printf("Array 1: ");
    for (int i = 0; i < size1; i++) printf("%d ", arr1[i]);
    
    printf("\nArray 2: ");
    for (int i = 0; i < size2; i++) printf("%d ", arr2[i]);
    
    printf("\nIntersection: ");
    if (intersectionSize == 0) {
        printf("No common elements found.");
    } else {
        for (int i = 0; i < intersectionSize; i++) {
            printf("%d ", result[i]);
        }
    }
    printf("\n");

    return 0;
}
