#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PATIENTS 100
#define MAX_DOCTORS 20
#define MAX_NAME_LENGTH 50
#define MAX_DIAGNOSIS_LENGTH 200
#define MAX_MEDICINE_LENGTH 100

// Structure for Doctor
struct Doctor {
    int doctorId;
    char name[MAX_NAME_LENGTH];
    char specialization[MAX_NAME_LENGTH];
    int available; // 1 = available, 0 = busy
};

// Structure for Patient
struct Patient {
    int patientId;
    char name[MAX_NAME_LENGTH];
    int age;
    char gender[10];
    char contact[MAX_NAME_LENGTH];
    char admissionDate[20];
    char diagnosis[MAX_DIAGNOSIS_LENGTH];
    char medicines[MAX_MEDICINE_LENGTH];
    int doctorId; // Assigned doctor ID
    int roomNumber;
    int bedNumber;
    char bloodGroup[5];
    float billAmount;
    int isDischarged; // 0 = admitted, 1 = discharged
};

// Global variables
struct Patient patients[MAX_PATIENTS];
struct Doctor doctors[MAX_DOCTORS];
int patientCount = 0;
int doctorCount = 0;
int nextPatientId = 1001;
int nextDoctorId = 2001;

// Function prototypes
void initializeDoctors();
void displayMainMenu();
void admitPatient();
void dischargePatient();
void viewAllPatients();
void viewPatientDetails(int patientId);
void searchPatient();
void assignDoctor();
void viewDoctors();
void viewAvailableBeds();
void generateBill();
void viewDepartmentStats();
void saveDataToFile();
void loadDataFromFile();
void displayDoctorDetails(int doctorId);
void clearInputBuffer();
int findPatientById(int patientId);
int findDoctorById(int doctorId);
void generateAdmissionDate(char *date);
int getCurrentBedCount();

// Main function
int main() {
    initializeDoctors();
    loadDataFromFile();
    
    int choice;
    do {
        displayMainMenu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        clearInputBuffer();
        
        switch(choice) {
            case 1:
                admitPatient();
                break;
            case 2:
                dischargePatient();
                break;
            case 3:
                viewAllPatients();
                break;
            case 4:
                searchPatient();
                break;
            case 5:
                viewDoctors();
                break;
            case 6:
                viewAvailableBeds();
                break;
            case 7:
                generateBill();
                break;
            case 8:
                viewDepartmentStats();
                break;
            case 9:
                saveDataToFile();
                printf("Data saved successfully!\n");
                break;
            case 10:
                printf("\nThank you for using Hospital Management System!\n");
                saveDataToFile();
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while(choice != 10);
    
    return 0;
}

// Initialize default doctors
void initializeDoctors() {
    strcpy(doctors[0].name, "Dr. Rajesh Kumar");
    strcpy(doctors[0].specialization, "Cardiology");
    doctors[0].doctorId = nextDoctorId++;
    doctors[0].available = 1;
    
    strcpy(doctors[1].name, "Dr. Priya Sharma");
    strcpy(doctors[1].specialization, "Neurology");
    doctors[1].doctorId = nextDoctorId++;
    doctors[1].available = 1;
    
    strcpy(doctors[2].name, "Dr. Amit Patel");
    strcpy(doctors[2].specialization, "Orthopedics");
    doctors[2].doctorId = nextDoctorId++;
    doctors[2].available = 1;
    
    strcpy(doctors[3].name, "Dr. Sunita Reddy");
    strcpy(doctors[3].specialization, "Pediatrics");
    doctors[3].doctorId = nextDoctorId++;
    doctors[3].available = 1;
    
    strcpy(doctors[4].name, "Dr. Vikram Singh");
    strcpy(doctors[4].specialization, "Gynecology");
    doctors[4].doctorId = nextDoctorId++;
    doctors[4].available = 1;
    
    doctorCount = 5;
}

// Display main menu
void displayMainMenu() {
    printf("\n╔══════════════════════════════════════════════════════╗\n");
    printf("║        HOSPITAL PATIENT MANAGEMENT SYSTEM            ║\n");
    printf("╠══════════════════════════════════════════════════════╣\n");
    printf("║  1. Admit New Patient                                ║\n");
    printf("║  2. Discharge Patient                               ║\n");
    printf("║  3. View All Patients                               ║\n");
    printf("║  4. Search Patient                                  ║\n");
    printf("║  5. View Doctors List                               ║\n");
    printf("║  6. View Available Beds                             ║\n");
    printf("║  7. Generate Patient Bill                           ║\n");
    printf("║  8. View Department Statistics                      ║\n");
    printf("║  9. Save Data                                       ║\n");
    printf("║  10. Exit                                           ║\n");
    printf("╚══════════════════════════════════════════════════════╝\n");
}

// Admit a new patient
void admitPatient() {
    if (patientCount >= MAX_PATIENTS) {
        printf("Hospital is full! Cannot admit more patients.\n");
        return;
    }
    
    struct Patient newPatient;
    newPatient.patientId = nextPatientId++;
    newPatient.isDischarged = 0;
    
    printf("\n--- Patient Admission Form ---\n");
    printf("Patient ID: %d\n", newPatient.patientId);
    
    printf("Enter Patient Name: ");
    fgets(newPatient.name, MAX_NAME_LENGTH, stdin);
    newPatient.name[strcspn(newPatient.name, "\n")] = '\0';
    
    printf("Enter Age: ");
    scanf("%d", &newPatient.age);
    clearInputBuffer();
    
    printf("Enter Gender (Male/Female/Other): ");
    fgets(newPatient.gender, 10, stdin);
    newPatient.gender[strcspn(newPatient.gender, "\n")] = '\0';
    
    printf("Enter Contact Number: ");
    fgets(newPatient.contact, MAX_NAME_LENGTH, stdin);
    newPatient.contact[strcspn(newPatient.contact, "\n")] = '\0';
    
    printf("Enter Blood Group (A+/A-/B+/B-/AB+/AB-/O+/O-): ");
    fgets(newPatient.bloodGroup, 5, stdin);
    newPatient.bloodGroup[strcspn(newPatient.bloodGroup, "\n")] = '\0';
    
    printf("Enter Diagnosis: ");
    fgets(newPatient.diagnosis, MAX_DIAGNOSIS_LENGTH, stdin);
    newPatient.diagnosis[strcspn(newPatient.diagnosis, "\n")] = '\0';
    
    printf("Enter Medicines Prescribed: ");
    fgets(newPatient.medicines, MAX_MEDICINE_LENGTH, stdin);
    newPatient.medicines[strcspn(newPatient.medicines, "\n")] = '\0';
    
    // Assign bed and room
    newPatient.roomNumber = (patientCount / 4) + 101;
    newPatient.bedNumber = (patientCount % 4) + 1;
    
    // Generate admission date
    generateAdmissionDate(newPatient.admissionDate);
    
    // Assign doctor based on diagnosis specialty
    assignDoctor(&newPatient);
    
    // Set initial bill amount
    newPatient.billAmount = 0.0;
    
    patients[patientCount] = newPatient;
    patientCount++;
    
    printf("\n✓ Patient admitted successfully!\n");
    printf("Room Number: %d, Bed Number: %d\n", newPatient.roomNumber, newPatient.bedNumber);
    printf("Assigned Doctor: %s\n", doctors[findDoctorById(newPatient.doctorId)].name);
}

// Assign doctor based on diagnosis keywords
void assignDoctor(struct Patient *patient) {
    char diagnosisLower[MAX_DIAGNOSIS_LENGTH];
    strcpy(diagnosisLower, patient->diagnosis);
    
    // Convert to lowercase for case-insensitive matching
    for(int i = 0; diagnosisLower[i]; i++) {
        diagnosisLower[i] = tolower(diagnosisLower[i]);
    }
    
    int assigned = 0;
    for(int i = 0; i < doctorCount; i++) {
        if(doctors[i].available == 1) {
            // Check specialization keywords
            if(strstr(diagnosisLower, "heart") && strstr(doctors[i].specialization, "Cardiology")) {
                patient->doctorId = doctors[i].doctorId;
                doctors[i].available = 0;
                assigned = 1;
                break;
            } else if((strstr(diagnosisLower, "brain") || strstr(diagnosisLower, "nerve")) && 
                      strstr(doctors[i].specialization, "Neurology")) {
                patient->doctorId = doctors[i].doctorId;
                doctors[i].available = 0;
                assigned = 1;
                break;
            } else if((strstr(diagnosisLower, "bone") || strstr(diagnosisLower, "fracture")) && 
                      strstr(doctors[i].specialization, "Orthopedics")) {
                patient->doctorId = doctors[i].doctorId;
                doctors[i].available = 0;
                assigned = 1;
                break;
            } else if((strstr(diagnosisLower, "child") || strstr(diagnosisLower, "infant")) && 
                      strstr(doctors[i].specialization, "Pediatrics")) {
                patient->doctorId = doctors[i].doctorId;
                doctors[i].available = 0;
                assigned = 1;
                break;
            } else if((strstr(diagnosisLower, "pregnan") || strstr(diagnosisLower, "gynae")) && 
                      strstr(doctors[i].specialization, "Gynecology")) {
                patient->doctorId = doctors[i].doctorId;
                doctors[i].available = 0;
                assigned = 1;
                break;
            }
        }
    }
    
    // If no specific doctor found, assign to first available
    if(!assigned) {
        for(int i = 0; i < doctorCount; i++) {
            if(doctors[i].available == 1) {
                patient->doctorId = doctors[i].doctorId;
                doctors[i].available = 0;
                assigned = 1;
                break;
            }
        }
    }
    
    // If no doctor available, assign to any doctor
    if(!assigned) {
        patient->doctorId = doctors[0].doctorId;
    }
}

// Discharge a patient
void dischargePatient() {
    if (patientCount == 0) {
        printf("No patients admitted.\n");
        return;
    }
    
    int patientId;
    printf("Enter Patient ID to discharge: ");
    scanf("%d", &patientId);
    clearInputBuffer();
    
    int index = findPatientById(patientId);
    if(index == -1) {
        printf("Patient not found!\n");
        return;
    }
    
    if(patients[index].isDischarged == 1) {
        printf("Patient already discharged!\n");
        return;
    }
    
    printf("\n--- Patient Discharge ---\n");
    printf("Patient Name: %s\n", patients[index].name);
    printf("Admission Date: %s\n", patients[index].admissionDate);
    
    // Calculate final bill
    float dailyCharges = 200.0;
    int daysAdmitted = 5; // Simplified - would calculate from admission date
    patients[index].billAmount = dailyCharges * daysAdmitted + 500.0; // Including treatment charges
    
    printf("Total Bill Amount: ₹%.2f\n", patients[index].billAmount);
    printf("Do you want to discharge this patient? (1 for Yes / 0 for No): ");
    int confirm;
    scanf("%d", &confirm);
    clearInputBuffer();
    
    if(confirm == 1) {
        patients[index].isDischarged = 1;
        
        // Make assigned doctor available again
        int doctorIdx = findDoctorById(patients[index].doctorId);
        if(doctorIdx != -1) {
            doctors[doctorIdx].available = 1;
        }
        
        printf("✓ Patient discharged successfully!\n");
        printf("Please collect the bill from the reception.\n");
    } else {
        printf("Discharge cancelled.\n");
    }
}

// View all patients
void viewAllPatients() {
    if(patientCount == 0) {
        printf("No patients admitted.\n");
        return;
    }
    
    printf("\n┌─────────────────────────────────────────────────────────────────────────────────────┐\n");
    printf("│                                   PATIENT LIST                                      │\n");
    printf("├───────┬──────────────────┬─────────┬───────────┬──────────────────┬──────────┬────────┤\n");
    printf("│  ID   │      Name        │   Age   │  Gender   │   Doctor         │  Room   │ Status │\n");
    printf("├───────┼──────────────────┼─────────┼───────────┼──────────────────┼──────────┼────────┤\n");
    
    for(int i = 0; i < patientCount; i++) {
        if(!patients[i].isDischarged) {
            int docIdx = findDoctorById(patients[i].doctorId);
            char docName[MAX_NAME_LENGTH] = "Not Assigned";
            if(docIdx != -1) {
                strcpy(docName, doctors[docIdx].name);
            }
            
            printf("│ %-5d │ %-16s │  %-6d │ %-9s │ %-16s │  %3d   │ Active │\n",
                   patients[i].patientId,
                   patients[i].name,
                   patients[i].age,
                   patients[i].gender,
                   docName,
                   patients[i].roomNumber);
        }
    }
    printf("└───────┴──────────────────┴─────────┴───────────┴──────────────────┴──────────┴────────┘\n");
}

// Search patient by ID or name
void searchPatient() {
    if(patientCount == 0) {
        printf("No patients in the system.\n");
        return;
    }
    
    int choice;
    printf("\nSearch by:\n");
    printf("1. Patient ID\n");
    printf("2. Patient Name\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    clearInputBuffer();
    
    if(choice == 1) {
        int patientId;
        printf("Enter Patient ID: ");
        scanf("%d", &patientId);
        clearInputBuffer();
        
        int index = findPatientById(patientId);
        if(index != -1) {
            viewPatientDetails(patientId);
        } else {
            printf("Patient not found!\n");
        }
    } else if(choice == 2) {
        char name[MAX_NAME_LENGTH];
        printf("Enter Patient Name: ");
        fgets(name, MAX_NAME_LENGTH, stdin);
        name[strcspn(name, "\n")] = '\0';
        
        int found = 0;
        for(int i = 0; i < patientCount; i++) {
            if(strcmp(patients[i].name, name) == 0) {
                viewPatientDetails(patients[i].patientId);
                found = 1;
            }
        }
        if(!found) {
            printf("No patient found with this name.\n");
        }
    } else {
        printf("Invalid choice!\n");
    }
}

// View detailed patient information
void viewPatientDetails(int patientId) {
    int index = findPatientById(patientId);
    if(index == -1) {
        printf("Patient not found!\n");
        return;
    }
    
    struct Patient p = patients[index];
    int docIdx = findDoctorById(p.doctorId);
    
    printf("\n╔═══════════════════════════════════════════════════════════════╗\n");
    printf("║                     PATIENT DETAILS                          ║\n");
    printf("╠═══════════════════════════════════════════════════════════════╣\n");
    printf("║ Patient ID    : %-40d ║\n", p.patientId);
    printf("║ Name          : %-40s ║\n", p.name);
    printf("║ Age           : %-40d ║\n", p.age);
    printf("║ Gender        : %-40s ║\n", p.gender);
    printf("║ Blood Group   : %-40s ║\n", p.bloodGroup);
    printf("║ Contact       : %-40s ║\n", p.contact);
    printf("║ Admission Date: %-40s ║\n", p.admissionDate);
    printf("║ Diagnosis     : %-40s ║\n", p.diagnosis);
    printf("║ Medicines     : %-40s ║\n", p.medicines);
    printf("║ Room Number   : %-40d ║\n", p.roomNumber);
    printf("║ Bed Number    : %-40d ║\n", p.bedNumber);
    if(docIdx != -1) {
        printf("║ Doctor        : %-40s ║\n", doctors[docIdx].name);
        printf("║ Specialization: %-40s ║\n", doctors[docIdx].specialization);
    }
    printf("║ Status        : %-40s ║\n", p.isDischarged ? "Discharged" : "Admitted");
    printf("║ Bill Amount   : ₹%-39.2f ║\n", p.billAmount);
    printf("╚═══════════════════════════════════════════════════════════════╝\n");
}

// View all doctors
void viewDoctors() {
    printf("\n┌─────────────────────────────────────────────────────────────────────┐\n");
    printf("│                          DOCTORS LIST                             │\n");
    printf("├──────────┬─────────────────────┬───────────────────────┬──────────┤\n");
    printf("│  ID      │      Name           │   Specialization      │ Status   │\n");
    printf("├──────────┼─────────────────────┼───────────────────────┼──────────┤\n");
    
    for(int i = 0; i < doctorCount; i++) {
        printf("│  %-6d │ %-19s │ %-21s │ %-8s │\n",
               doctors[i].doctorId,
               doctors[i].name,
               doctors[i].specialization,
               doctors[i].available ? "Available" : "Busy");
    }
    printf("└──────────┴─────────────────────┴───────────────────────┴──────────┘\n");
}

// View available beds
void viewAvailableBeds() {
    int admitted = 0;
    for(int i = 0; i < patientCount; i++) {
        if(!patients[i].isDischarged) {
            admitted++;
        }
    }
    
    int totalBeds = MAX_PATIENTS;
    int availableBeds = totalBeds - admitted;
    
    printf("\n╔══════════════════════════════════════════╗\n");
    printf("║          BED OCCUPANCY STATUS            ║\n");
    printf("╠══════════════════════════════════════════╣\n");
    printf("║ Total Beds       : %-20d ║\n", totalBeds);
    printf("║ Occupied Beds    : %-20d ║\n", admitted);
    printf("║ Available Beds   : %-20d ║\n", availableBeds);
    printf("║ Occupancy Rate   : %.1f%%                 ║\n", 
           totalBeds > 0 ? (float)admitted / totalBeds * 100 : 0);
    printf("╚══════════════════════════════════════════╝\n");
    
    // Show detailed bed allocation by room
    printf("\nBed Allocation by Room:\n");
    printf("Room  | Beds\n");
    printf("------+-----------------------------\n");
    for(int room = 101; room < 101 + (MAX_PATIENTS / 4); room++) {
        printf(" %3d  | ", room);
        int bedCount = 0;
        for(int i = 0; i < patientCount; i++) {
            if(patients[i].roomNumber == room && !patients[i].isDischarged) {
                printf("[%d] ", patients[i].bedNumber);
                bedCount++;
            }
        }
        if(bedCount == 0) {
            printf("All beds available");
        }
        printf("\n");
    }
}

// Generate patient bill
void generateBill() {
    int patientId;
    printf("Enter Patient ID: ");
    scanf("%d", &patientId);
    clearInputBuffer();
    
    int index = findPatientById(patientId);
    if(index == -1) {
        printf("Patient not found!\n");
        return;
    }
    
    if(!patients[index].isDischarged) {
        printf("Patient is still admitted. Please discharge first to generate final bill.\n");
        return;
    }
    
    printf("\n╔════════════════════════════════════════════════════════╗\n");
    printf("║                    PATIENT BILL                        ║\n");
    printf("╠════════════════════════════════════════════════════════╣\n");
    printf("║ Hospital: City General Hospital                       ║\n");
    printf("║────────────────────────────────────────────────────────║\n");
    printf("║ Patient ID   : %-35d ║\n", patients[index].patientId);
    printf("║ Patient Name : %-35s ║\n", patients[index].name);
    printf("║────────────────────────────────────────────────────────║\n");
    printf("║ Room Charges : ₹%-30.2f ║\n", 1000.0);
    printf("║ Doctor Fees  : ₹%-30.2f ║\n", 500.0);
    printf("║ Medicine Cost: ₹%-30.2f ║\n", 300.0);
    printf("║ Lab Charges  : ₹%-30.2f ║\n", 200.0);
    printf("║ Other Charges: ₹%-30.2f ║\n", 150.0);
    printf("║────────────────────────────────────────────────────────║\n");
    printf("║ Total Amount : ₹%-30.2f ║\n", patients[index].billAmount);
    printf("╚════════════════════════════════════════════════════════╝\n");
}

// View department statistics
void viewDepartmentStats() {
    if(patientCount == 0) {
        printf("No patients in the system.\n");
        return;
    }
    
    printf("\n╔═══════════════════════════════════════════════════════════╗\n");
    printf("║              DEPARTMENT STATISTICS                       ║\n");
    printf("╠═══════════════════════════════════════════════════════════╣\n");
    
    // Count patients by department (using doctor specialization)
    int cardio = 0, neuro = 0, ortho = 0, pedia = 0, gynae = 0;
    
    for(int i = 0; i < patientCount; i++) {
        if(!patients[i].isDischarged) {
            int docIdx = findDoctorById(patients[i].doctorId);
            if(docIdx != -1) {
                if(strstr(doctors[docIdx].specialization, "Cardiology")) cardio++;
                else if(strstr(doctors[docIdx].specialization, "Neurology")) neuro++;
                else if(strstr(doctors[docIdx].specialization, "Orthopedics")) ortho++;
                else if(strstr(doctors[docIdx].specialization, "Pediatrics")) pedia++;
                else if(strstr(doctors[docIdx].specialization, "Gynecology")) gynae++;
            }
        }
    }
    
    printf("║ Cardiology     : %-33d ║\n", cardio);
    printf("║ Neurology      : %-33d ║\n", neuro);
    printf("║ Orthopedics    : %-33d ║\n", ortho);
    printf("║ Pediatrics     : %-33d ║\n", pedia);
    printf("║ Gynecology     : %-33d ║\n", gynae);
    printf("╠═══════════════════════════════════════════════════════════╣\n");
    printf("║ Total Patients : %-33d ║\n", patientCount);
    printf("╚═══════════════════════════════════════════════════════════╝\n");
}

// Save data to file
void saveDataToFile() {
    FILE *file = fopen("hospital_data.txt", "w");
    if(file == NULL) {
        printf("Error saving data!\n");
        return;
    }
    
    // Save patient data
    fprintf(file, "%d\n", patientCount);
    for(int i = 0; i < patientCount; i++) {
        fprintf(file, "%d\n", patients[i].patientId);
        fprintf(file, "%s\n", patients[i].name);
        fprintf(file, "%d\n", patients[i].age);
        fprintf(file, "%s\n", patients[i].gender);
        fprintf(file, "%s\n", patients[i].contact);
        fprintf(file, "%s\n", patients[i].admissionDate);
        fprintf(file, "%s\n", patients[i].diagnosis);
        fprintf(file, "%s\n", patients[i].medicines);
        fprintf(file, "%d\n", patients[i].doctorId);
        fprintf(file, "%d\n", patients[i].roomNumber);
        fprintf(file, "%d\n", patients[i].bedNumber);
        fprintf(file, "%s\n", patients[i].bloodGroup);
        fprintf(file, "%f\n", patients[i].billAmount);
        fprintf(file, "%d\n", patients[i].isDischarged);
    }
    
    // Save doctor data
    fprintf(file, "%d\n", doctorCount);
    for(int i = 0; i < doctorCount; i++) {
        fprintf(file, "%d\n", doctors[i].doctorId);
        fprintf(file, "%s\n", doctors[i].name);
        fprintf(file, "%s\n", doctors[i].specialization);
        fprintf(file, "%d\n", doctors[i].available);
    }
    
    fprintf(file, "%d\n", nextPatientId);
    fprintf(file, "%d\n", nextDoctorId);
    
    fclose(file);
}

// Load data from file
void loadDataFromFile() {
    FILE *file = fopen("hospital_data.txt", "r");
    if(file == NULL) {
        return;
    }
    
    // Load patient data
    fscanf(file, "%d", &patientCount);
    for(int i = 0; i < patientCount && i < MAX_PATIENTS; i++) {
        fscanf(file, "%d", &patients[i].patientId);
        fgetc(file);
        fgets(patients[i].name, MAX_NAME_LENGTH, file);
        patients[i].name[strcspn(patients[i].name, "\n")] = '\0';
        fscanf(file, "%d", &patients[i].age);
        fgetc(file);
        fgets(patients[i].gender, 10, file);
        patients[i].gender[strcspn(patients[i].gender, "\n")] = '\0';
        fgets(patients[i].contact, MAX_NAME_LENGTH, file);
        patients[i].contact[strcspn(patients[i].contact, "\n")] = '\0';
        fgets(patients[i].admissionDate, 20, file);
        patients[i].admissionDate[strcspn(patients[i].admissionDate, "\n")] = '\0';
        fgets(patients[i].diagnosis, MAX_DIAGNOSIS_LENGTH, file);
        patients[i].diagnosis[strcspn(patients[i].diagnosis, "\n")] = '\0';
        fgets(patients[i].medicines, MAX_MEDICINE_LENGTH, file);
        patients[i].medicines[strcspn(patients[i].medicines, "\n")] = '\0';
        fscanf(file, "%d", &patients[i].doctorId);
        fscanf(file, "%d", &patients[i].roomNumber);
        fscanf(file, "%d", &patients[i].bedNumber);
        fgetc(file);
        fgets(patients[i].bloodGroup, 5, file);
        patients[i].bloodGroup[strcspn(patients[i].bloodGroup, "\n")] = '\0';
        fscanf(file, "%f", &patients[i].billAmount);
        fscanf(file, "%d", &patients[i].isDischarged);
    }
    
    // Load doctor data
    fscanf(file, "%d", &doctorCount);
    for(int i = 0; i < doctorCount && i < MAX_DOCTORS; i++) {
        fscanf(file, "%d", &doctors[i].doctorId);
        fgetc(file);
        fgets(doctors[i].name, MAX_NAME_LENGTH, file);
        doctors[i].name[strcspn(doctors[i].name, "\n")] = '\0';
        fgets(doctors[i].specialization, MAX_NAME_LENGTH, file);
        doctors[i].specialization[strcspn(doctors[i].specialization, "\n")] = '\0';
        fscanf(file, "%d", &doctors[i].available);
    }
    
    fscanf(file, "%d", &nextPatientId);
    fscanf(file, "%d", &nextDoctorId);
    
    fclose(file);
}

// Helper function to find patient by ID
int findPatientById(int patientId) {
    for(int i = 0; i < patientCount; i++) {
        if(patients[i].patientId == patientId) {
            return i;
        }
    }
    return -1;
}

// Helper function to find doctor by ID
int findDoctorById(int doctorId) {
    for(int i = 0; i < doctorCount; i++) {
        if(doctors[i].doctorId == doctorId) {
            return i;
        }
    }
    return -1;
}

// Generate admission date (current date)
void generateAdmissionDate(char *date) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(date, "%02d/%02d/%04d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
}

// Clear input buffer
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}