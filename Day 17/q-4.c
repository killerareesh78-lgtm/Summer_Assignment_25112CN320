#include <stdio.h>

int main() {
    // Initialize two arrays with some sample values
    int array1[] = {8, 2, 3, 4, 5, 6, 7, 1, 4};
    int array2[] = {4, 5, 7, 11, 6, 1, 4};
    
    // Calculate the size of each array automatically
    int size1 = sizeof(array1) / sizeof(array1[0]);
    int size2 = sizeof(array2) / sizeof(array2[0]);
    
    // Array to store common elements and avoid printing duplicates
    int result[100]; 
    int k = 0; // Counter for unique common elements
    
    printf("Array 1: ");
    for(int i = 0; i < size1; i++) printf("%d ", array1[i]);
    printf("\n");

    printf("Array 2: ");
    for(int i = 0; i < size2; i++) printf("%d ", array2[i]);
    printf("\n\n");

    printf("Common elements are: ");
    
    // Loop through the first array
    for (int i = 0; i < size1; i++) {
        // Loop through the second array
        for (int j = 0; j < size2; j++) {
            // Check if elements match
            if (array1[i] == array2[j]) {
                int alreadyAdded = 0;
                
                // Check if this element was already added to the result array
                for (int x = 0; x < k; x++) {
                    if (result[x] == array1[i]) {
                        alreadyAdded = 1;
                        break;
                    }
                }
                
                // If it is a new common element, store and print it
                if (!alreadyAdded) {
                    result[k] = array1[i];
                    printf("%d ", result[k]);
                    k++;
                }
                // Break inner loop since match for current array1 item is processed
                break; 
            }
        }
    }
    
    if (k == 0) {
        printf("No common elements found.");
    }
    
    printf("\n");
    return 0;
}
