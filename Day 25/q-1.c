#include <stdio.h>

// Function to merge two sorted arrays
void mergeSortedArrays(int arr1[], int n1, int arr2[], int n2, int merged[]) {
    int i = 0; // Pointer for arr1
    int j = 0; // Pointer for arr2
    int k = 0; // Pointer for merged array

    // Traverse both arrays and copy the smaller element
    while (i < n1 && j < n2) {
        if (arr1[i] <= arr2[j]) {
            merged[k++] = arr1[i++];
        } else {
            merged[k++] = arr2[j++];
        }
    }

    // Copy remaining elements of arr1, if any
    while (i < n1) {
        merged[k++] = arr1[i++];
    }

    // Copy remaining elements of arr2, if any
    while (j < n2) {
        merged[k++] = arr2[j++];
    }
}

int main() {
    int n1, n2;

    // Input size and elements of the first sorted array
    printf("Enter number of elements in the first array: ");
    scanf("%d", &n1);
    int arr1[n1];
    printf("Enter %d sorted elements: ", n1);
    for (int i = 0; i < n1; i++) {
        scanf("%d", &arr1[i]);
    }

    // Input size and elements of the second sorted array
    printf("Enter number of elements in the second array: ");
    scanf("%d", &n2);
    int arr2[n2];
    printf("Enter %d sorted elements: ", n2);
    for (int i = 0; i < n2; i++) {
        scanf("%d", &arr2[i]);
    }

    // Create the destination array to hold merged elements
    int merged[n1 + n2];

    // Call the merge function
    mergeSortedArrays(arr1, n1, arr2, n2, merged);

    // Display the final merged array
    printf("\nMerged sorted array:\n");
    for (int i = 0; i < n1 + n2; i++) {
        printf("%d ", merged[i]);
    }
    printf("\n");

    return 0;
}
