#include "datetype.h"

//Student
void pressToExitOrReturn();
void loadStudentsFromFile(Student students[], int *n);
void inputStudent(Student students[], int *n);
void printStudent(Student students[], int n);
void updateStudent(Student students[], int n);
void deleteStudent(Student students[], int *n);
void sortStudents(Student students[], int n);
void displayStudentsMenu();
void displayMainMenu();
void saveStudentsToFile(Student students[], int n);
void searchStudentByName(Student students[], int n);

//Teacher
void displayTeachersMenu();

void loadTeachersFromFile(Teacher teachers[], int *n);
void saveTeachersToFile(Teacher teachers[], int n);
void inputStudent(Student students[], int *n);
void updateTeacher(Teacher teachers[], int n);
void searchTeacherByName(Teacher teachers[], int n);
void deleteTeacher(Teacher teachers[], int *n);


// Classroom
void displayClassroomsMenu();
