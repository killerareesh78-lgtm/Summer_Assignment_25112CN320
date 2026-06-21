#include <stdio.h>

// Function to find the missing number
int findMissingNumber(int arr[], int size) {
    // Since one number is missing, total expected elements (N) is size + 1
    int n = size + 1;
    
    // Calculate the expected sum of numbers from 1 to N
    int expectedSum = (n * (n + 1)) / 2;
    
    // Calculate the actual sum of elements present in the array
    int actualSum = 0;
    for (int i = 0; i < size; i++) {
        actualSum += arr[i];
    }
    
    // The difference gives the missing number
    return expectedSum - actualSum;
}

int main() {
    // Example array of size 7 containing distinct numbers from 1 to 8 (6 is missing)
    int arr[] = {1, 2, 4, 6, 3, 7, 8};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    int missingNum = findMissingNumber(arr, size);
    
    printf("The missing number is: %d\n", missingNum);
    
    return 0;
}
