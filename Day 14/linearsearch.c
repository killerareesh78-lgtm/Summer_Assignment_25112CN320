#include <stdio.h>

int main() {
    int size, i, key, pos = -1; // Initialize pos to -1 to signify "not found"
    int found = 0;             // A flag to keep track of whether we found the element

    // Ask the user for the size of the array
    printf("Enter the number of elements: ");
    scanf("%d", &size);

    // Declare the array with the user-defined size
    int arr[size];

    // Take array elements as input from the user
    printf("Enter %d elements:\n", size);
    for (i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to be searched: ");
    scanf("%d", &key);

    // Display the array elements and search for the key
    printf("\nThe elements in the array are: ");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
        
        // FIX: Compare key with the array element, not the index 'i'
        if (key == arr[i]) {
            pos = i + 1; // Stores 1-based position (e.g., 1st element, 2nd element)
            found = 1;   // Set flag to true
        }
    }
    printf("\n");

    // Print the result based on whether the element was found
    if (found == 1) {
        printf("The element %d is found at position %d\n", key, pos);
    } else {
        printf("The element %d was not found in the array.\n", key);
    }

    return 0;
}