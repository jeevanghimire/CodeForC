#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 50

// Structure to hold student information
typedef struct
{
  char name[MAX_NAME_LENGTH];
  int age;
  float gpa;
} Student;

// Function prototypes
void addStudent(Student students[], int *count);
void editStudent(Student students[], int count);
void deleteStudent(Student students[], int *count);
void displayStudents(Student students[], int count);

int main()
{
  Student students[MAX_STUDENTS];
  int count = 0;
  int choice;

  do
  {
    printf("\nStudent Database Management System\n");
    printf("1. Add Student\n");
    printf("2. Edit Student\n");
    printf("3. Delete Student\n");
    printf("4. Display Students\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      addStudent(students, &count);
      break;
    case 2:
      editStudent(students, count);
      break;
    case 3:
      deleteStudent(students, &count);
      break;
    case 4:
      displayStudents(students, count);
      break;
    case 5:
      printf("Exiting program.\n");
      break;
    default:
      printf("Invalid choice. Please enter a number between 1 and 5.\n");
    }
  } while (choice != 5);

  return 0;
}

// Function to add a student
void addStudent(Student students[], int *count)
{
  if (*count >= MAX_STUDENTS)
  {
    printf("Database is full. Cannot add more students.\n");
    return;
  }

  Student newStudent;
  printf("Enter student name: \n");
  scanf("%s", newStudent.name);
  printf("Enter student age: \n");
  scanf("%d", &newStudent.age);
  printf("Enter student GPA: \n");
  scanf("%f", &newStudent.gpa);

  students[*count] = newStudent;
  (*count)++;

  printf("Student added successfully.\n");
}

// Function to edit a student
void editStudent(Student students[], int count)
{
  if (count == 0)
  {
    printf("No students to edit.\n");
    return;
  }

  char searchName[MAX_NAME_LENGTH];
  printf("Enter name of student to edit: ");
  scanf("%s", searchName);

  int found = 0;
  for (int i = 0; i < count; i++)
  {
    if (strcmp(students[i].name, searchName) == 0)
    {
      printf("Enter new age for %s: \n", students[i].name);
      scanf("%d", &students[i].age);
      printf("Enter new GPA for %s: \n", students[i].name);
      scanf("%f", &students[i].gpa);
      found = 1;
      printf("Student information updated.\n");
      break;
    }
  }

  if (!found)
  {
    printf("Student not found.\n");
  }
}

// Function to delete a student
void deleteStudent(Student students[], int *count)
{
  if (*count == 0)
  {
    printf("No students to delete.\n");
    return;
  }

  char searchName[MAX_NAME_LENGTH];
  printf("Enter name of student to delete: \n");
  scanf("%s", searchName);

  int found = 0;
  for (int i = 0; i < *count; i++)
  {
    if (strcmp(students[i].name, searchName) == 0)
    {
      for (int j = i; j < *count - 1; j++)
      {
        students[j] = students[j + 1];
      }
      (*count)--;
      found = 1;
      printf("Student deleted successfully.\n");
      break;
    }
  }

  if (!found)
  {
    printf("Student not found.\n");
  }
}

// Function to display all students
void displayStudents(Student students[], int count)
{
  if (count == 0)
  {
    printf("No students to display.\n");
    return;
  }

  printf("\nStudent Records:\n");
  printf("Name\tAge\tGPA\n");
  for (int i = 0; i < count; i++)
  {
    printf("%s\t%d\t%.2f\n", students[i].name, students[i].age, students[i].gpa);
  }
}
