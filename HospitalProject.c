#include <stdio.h>
#include <string.h>
struct Patient {
    int patient_ID;
    char name[50];
    int age;
    char gender[10];
    char symptoms[100];
};
struct Patient hospital[100];
int total_patients = 0;       
void addPatient();
void viewPatients();
void searchPatient();
void updatePatient();
void deletePatient();
int main() {
    int choice;
    do {
        printf("\n======================================================\n");
        printf("||             HOSPITAL PATIENT MANAGEMENT          ||\n");
        printf("======================================================\n");
        printf("+----------------------------------------------------+\n");
        printf("|                   MAIN MENU                        |\n");
        printf("+----------------------------------------------------+\n");
        printf("| 1. |  Add Patient                                  |\n");
        printf("| 2. |  View Patients                                |\n");
        printf("| 3. |  Search Patient                               |\n");
        printf("| 4. |  Update Patient                               |\n");
        printf("| 5. |  Delete Patient                               |\n");
        printf("| 6. |  Exit                                         |\n");
        printf("+----------------------------------------------------+\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: addPatient(); break;
            case 2: viewPatients(); break;
            case 3: searchPatient(); break;
            case 4: updatePatient(); break;
            case 5: deletePatient(); break;
            case 6: printf("Exiting System...\n"); break;
            default: printf("Invalid Choice! Please enter between 1-6.\n");
        }
        if(choice != 6) {
            printf("\nPress Enter to return to the main menu...");
            while(getchar() != '\n');
            getchar(); 
        }
    } while(choice != 6);
    
    return 0;
}

void addPatient() {
    printf("\n+----- PATIENT REGISTRATION -----+\n");
    if(total_patients < 100) {
        printf("Patient ID: ");
        scanf("%d", &hospital[total_patients].patient_ID);
        printf("Patient Name: ");
        scanf("%s", hospital[total_patients].name);
        printf("Age: ");
        scanf("%d", &hospital[total_patients].age);
        printf("Gender: ");
        scanf("%s", hospital[total_patients].gender);
        printf("Symptoms: ");
        scanf("%s", hospital[total_patients].symptoms);
        
        total_patients++;
        printf("Patient added successfully!\n");
    } else {
        printf("Hospital capacity is full!\n");
    }
}

void viewPatients() {
    printf("\n+----- VIEW ALL PATIENTS -----+\n");
    if(total_patients == 0) {
        printf("No patients registered yet.\n");
        return;
    }
    printf("ID\tName\t\tAge\tGender\tSymptoms\n");
    printf("------------------------------------------------------\n");
    for(int i = 0; i < total_patients; i++) {
        printf("%d\t%s\t\t%d\t%s\t%s\n", 
               hospital[i].patient_ID, hospital[i].name, 
               hospital[i].age, hospital[i].gender, hospital[i].symptoms);
    }
}

void searchPatient() {
    int id, found = 0;
    printf("\n+----- SEARCH PATIENT -----+\n");
    printf("Enter Patient ID to search: ");
    scanf("%d", &id);
    
    for(int i = 0; i < total_patients; i++) {
        if(hospital[i].patient_ID == id) {
            printf("\nPatient Found!\n");
            printf("Name: %s\nAge: %d\nGender: %s\nSymptoms: %s\n", 
                   hospital[i].name, hospital[i].age, hospital[i].gender, hospital[i].symptoms);
            found = 1;
            break;
        }
    }
    if(found == 0) printf("Patient with ID %d not found.\n", id);
}

void updatePatient() {
    int id, found = 0;
    printf("\n+----- UPDATE PATIENT -----+\n");
    printf("Enter Patient ID to update: ");
    scanf("%d", &id);
    
    for(int i = 0; i < total_patients; i++) {
        if(hospital[i].patient_ID == id) {
            printf("Enter New Name: ");
            scanf("%s", hospital[i].name);
            printf("Enter New Age: ");
            scanf("%d", &hospital[i].age);
            printf("Enter New Symptoms: ");
            scanf("%s", hospital[i].symptoms);
            printf("Patient record updated successfully!\n");
            found = 1;
            break;
        }
    }
    if(found == 0) printf("Patient with ID %d not found.\n", id);
}

void deletePatient() {
    int id, found = 0;
    printf("\n+----- DELETE PATIENT -----+\n");
    printf("Enter Patient ID to delete: ");
    scanf("%d", &id);
    
    for(int i = 0; i < total_patients; i++) {
        if(hospital[i].patient_ID == id) {
            found = 1;
            // Shift all elements one position to the left
            for(int j = i; j < total_patients - 1; j++) {
                hospital[j] = hospital[j + 1];
            }
            total_patients--; // Decrease patient count
            printf("Patient ID %d deleted successfully!\n", id);
            break;
        }
    }
    if(found == 0) printf("Patient with ID %d not found.\n", id);
}