#include <stdio.h>

int main() {
    int size, i, j, count;

    // 1. Get the size of the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);

    int arr[size];
    int freq[size]; // Array to store frequency of elements

    // 2. Input array elements
    printf("Enter %d elements:\n", size);
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
        freq[i] = -1; // Initialize frequency array with -1
    }

    // 3. Count the frequency of each element
    for (i = 0; i < size; i++) {
        count = 1; // Every element exists at least once
        
        // Check the rest of the array for duplicates
        for (j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                count++;
                freq[j] = 0; // Mark this element as visited so we don't count it again
            }
        }

        // If the element was not visited before, store its count
        if (freq[i] != 0) {
            freq[i] = count;
        }
    }

    // 4. Print the frequencies
    printf("\nFrequency of all elements in the array:\n");
    printf("Element | Frequency\n");
    printf("-------------------\n");
    for (i = 0; i < size; i++) {
        if (freq[i] != 0) { // Only print elements that haven't been skipped
            printf("   %d    |    %d\n", arr[i], freq[i]);
        }
    }

    return 0;
}