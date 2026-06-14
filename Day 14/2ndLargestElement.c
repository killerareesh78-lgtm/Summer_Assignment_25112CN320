#include <stdio.h>
#include <limits.h> // Included for INT_MIN

int main() {
    int size, i;

    printf("Enter the number of elements: ");
    scanf("%d", &size);

    if (size < 2) {
        printf("Array must have at least two elements.\n");
        return 0;
    }

    int arr[size];
    printf("Enter %d elements:\n", size);
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Initialize largest and second_largest to the smallest possible integer value
    int largest = INT_MIN;
    int second_largest = INT_MIN;

    for (i = 0; i < size; i++) {
        // Case 1: Current element is greater than the largest element
        if (arr[i] > largest) {
            second_largest = largest; // Old largest becomes second largest
            largest = arr[i];         // Current element becomes the new largest
        }
        // Case 2: Current element is between largest and second_largest
        else if (arr[i] > second_largest && arr[i] != largest) {
            second_largest = arr[i];  // Update second largest
        }
    }

    // Check if second_largest was actually updated
    if (second_largest == INT_MIN) {
        printf("There is no second largest element (all elements might be equal).\n");
    } else {
        printf("The largest element is: %d\n", largest);
        printf("The second largest element is: %d\n", second_largest);
    }

    return 0;
}