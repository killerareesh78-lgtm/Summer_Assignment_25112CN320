#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100

// Define the book structure to store details
struct Book {
    int id;
    char title[100];
    char author[50];
    int isAvailable; // 1 = Available, 0 = Issued
};

// Global variables
struct Book library[MAX_BOOKS];
int bookCount = 0;

// Function prototypes
void addBook();
void displayBooks();
void searchBook();
void issueBook();
void returnBook();

int main() {
    int choice;

    while (1) {
        printf("\n=================================");
        printf("\n=== MINI LIBRARY SYSTEM MENU ===");
        printf("\n=================================");
        printf("\n1. Add a New Book");
        printf("\n2. Display All Books");
        printf("\n3. Search for a Book by Title");
        printf("\n4. Issue a Book");
        printf("\n5. Return a Book");
        printf("\n6. Exit System");
        printf("\n=================================");
        printf("\nEnter your choice (1-6): ");
        scanf("%d", &choice);
        getchar(); // Clear the newline character left in the buffer

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                searchBook();
                break;
            case 4:
                issueBook();
                break;
            case 5:
                returnBook();
                break;
            case 6:
                printf("\nExiting library system. Goodbye!\n");
                return 0;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
    return 0;
}

// Function to add a book to the library
void addBook() {
    if (bookCount >= MAX_BOOKS) {
        printf("\nLibrary is full! Cannot add more books.\n");
        return;
    }

    struct Book newBook;
    
    printf("\nEnter Book ID (integer): ");
    scanf("%d", &newBook.id);
    getchar(); // Clear buffer

    printf("Enter Book Title: ");
    fgets(newBook.title, sizeof(newBook.title), stdin);
    newBook.title[strcspn(newBook.title, "\n")] = '\0'; // Remove newline character

    printf("Enter Author Name: ");
    fgets(newBook.author, sizeof(newBook.author), stdin);
    newBook.author[strcspn(newBook.author, "\n")] = '\0'; // Remove newline character

    newBook.isAvailable = 1; // Default status is available

    library[bookCount] = newBook;
    bookCount++;

    printf("\nBook added successfully!\n");
}

// Function to display all books
void displayBooks() {
    if (bookCount == 0) {
        printf("\nNo books available in the library yet.\n");
        return;
    }

    printf("\n%-10s %-30s %-25s %-15s", "Book ID", "Title", "Author", "Status");
    printf("\n-----------------------------------------------------------------------------");
    for (int i = 0; i < bookCount; i++) {
        printf("\n%-10d %-30s %-25s %-15s", 
               library[i].id, 
               library[i].title, 
               library[i].author, 
               library[i].isAvailable ? "Available" : "Issued");
    }
    printf("\n");
}

// Function to search for a book by title
void searchBook() {
    if (bookCount == 0) {
        printf("\nNo books in the library to search.\n");
        return;
    }

    char searchTitle[100];
    int found = 0;

    printf("\nEnter the title of the book to search: ");
    fgets(searchTitle, sizeof(searchTitle), stdin);
    searchTitle[strcspn(searchTitle, "\n")] = '\0';

    for (int i = 0; i < bookCount; i++) {
        // Case-sensitive exact or partial match check
        if (strstr(library[i].title, searchTitle) != NULL) {
            if (!found) {
                printf("\nMatch(es) found:\n");
                printf("%-10s %-30s %-25s %-15s", "Book ID", "Title", "Author", "Status");
                printf("\n-----------------------------------------------------------------------------");
            }
            printf("\n%-10d %-30s %-25s %-15s", 
                   library[i].id, 
                   library[i].title, 
                   library[i].author, 
                   library[i].isAvailable ? "Available" : "Issued");
            found = 1;
        }
    }

    if (!found) {
        printf("\nNo book found with the title matching \"%s\".\n", searchTitle);
    } else {
        printf("\n");
    }
}

// Function to issue a book
void issueBook() {
    int searchId, found = 0;

    printf("\nEnter Book ID to issue: ");
    scanf("%d", &searchId);

    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == searchId) {
            found = 1;
            if (library[i].isAvailable == 1) {
                library[i].isAvailable = 0; // Set status to Issued
                printf("\nBook \"%s\" has been issued successfully!\n", library[i].title);
            } else {
                printf("\nSorry, this book is already issued to someone else.\n");
            }
            break;
        }
    }

    if (!found) {
        printf("\nBook ID %d not found in the system.\n", searchId);
    }
}

// Function to return an issued book
void returnBook() {
    int searchId, found = 0;

    printf("\nEnter Book ID to return: ");
    scanf("%d", &searchId);

    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == searchId) {
            found = 1;
            if (library[i].isAvailable == 0) {
                library[i].isAvailable = 1; // Set status back to Available
                printf("\nBook \"%s\" returned successfully!\n", library[i].title);
            } else {
                printf("\nThis book is already marked as available in the library.\n");
            }
            break;
        }
    }

    if (!found) {
        printf("\nBook ID %d not found in the system.\n", searchId);
    }
}
