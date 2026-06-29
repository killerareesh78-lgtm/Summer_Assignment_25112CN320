#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold book details
struct Book {
    int id;
    char title[100];
    char author[50];
    int isAvailable; // 1 = Yes, 0 = Issued
};

// Function declarations
void addBook();
void displayBooks();
void searchBook();
void issueBook();
void returnBook();
void clearInputBuffer();

const char* FILE_NAME = "library_books.dat";

int main() {
    int choice;

    while (1) {
        printf("\n=================================");
        printf("\n    LIBRARY MANAGEMENT SYSTEM    ");
        printf("\n=================================");
        printf("\n1. Add a New Book");
        printf("\n2. Display All Books");
        printf("\n3. Search for a Book");
        printf("\n4. Issue a Book");
        printf("\n5. Return a Book");
        printf("\n6. Exit the Application");
        printf("\n=================================");
        printf("\nEnter your choice (1-6): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid input. Please enter a number.\n");
            clearInputBuffer();
            continue;
        }

        switch (choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: searchBook(); break;
            case 4: issueBook(); break;
            case 5: returnBook(); break;
            case 6: 
                printf("\nExiting the system. Goodbye!\n");
                exit(0);
            default: 
                printf("\nInvalid choice! Choose between 1 and 6.\n");
        }
    }
    return 0;
}

// Function to safely clear standard input buffer
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// 1. Add a new book to the binary file
void addBook() {
    FILE *fp = fopen(FILE_NAME, "ab");
    if (fp == NULL) {
        printf("\nError opening file for writing!\n");
        return;
    }

    struct Book b;
    b.isAvailable = 1; // New books are available by default

    printf("\nEnter Book ID (Integer): ");
    scanf("%d", &b.id);
    clearInputBuffer();

    printf("Enter Book Title: ");
    fgets(b.title, sizeof(b.title), stdin);
    b.title[strcspn(b.title, "\n")] = '\0'; // Remove trailing newline

    printf("Enter Author Name: ");
    fgets(b.author, sizeof(b.author), stdin);
    b.author[strcspn(b.author, "\n")] = '\0';

    fwrite(&b, sizeof(struct Book), 1, fp);
    fclose(fp);

    printf("\nSuccess: Book successfully added to the library!\n");
}

// 2. Read and display all stored books
void displayBooks() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) {
        printf("\nNo records found. The library database is empty.\n");
        return;
    }

    struct Book b;
    printf("\n%-10s %-30s %-25s %-15s", "Book ID", "Title", "Author", "Status");
    printf("\n--------------------------------------------------------------------------------");
    
    while (fread(&b, sizeof(struct Book), 1, fp) == 1) {
        printf("\n%-10d %-30s %-25s %-15s", 
               b.id, b.title, b.author, 
               b.isAvailable ? "Available" : "Issued");
    }
    printf("\n--------------------------------------------------------------------------------\n");
    fclose(fp);
}

// 3. Search for a specific book using its Unique ID
void searchBook() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) {
        printf("\nNo library records available to search.\n");
        return;
    }

    int searchId, found = 0;
    struct Book b;

    printf("\nEnter the Book ID to search: ");
    scanf("%d", &searchId);

    while (fread(&b, sizeof(struct Book), 1, fp) == 1) {
        if (b.id == searchId) {
            found = 1;
            printf("\n--- Book Found ---");
            printf("\nID: %d", b.id);
            printf("\nTitle: %s", b.title);
            printf("\nAuthor: %s", b.author);
            printf("\nStatus: %s\n", b.isAvailable ? "Available" : "Issued");
            break;
        }
    }

    if (!found) {
        printf("\nError: Book with ID %d does not exist.\n", searchId);
    }
    fclose(fp);
}

// 4. Update status to "Issued" (0)
void issueBook() {
    FILE *fp = fopen(FILE_NAME, "rb+");
    if (fp == NULL) {
        printf("\nNo records found. Cannot issue books.\n");
        return;
    }

    int issueId, found = 0;
    struct Book b;

    printf("\nEnter Book ID to issue: ");
    scanf("%d", &issueId);

    while (fread(&b, sizeof(struct Book), 1, fp) == 1) {
        if (b.id == issueId) {
            found = 1;
            if (b.isAvailable == 1) {
                b.isAvailable = 0; // Update to issued
                // Move file pointer back to overwrite this specific record
                fseek(fp, -sizeof(struct Book), SEEK_CUR);
                fwrite(&b, sizeof(struct Book), 1, fp);
                printf("\nSuccess: Book issued successfully!\n");
            } else {
                printf("\nNotice: This book is already issued out to someone else.\n");
            }
            break;
        }
    }

    if (!found) {
        printf("\nError: Book ID %d not found.\n", issueId);
    }
    fclose(fp);
}

// 5. Update status back to "Available" (1)
void returnBook() {
    FILE *fp = fopen(FILE_NAME, "rb+");
    if (fp == NULL) {
        printf("\nNo records found. Cannot return books.\n");
        return;
    }

    int returnId, found = 0;
    struct Book b;

    printf("\nEnter Book ID to return: ");
    scanf("%d", &returnId);

    while (fread(&b, sizeof(struct Book), 1, fp) == 1) {
        if (b.id == returnId) {
            found = 1;
            if (b.isAvailable == 0) {
                b.isAvailable = 1; // Update to available
                fseek(fp, -sizeof(struct Book), SEEK_CUR);
                fwrite(&b, sizeof(struct Book), 1, fp);
                printf("\nSuccess: Book returned successfully!\n");
            } else {
                printf("\nNotice: This book is already marked as available in the library.\n");
            }
            break;
        }
    }

    if (!found) {
        printf("\nError: Book ID %d not found.\n", returnId);
    }
    fclose(fp);
}
