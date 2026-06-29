#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TOTAL_SEATS 20
#define TICKET_PRICE 500

// Structure to hold individual booking details
typedef struct {
    int seatNumber;
    char passengerName[50];
} Booking;

// Global array to manage seats (0 = Available, 1 = Booked)
int seats[TOTAL_SEATS] = {0};
Booking bookings[TOTAL_SEATS];

// Function Prototypes
void displayMenu();
void viewSeats();
void bookTicket();
void cancelTicket();
void viewBookings();

int main() {
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("\n[!] Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                viewSeats();
                break;
            case 2:
                bookTicket();
                break;
            case 3:
                cancelTicket();
                break;
            case 4:
                viewBookings();
                break;
            case 5:
                printf("\nThank you for using the Ticket Booking System. Goodbye!\n");
                exit(0);
            default:
                printf("\n[!] Invalid choice. Please select between 1 and 5.\n");
        }
    }
    return 0;
}

// Displays the main terminal interface dashboard
void displayMenu() {
    printf("\n=========================================");
    printf("\n      TICKET BOOKING SYSTEM (C)          ");
    printf("\n=========================================");
    printf("\n 1. View Seating Layout");
    printf("\n 2. Book a Ticket");
    printf("\n 3. Cancel a Ticket");
    printf("\n 4. View All Passenger Bookings");
    printf("\n 5. Exit");
    printf("\n=========================================\n");
}

// Prints the 2D visual grid layout of the seats
void viewSeats() {
    printf("\n--- SEATING LAYOUT ---\n");
    printf("[X] = Booked   [ ] = Available\n\n");

    for (int i = 0; i < TOTAL_SEATS; i++) {
        if (seats[i] == 0) {
            printf("Seat %02d: [ ]\t", i + 1);
        } else {
            printf("Seat %02d: [X]\t", i + 1);
        }
        
        // Print 4 seats per row for easy structural layout readability
        if ((i + 1) % 4 == 0) {
            printf("\n");
        }
    }
    printf("\n----------------------\n");
}

// Processes a new ticket reservation
void bookTicket() {
    int seatNum;

    printf("\nEnter seat number to book (1-%d): ", TOTAL_SEATS);
    if (scanf("%d", &seatNum) != 1) {
        printf("\n[!] Error: Invalid numeric value.\n");
        while (getchar() != '\n');
        return;
    }

    // Input bounds validation
    if (seatNum < 1 || seatNum > TOTAL_SEATS) {
        printf("\n[!] Error: Seat number %d does not exist.\n", seatNum);
        return;
    }

    int index = seatNum - 1;

    // Check if seat is already occupied
    if (seats[index] == 1) {
        printf("\n[!] Sorry, Seat %d is already booked.\n", seatNum);
        return;
    }

    // Save passenger registration details
    printf("Enter passenger name: ");
    while (getchar() != '\n'); // Clear trailing newline from buffer
    fgets(bookings[index].passengerName, sizeof(bookings[index].passengerName), stdin);
    
    // Remove the newline character added by fgets
    bookings[index].passengerName[strcspn(bookings[index].passengerName, "\n")] = 0;
    
    bookings[index].seatNumber = seatNum;
    seats[index] = 1; // Mark seat as booked

    printf("\n====== BOOKING CONFIRMED ======");
    printf("\n Passenger: %s", bookings[index].passengerName);
    printf("\n Seat Allocated: %d", seatNum);
    printf("\n Total Fare Paid: %d INR", TICKET_PRICE);
    printf("\n===============================\n");
}

// Cancels a pre-existing ticket modification
void cancelTicket() {
    int seatNum;

    printf("\nEnter your seat number to cancel booking: ");
    if (scanf("%d", &seatNum) != 1) {
        printf("\n[!] Error: Invalid input format.\n");
        while (getchar() != '\n');
        return;
    }

    if (seatNum < 1 || seatNum > TOTAL_SEATS) {
        printf("\n[!] Error: Seat number out of range.\n");
        return;
    }

    int index = seatNum - 1;

    // Validate if reservation exists
    if (seats[index] == 0) {
        printf("\n[!] Notice: Seat %d is already vacant. No active reservation found.\n", seatNum);
        return;
    }

    printf("\n[✔] Reservation for %s (Seat %d) successfully canceled.\n", bookings[index].passengerName, seatNum);
    
    // Clear structural array data properties
    seats[index] = 0;
    strcpy(bookings[index].passengerName, "");
    bookings[index].seatNumber = 0;
}

// Traverses structural elements to display current bookings
void viewBookings() {
    int found = 0;
    printf("\n--- CURRENT PASSENGER RECORDS ---\n");
    printf("%-10s %-30s\n", "Seat No.", "Passenger Name");
    printf("----------------------------------------\n");

    for (int i = 0; i < TOTAL_SEATS; i++) {
        if (seats[i] == 1) {
            printf("%-10d %-30s\n", bookings[i].seatNumber, bookings[i].passengerName);
            found = 1;
        }
    }

    if (!found) {
        printf("No active reservations recorded in the system.\n");
    }
    printf("----------------------------------------\n");
}
