#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATIENTS 100
#define MAX_NAME_LENGTH 50

// Structure to hold patient information
typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    char gender[MAX_NAME_LENGTH];
    char diagnosis[MAX_NAME_LENGTH];
} Patient;

// Function prototypes
void addPatient(Patient patients[], int *count);
void editPatient(Patient patients[], int count);
void deletePatient(Patient patients[], int *count);
void displayPatients(Patient patients[], int count);
void saveData(Patient patients[], int count);
void loadData(Patient patients[], int *count);

int main() {
    Patient patients[MAX_PATIENTS];
    int count = 0;
    int choice;
    // Load existing data from file
    loadData(patients, &count);
    do {
        printf("\nHospital Management System\n");
        printf("1. Add Patient\n");
        printf("2. Edit Patient\n");
        printf("3. Delete Patient\n");
        printf("4. Display Patients\n");
        printf("5. Save Data\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addPatient(patients, &count);
                break;
            case 2:
                editPatient(patients, count);
                break;
            case 3:
                deletePatient(patients, &count);
                break;
            case 4:
                displayPatients(patients, count);
                break;
            case 5:
                saveData(patients, count);
                break;
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 6.\n");
        }
    } while(choice != 6);

    return 0;
}

// Function to add a patient
void addPatient(Patient patients[], int *count) {
    if (*count >= MAX_PATIENTS) {
        printf("Hospital is full. Cannot add more patients.\n");
        return;
    }

    Patient newPatient;
    printf("Enter patient name: ");
    scanf("%s", newPatient.name);
    printf("Enter patient age: ");
    scanf("%d", &newPatient.age);
    printf("Enter patient gender: ");
    scanf("%s", newPatient.gender);
    printf("Enter patient diagnosis: ");
    scanf("%s", newPatient.diagnosis);

    patients[*count] = newPatient;
    (*count)++;

    printf("Patient added successfully.\n");
}

// Function to edit a patient
void editPatient(Patient patients[], int count) {
    if (count == 0) {
        printf("No patients to edit.\n");
        return;
    }

    char searchName[MAX_NAME_LENGTH];
    printf("Enter name of patient to edit: ");
    scanf("%s", searchName);

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(patients[i].name, searchName) == 0) {
            printf("Enter new age for %s: ", patients[i].name);
            scanf("%d", &patients[i].age);
            printf("Enter new gender for %s: ", patients[i].name);
            scanf("%s", patients[i].gender);
            printf("Enter new diagnosis for %s: ", patients[i].name);
            scanf("%s", patients[i].diagnosis);
            found = 1;
            printf("Patient information updated.\n");
            break;
        }
    }

    if (!found) {
        printf("Patient not found.\n");
    }
}

// Function to delete a patient
void deletePatient(Patient patients[], int *count) {
    if (*count == 0) {
        printf("No patients to delete.\n");
        return;
    }

    char searchName[MAX_NAME_LENGTH];
    printf("Enter name of patient to delete: ");
    scanf("%s", searchName);

    int found = 0;
    for (int i = 0; i < *count; i++) {
        if (strcmp(patients[i].name, searchName) == 0) {
            for (int j = i; j < *count - 1; j++) {
                patients[j] = patients[j + 1];
            }
            (*count)--;
            found = 1;
            printf("Patient deleted successfully.\n");
            break;
        }
    }

    if (!found) {
        printf("Patient not found.\n");
    }
}

// Function to display all patients
void displayPatients(Patient patients[], int count) {
    if (count == 0) {
        printf("No patients to display.\n");
        return;
    }

    printf("\nPatient Records:\n");
    printf("Name\tAge\tGender\tDiagnosis\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t%d\t%s\t%s\n", patients[i].name, patients[i].age, patients[i].gender, patients[i].diagnosis);
    }
}

// Function to save data to file
void saveData(Patient patients[], int count) {
    FILE *fp = fopen("patients.txt", "w");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(fp, "%s %d %s %s\n", patients[i].name, patients[i].age, patients[i].gender, patients[i].diagnosis);
    }

    fclose(fp);
    printf("Data saved to file.\n");
}

// Function to load data from file
void loadData(Patient patients[], int *count) {
    FILE *fp = fopen("patients.txt", "r");
    if (fp == NULL) {
        printf("No existing data found.\n");
        return;
    }

        while ((*count < MAX_PATIENTS) && (fscanf(fp, "%s %d %s %s", patients[*count].name, &patients[*count].age, patients[*count].gender, patients[*count].diagnosis) != EOF)) {
            (*count)++;
        }

    fclose(fp);
    printf("Data loaded successfully.\n");
}
