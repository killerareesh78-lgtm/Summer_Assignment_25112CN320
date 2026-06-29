#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define FILE_NAME "inventory.txt"

// Structure to hold product details
typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
} Item;

// Global array and counter
Item inventory[MAX_ITEMS];
int itemCount = 0;

// Function declarations
void loadInventory();
void saveInventory();
void addItem();
void displayInventory();
void searchItem();
void updateItem();
void deleteItem();

int main() {
    int choice;
    loadInventory(); // Load data from file at startup

    while (1) {
        printf("\n=== INVENTORY MANAGEMENT SYSTEM ===\n");
        printf("1. Add New Item\n");
        printf("2. Display All Items\n");
        printf("3. Search Item by ID\n");
        printf("4. Update Item Quantity/Price\n");
        printf("5. Delete Item\n");
        printf("6. Save and Exit\n");
        printf("Enter your choice (1-6): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
            case 1: addItem(); break;
            case 2: displayInventory(); break;
            case 3: searchItem(); break;
            case 4: updateItem(); break;
            case 5: deleteItem(); break;
            case 6: 
                saveInventory(); 
                printf("Data saved. Exiting program...\n"); 
                exit(0);
            default: printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

// Loads data from a text file into the inventory array
void loadInventory() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        // File doesn't exist yet, which is fine for the first run
        itemCount = 0;
        return;
    }
    
    itemCount = 0;
    while (fscanf(file, "%d,%49[^,],%d,%f\n", 
                  &inventory[itemCount].id, 
                  inventory[itemCount].name, 
                  &inventory[itemCount].quantity, 
                  &inventory[itemCount].price) == 4) {
        itemCount++;
        if (itemCount >= MAX_ITEMS) break;
    }
    fclose(file);
}

// Saves data from the inventory array to a text file
void saveInventory() {
    FILE *file = fopen(FILE_NAME, "w");
    if (file == NULL) {
        printf("Error opening file for writing!\n");
        return;
    }
    for (int i = 0; i < itemCount; i++) {
        fprintf(file, "%d,%s,%d,%.2f\n", 
                inventory[i].id, 
                inventory[i].name, 
                inventory[i].quantity, 
                inventory[i].price);
    }
    fclose(file);
}

// Adds a new product record
void addItem() {
    if (itemCount >= MAX_ITEMS) {
        printf("Inventory is full! Cannot add more items.\n");
        return;
    }

    Item newItem;
    printf("\nEnter Item ID (Integer): ");
    scanf("%d", &newItem.id);

    // Check if ID already exists
    for (int i = 0; i < itemCount; i++) {
        if (inventory[i].id == newItem.id) {
            printf("Error: An item with ID %d already exists.\n", newItem.id);
            return;
        }
    }

    printf("Enter Item Name: ");
    while (getchar() != '\n'); // Clear newline left in buffer
    fgets(newItem.name, sizeof(newItem.name), stdin);
    newItem.name[strcspn(newItem.name, "\n")] = 0; // Remove trailing newline

    printf("Enter Quantity: ");
    scanf("%d", &newItem.quantity);
    printf("Enter Price: ");
    scanf("%f", &newItem.price);

    inventory[itemCount] = newItem;
    itemCount++;
    printf("Item added successfully!\n");
}

// Displays all stored items in a structured list
void displayInventory() {
    if (itemCount == 0) {
        printf("\nNo items available in the inventory.\n");
        return;
    }

    printf("\n-------------------------------------------------------------\n");
    printf("%-10s %-25s %-12s %-10s\n", "Item ID", "Name", "Quantity", "Price");
    printf("-------------------------------------------------------------\n");
    for (int i = 0; i < itemCount; i++) {
        printf("%-10d %-25s %-12d $%-9.2f\n", 
               inventory[i].id, 
               inventory[i].name, 
               inventory[i].quantity, 
               inventory[i].price);
    }
    printf("-------------------------------------------------------------\n");
}

// Locates an item using its ID
void searchItem() {
    int searchId;
    printf("\nEnter Item ID to search: ");
    scanf("%d", &searchId);

    for (int i = 0; i < itemCount; i++) {
        if (inventory[i].id == searchId) {
            printf("\nItem Found:\n");
            printf("ID: %d\nName: %s\nQuantity: %d\nPrice: $%.2f\n", 
                   inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
            return;
        }
    }
    printf("Item with ID %d not found.\n", searchId);
}

// Updates an existing item's quantity or price
void updateItem() {
    int updateId;
    printf("\nEnter Item ID to update: ");
    scanf("%d", &updateId);

    for (int i = 0; i < itemCount; i++) {
        if (inventory[i].id == updateId) {
            printf("Current Details - Name: %s, Qty: %d, Price: $%.2f\n", 
                   inventory[i].name, inventory[i].quantity, inventory[i].price);
            
            printf("Enter New Quantity: ");
            scanf("%d", &inventory[i].quantity);
            printf("Enter New Price: ");
            scanf("%f", &inventory[i].price);
            
            printf("Item updated successfully!\n");
            return;
        }
    }
    printf("Item with ID %d not found.\n", updateId);
}

// Deletes an item and shifts remaining array items left
void deleteItem() {
    int deleteId;
    printf("\nEnter Item ID to delete: ");
    scanf("%d", &deleteId);

    for (int i = 0; i < itemCount; i++) {
        if (inventory[i].id == deleteId) {
            // Shift elements to overwrite the deleted item
            for (int j = i; j < itemCount - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            itemCount--;
            printf("Item deleted successfully!\n");
            return;
        }
    }
    printf("Item with ID %d not found.\n", deleteId);
}

