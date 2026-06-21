#include <stdio.h>

// Function to check if an element is already in the result array
int isDuplicate(int arr[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            return 1; // Element found, it's a duplicate
        }
    }
    return 0; // Element not found
}

// Function to find the union of two arrays
int findUnion(int arr1[], int size1, int arr2[], int size2, int unionResult[]) {
    int k = 0; // Index tracker for unionResult

    // 1. Copy unique elements from the first array
    for (int i = 0; i < size1; i++) {
        if (!isDuplicate(unionResult, k, arr1[i])) {
            unionResult[k++] = arr1[i];
        }
    }

    // 2. Copy unique elements from the second array
    for (int i = 0; i < size2; i++) {
        if (!isDuplicate(unionResult, k, arr2[i])) {
            unionResult[k++] = arr2[i];
        }
    }

    return k; // Return total number of elements in union
}

int main() {
    int arr1[] = {1, 3, 2, 3, 4};
    int arr2[] = {2, 4, 5, 6, 2};

    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    // Maximum possible size of union is the sum of sizes of both arrays
    int unionResult[size1 + size2]; 

    int unionSize = findUnion(arr1, size1, arr2, size2, unionResult);

    // Print the result
    printf("Union of the two arrays is: ");
    for (int i = 0; i < unionSize; i++) {
        printf("%d ", unionResult[i]);
    }
    printf("\n");

    return 0;
}
