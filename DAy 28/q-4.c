#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "contacts.dat"

// Structure to hold contact details
typedef struct {
    char name[50];
    char phone[20];
    char email[50];
} Contact;

// Function prototypes
void addContact();
void displayContacts();
void searchContact();
void updateContact();
void deleteContact();
void clearInputBuffer();

int main() {
    int choice;

    while (1) {
        printf("\n=== CONTACT MANAGEMENT SYSTEM ===\n");
        printf("1. Add New Contact\n");
        printf("2. Display All Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Update Contact\n");
        printf("5. Delete Contact\n");
        printf("6. Exit\n");
        printf("Enter your choice (1-6): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            clearInputBuffer();
            continue;
        }
        clearInputBuffer();

        switch (choice) {
            case 1: addContact(); break;
            case 2: displayContacts(); break;
            case 3: searchContact(); break;
            case 4: updateContact(); break;
            case 5: deleteContact(); break;
            case 6: 
                printf("Exiting system. Goodbye!\n");
                exit(0);
            default: 
                printf("Invalid choice. Please select from 1 to 6.\n");
        }
    }
    return 0;
}

// Clears stdin buffer to handle stray characters and newlines safely
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// 1. Function to add a contact to the file
void addContact() {
    FILE *file = fopen(FILE_NAME, "ab"); // Open in append binary mode
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    Contact c;
    printf("Enter Name: ");
    fgets(c.name, sizeof(c.name), stdin);
    c.name[strcspn(c.name, "\n")] = '\0'; // Remove trailing newline

    printf("Enter Phone Number: ");
    fgets(c.phone, sizeof(c.phone), stdin);
    c.phone[strcspn(c.phone, "\n")] = '\0';

    printf("Enter Email: ");
    fgets(c.email, sizeof(c.email), stdin);
    c.email[strcspn(c.email, "\n")] = '\0';

    fwrite(&c, sizeof(Contact), 1, file);
    fclose(file);
    printf("Contact added successfully!\n");
}

// 2. Function to read and display all contacts
void displayContacts() {
    FILE *file = fopen(FILE_NAME, "rb"); // Open in read binary mode
    if (file == NULL) {
        printf("No contacts found. The file may be empty.\n");
        return;
    }

    Contact c;
    printf("\n%-30s %-20s %-30s\n", "Name", "Phone", "Email");
    printf("----------------------------------------------------------------------------\n");

    while (fread(&c, sizeof(Contact), 1, file) == 1) {
        printf("%-30s %-20s %-30s\n", c.name, c.phone, c.email);
    }
    fclose(file);
}

// 3. Function to search for a contact by name
void searchContact() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (file == NULL) {
        printf("No contacts found.\n");
        return;
    }

    char searchName[50];
    printf("Enter the name to search: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0';

    Contact c;
    int found = 0;
    while (fread(&c, sizeof(Contact), 1, file) == 1) {
        // Case-insensitive comparison check can be added if needed via strcasecmp
        if (strcmp(c.name, searchName) == 0) {
            printf("\nContact Found:\n");
            printf("Name:  %s\n", c.name);
            printf("Phone: %s\n", c.phone);
            printf("Email: %s\n", c.email);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Contact not found.\n");
    }
    fclose(file);
}

// 4. Function to update an existing contact's details
void updateContact() {
    FILE *file = fopen(FILE_NAME, "rb+"); // Open for reading and writing
    if (file == NULL) {
        printf("No contacts found.\n");
        return;
    }

    char searchName[50];
    printf("Enter the name of the contact to update: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0';

    Contact c;
    int found = 0;
    while (fread(&c, sizeof(Contact), 1, file) == 1) {
        if (strcmp(c.name, searchName) == 0) {
            printf("Current Details - Phone: %s, Email: %s\n", c.phone, c.email);
            
            printf("Enter New Phone Number: ");
            fgets(c.phone, sizeof(c.phone), stdin);
            c.phone[strcspn(c.phone, "\n")] = '\0';

            printf("Enter New Email: ");
            fgets(c.email, sizeof(c.email), stdin);
            c.email[strcspn(c.email, "\n")] = '\0';

            // Move the file pointer back to override the specific struct record
            fseek(file, -sizeof(Contact), SEEK_CUR);
            fwrite(&c, sizeof(Contact), 1, file);
            
            printf("Contact updated successfully!\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Contact not found.\n");
    }
    fclose(file);
}

// 5. Function to delete a contact by omitting it during a file rewrite
void deleteContact() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (file == NULL) {
        printf("No contacts found.\n");
        return;
    }

    char searchName[50];
    printf("Enter the name of the contact to delete: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0';

    // Create a temporary file to clone records we wish to keep
    FILE *tempFile = fopen("temp.dat", "wb");
    if (tempFile == NULL) {
        printf("System error. Cannot complete deletion.\n");
        fclose(file);
        return;
    }

    Contact c;
    int found = 0;
    while (fread(&c, sizeof(Contact), 1, file) == 1) {
        if (strcmp(c.name, searchName) == 0) {
            found = 1; // Skip writing this entry to delete it
        } else {
            fwrite(&c, sizeof(Contact), 1, tempFile);
        }
    }

    fclose(file);
    fclose(tempFile);

    // Swap original file with the updated temporary file
    if (found) {
        remove(FILE_NAME);
        rename("temp.dat", FILE_NAME);
        printf("Contact deleted successfully!\n");
    } else {
        remove("temp.dat"); // Clean up temporary file
        printf("Contact not found.\n");
    }
}
