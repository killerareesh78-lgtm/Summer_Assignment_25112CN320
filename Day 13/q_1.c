#include <stdio.h>

int main() {
    int size, i;

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

    // Display the array elements
    printf("\nThe elements in the array are: ");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
