#include <stdio.h>

int main() {
    int n, i, j;
    
    // Get array size from user
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int arr[n];
    
    // Get array elements
    printf("Enter %d integers: \n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int max_element = arr[0];
    int max_count = 0;
    
    // Find the frequency of each element
    for(i = 0; i < n; i++) {
        int count = 1;
        
        for(j = i + 1; j < n; j++) {
            if(arr[i] == arr[j]) {
                count++;
            }
        }
        
        // Update max_count if current element frequency is higher
        if(count > max_count) {
            max_count = count;
            max_element = arr[i];
        }
    }
    
    // Output the result
    printf("\nThe most frequent element is %d, appearing %d times.\n", max_element, max_count);
    
    return 0;
}
