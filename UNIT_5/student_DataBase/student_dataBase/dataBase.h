#ifndef _DATABASE_H
#define _DATABASE_H

#define MAX_SIZE 50

typedef struct
{
    int roll_number;
    char first_name[MAX_SIZE];
    char last_name[MAX_SIZE];
    float GPA;
    char Course[MAX_SIZE];
}Data;

typedef struct
{
    Data Student_data;
    struct Student* next;
} Student;
void add_student_from_file(Student** head);
void Add_Student_Manually(Student** head);
void find_student_by_roll_number(Student** head);
void find_student_by_first_name(Student** head);
void find_students_by_course(Student** head);
void count_students(Student** head);
void delete_student(Student** head);
void update_student(Student** head);
void display_student(Student* head);
#endif // _DATABASE_H

