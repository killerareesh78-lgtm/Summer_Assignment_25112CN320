#include <stdio.h>

#define MAX_SIZE 100 // Maximum capacity of the array

int main() {
    int arr[MAX_SIZE];
    int size, i;
    int even_count = 0;
    int odd_count = 0;

    // Step 1: Get the size of the array from the user
    printf("Enter size of the array: ");
    scanf("%d", &size);

    // Step 2: Input the elements into the array
    printf("Enter %d elements in the array: \n", size);
    for(i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Step 3: Loop through the array to check each element
    for(i = 0; i < size; i++) {
        // If remainder is 0 when divided by 2, it's even
        if(arr[i] % 2 == 0) {
            even_count++;
        } 
        // Otherwise, it's odd
        else {
            odd_count++;
        }
    }

    // Step 4: Display the total counts
    printf("\nTotal even elements: %d\n", even_count);
    printf("Total odd elements: %d\n", odd_count);

    return 0;
}
