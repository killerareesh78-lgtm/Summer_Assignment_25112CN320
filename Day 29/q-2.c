#include <stdio.h>
#include <stdlib.h>

#define MAX_CAPACITY 100

// Function prototypes
void createArray(int arr[], int *size);
void displayArray(const int arr[], int size);
void insertElement(int arr[], int *size);
void deleteElement(int arr[], int *size);
void searchElement(const int arr[], int size);

int main() {
    int arr[MAX_CAPACITY];
    int size = 0; // Tracks the current number of elements in the array
    int choice;

    do {
        // Displaying the menu options
        printf("\n====================================");
        printf("\n      ARRAY OPERATIONS SYSTEM       ");
        printf("\n====================================");
        printf("\n1. Create / Reset Array");
        printf("\n2. Display Array");
        printf("\n3. Insert Element at Position");
        printf("\n4. Delete Element from Position");
        printf("\n5. Search Element (Linear Search)");
        printf("\n6. Exit");
        printf("\n====================================");
        printf("\nEnter your choice (1-6): ");
        
        // Input validation for menu choice
        if (scanf("%d", &choice) != 1) {
            printf("\n[Error] Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                createArray(arr, &size);
                break;
            case 2:
                displayArray(arr, size);
                break;
            case 3:
                insertElement(arr, &size);
                break;
            case 4:
                deleteElement(arr, &size);
                break;
            case 5:
                searchElement(arr, size);
                break;
            case 6:
                printf("\nExiting program. Goodbye!\n");
                break;
            default:
                printf("\n[Error] Invalid choice! Please select between 1 and 6.\n");
        }
    } while (choice != 6);

    return 0;
}

// 1. Create or fully populate the array
void createArray(int arr[], int *size) {
    int n;
    printf("\nEnter the number of elements to initialize (Max %d): ", MAX_CAPACITY);
    scanf("%d", &n);

    if (n < 0 || n > MAX_CAPACITY) {
        printf("[Error] Invalid size! Must be between 0 and %d.\n", MAX_CAPACITY);
        return;
    }

    *size = n;
    if (n > 0) {
        printf("Enter %d elements:\n", n);
        for (int i = 0; i < *size; i++) {
            printf("Element [%d]: ", i);
            scanf("%d", &arr[i]);
        }
        printf("\nArray created successfully!\n");
    } else {
        printf("\nArray cleared/Initialized to empty status.\n");
    }
}

// 2. Traversal and display operation
void displayArray(const int arr[], int size) {
    if (size == 0) {
        printf("\n[Notice] Array is empty. Nothing to display.\n");
        return;
    }

    printf("\nCurrent Array Elements:\n");
    printf("[ ");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf(" ]\n");
    printf("Total items: %d\n", size);
}

// 3. Insertion operation
void insertElement(int arr[], int *size) {
    if (*size >= MAX_CAPACITY) {
        printf("\n[Error] Array Overflow! Cannot insert more elements.\n");
        return;
    }

    int element, pos;
    printf("\nEnter the element to insert: ");
    scanf("%d", &element);
    
    // User sees positions as 1 to size+1
    printf("Enter position (1 to %d): ", *size + 1);
    scanf("%d", &pos);

    // Validate if the user-specified index falls into bound
    if (pos < 1 || pos > *size + 1) {
        printf("[Error] Invalid position bounds!\n");
        return;
    }

    // Convert user choice 1-based index to 0-based computer index
    int index = pos - 1;

    // Shift existing elements to the right side
    for (int i = *size; i > index; i--) {
        arr[i] = arr[i - 1];
    }

    // Insert element & adjust size variable
    arr[index] = element;
    (*size)++;
    printf("\nElement %d successfully inserted at position %d.\n", element, pos);
}

// 4. Deletion operation
void deleteElement(int arr[], int *size) {
    if (*size == 0) {
        printf("\n[Error] Array Underflow! No items available to delete.\n");
        return;
    }

    int pos;
    printf("\nEnter position to delete (1 to %d): ", *size);
    scanf("%d", &pos);

    if (pos < 1 || pos > *size) {
        printf("[Error] Invalid position bounds!\n");
        return;
    }

    int index = pos - 1;
    int deletedValue = arr[index];

    // Shift elements left to overwrite the index
    for (int i = index; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    (*size)--;
    printf("\nElement %d deleted from position %d.\n", deletedValue, pos);
}

// 5. Linear search operation
void searchElement(const int arr[], int size) {
    if (size == 0) {
        printf("\n[Notice] Array is empty. Cannot perform search.\n");
        return;
    }

    int target, foundIndex = -1;
    printf("\nEnter the element to search for: ");
    scanf("%d", &target);

    // Linear scanning logic
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            foundIndex = i;
            break; // Stop at first occurrence
        }
    }

    if (foundIndex != -1) {
        printf("\n[Success] Element %d found at index %d (Position %d).\n", target, foundIndex, foundIndex + 1);
    } else {
        printf("\n[Result] Element %d does not exist in the array.\n", target);
    }
}
