#include "dataBase.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Add students from file
void add_student_from_file(Student** head)
{
    char filename[100];
    printf("Enter the filename: ");
    scanf("%s", filename);
    FILE *file = fopen(filename, "r");
    if (!file)
    {
        printf("Unable to open file.\n");
        return;
    }

    while (!feof(file))
    {
        Student* temp = (Student*)malloc(sizeof(Student));
        if (!temp)
        {
            printf("Memory allocation failed!\n");
            fclose(file);
            return;
        }

        fscanf(file, "%d %s %s %f %s", &temp->Student_data.roll_number, temp->Student_data.first_name, temp->Student_data.last_name, &temp->Student_data.GPA, temp->Student_data.Course);
        temp->next = *head;
        *head = temp;
    }
    fclose(file);
    printf("Student details added from file.\n");
}

// Add a new student manually
void Add_Student_Manually(Student** head)
{
    Student* newStudent = (Student*)malloc(sizeof(Student));
    if (newStudent == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    // Input student details
    printf("Enter first name: ");
    scanf("%s", newStudent->Student_data.first_name);
    printf("Enter last name: ");
    scanf("%s", newStudent->Student_data.last_name);
    printf("Enter roll number: ");
    scanf("%d", &newStudent->Student_data.roll_number);
    printf("Enter GPA: ");
    scanf("%f", &newStudent->Student_data.GPA);
    printf("Enter course: ");
    scanf("%s", newStudent->Student_data.Course);

    // Add to the beginning of the list
    newStudent->next = *head;
    *head = newStudent;

    printf("Student has been added successfully...\n");
}

// Find student by roll number
void find_student_by_roll_number(Student** head)
{
    int id;
    printf("Enter roll number: ");
    scanf("%d", &id);

    Student* temp = *head;

    while (temp != NULL)
    {
        if (temp->Student_data.roll_number == id)
        {
            display_student(temp);
            return;
        }
        temp = temp->next;
    }
    printf("Student not found.\n");
}

// Find student by first name
void find_student_by_first_name(Student** head)
{
    char first[20];
    printf("Enter first name: ");
    scanf("%s", first);

    Student* temp = *head;

    while (temp != NULL)
    {
        if (strcmp(temp->Student_data.first_name, first) == 0)
        {
            display_student(temp);
            return;
        }
        temp = temp->next;
    }
    printf("Student not found.\n");
}

// Find students by course
void find_students_by_course(Student** head)
{
    char course[MAX_SIZE];
    printf("Enter course: ");
    scanf("%s", course);

    Student* temp = *head;

    while (temp != NULL)
    {
        if (strcmp(temp->Student_data.Course, course) == 0)
        {
            display_student(temp);
            return;
        }
        temp = temp->next;
    }
    printf("Student not found.\n");
}

// Count the number of students
void count_students(Student** head)
{
    Student* temp = *head;
    int count = 0;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    printf("Total number of students: %d\n", count);
}

// Delete a student by roll number
void delete_student(Student** head)
{
    int id;
    printf("Enter roll number of the student to delete: ");
    scanf("%d", &id);

    Student* temp = *head;
    Student* prev = NULL;

    // If the student to be deleted is the head
    if (temp != NULL && temp->Student_data.roll_number == id)
    {
        *head = temp->next; // Update the head to the next node
        free(temp); // Free the memory of the old head
        printf("Student with roll number %d deleted.\n", id);
        return;
    }

    // Traverse the list to find the student with the given roll number
    while (temp != NULL && temp->Student_data.roll_number != id)
    {
        prev = temp;
        temp = temp->next;
    }

    // Unlink the node from the list
    prev->next = temp->next;
    free(temp); // Free the memory of the node to be deleted
    printf("Student with roll number %d deleted.\n", id);
}

void update_student(Student** head)
{
    int roll_number;
    printf("Enter roll number of the student to update: ");
    scanf("%d", &roll_number);
    Student* temp = *head;
    while (temp != NULL) {
        if (temp->Student_data.roll_number == roll_number) {
            printf("Enter new first name: ");
            scanf("%s", temp->Student_data.first_name);
            printf("Enter new last name: ");
            scanf("%s", temp->Student_data.last_name);
            printf("Enter new course: ");
            scanf("%s", temp->Student_data.Course);
            printf("Student updated successfully.\n");
            return;
        }
        temp = temp->next;
    }
    printf("Student not found.\n");
}

// Display a single student's details
void display_student(Student* student)
{
    printf("Roll Number: %d\n", student->Student_data.roll_number);
    printf("First Name: %s\n", student->Student_data.first_name);
    printf("Last Name: %s\n", student->Student_data.last_name);
    printf("GPA: %.2f\n", student->Student_data.GPA);
    printf("Course: %s\n", student->Student_data.Course);
}
