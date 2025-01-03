#include <stdio.h>
#include <string.h>
#include "Function.h"
// student
void searchStudentByName(Student students[], int n) {
    char searchName[30];
    int i;
    int found = 0;  

    printf("Enter the name of the student you want to search: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0';  

    printf("\nSearch Results for '%s':\n", searchName);
    printf("ID   | Name                | Classroom | Gender    | Email                   | Phone\n");
    printf("-----------------------------------------------------------------------------------\n");
    for ( i = 0; i < n; i++) {
        if (strstr(students[i].name, searchName) != NULL) {  // T�m t�n ch?a chu?i searchName
            printf("%-4d | %-20s | %-9d | %-9s | %-23s | %-15s\n",
                   students[i].id, students[i].name, students[i].classroomId, students[i].gender,
                   students[i].email, students[i].phone);
            found = 1;
        }
    }

    if (!found) {
        printf("No students found with the name '%s'.\n", searchName);
    }
}

void pressToExitOrReturn() {
    char choice;
    printf("\nPress [0] to exit the program or [b] to return to the menu: ");
    scanf(" %c", &choice);

    if (choice == '0') {
        printf("Exiting the program...\n");
        exit(0);
    } else if (choice == 'b' || choice == 'B') {
        printf("Returning to the menu...\n");
        return; 
    } else {
        printf("Invalid input. Returning to the menu...\n");
        return; 
    }    
}
	int isValidEmail(const char *email) {
    return (strstr(email, "@") != NULL && strstr(email, ".") != NULL);
}
	int isValidPhoneNumber(const char *phone) {
	int i;
    for ( i = 0; phone[i] != '\0'; i++) {
        if (phone[i] < '0' || phone[i] > '9') {
            return 0;  
        }
    }
    return 1;
}

void inputStudent(Student students[], int *n) {
    int num, i, j, id_exists, email_exists, phone_exists;
    printf("Enter the number of students to add: ");
    scanf("%d", &num);
    getchar();  

    for (i = 0; i < num; i++) {
        id_exists = 1;  
        while (id_exists) {
            printf("Enter student ID: ");
            scanf("%d", &students[*n].id);
            getchar();  
            id_exists = 0;
            for (j = 0; j < *n; j++) {
                if (students[j].id == students[*n].id) {
                    id_exists = 1; 
                    printf("ID already exists. Please enter a different ID.\n");
                    break;
                }
            }
        }
        printf("Enter student name: ");
        fgets(students[*n].name, sizeof(students[*n].name), stdin);
        students[*n].name[strcspn(students[*n].name, "\n")] = '\0'; 
        if (strlen(students[*n].name) == 0) {
            printf("Name cannot be empty. Please enter a valid name.\n");
            i--;
            continue;
        }

       
        printf("Enter classroom ID: ");
        scanf("%d", &students[*n].classroomId);
        getchar();  // Clear newline
        printf("Enter gender: ");
        fgets(students[*n].gender, sizeof(students[*n].gender), stdin);
        students[*n].gender[strcspn(students[*n].gender, "\n")] = '\0';  
        if (strlen(students[*n].gender) == 0) {
            printf("Gender cannot be empty. Please enter a valid gender.\n");
            i--;
            continue;
        }

        email_exists = 1;
        while (email_exists) {
            printf("Enter email: ");
            fgets(students[*n].email, sizeof(students[*n].email), stdin);
            students[*n].email[strcspn(students[*n].email, "\n")] = '\0';

            if (strlen(students[*n].email) == 0) {
                printf("Email cannot be empty. Please enter a valid email.\n");
                i--;
                continue;
            }
            if (!isValidEmail(students[*n].email)) {
                printf("Invalid email format. Please enter a valid email.\n");
                i--;
                continue;
            }

            email_exists = 0;
            for (j = 0; j < *n; j++) {
                if (strcmp(students[j].email, students[*n].email) == 0) {
                    email_exists = 1;  // N?u tr�ng email, y�u c?u nh?p l?i
                    printf("Email already exists. Please enter a different email.\n");
                    break;
                }
            }
        }

        phone_exists = 1;
        while (phone_exists) {
            printf("Enter phone number: ");
            fgets(students[*n].phone, sizeof(students[*n].phone), stdin);
            students[*n].phone[strcspn(students[*n].phone, "\n")] = '\0';

            if (strlen(students[*n].phone) == 0) {
                printf("Phone number cannot be empty. Please enter a valid phone number.\n");
                i--;
                continue;
            }
      
            if (!isValidPhoneNumber(students[*n].phone)) {
                printf("Invalid phone number. Please enter a valid phone number.\n");
                i--;
                continue;
            }
            phone_exists = 0;
            for (j = 0; j < *n; j++) {
                if (strcmp(students[j].phone, students[*n].phone) == 0) {
                    phone_exists = 1;  // N?u tr�ng s? di?n tho?i, y�u c?u nh?p l?i
                    printf("Phone number already exists. Please enter a different phone number.\n");
                    break;
                }
            }
        }

        (*n)++;
    }
    printf("%d students have been added to the list.\n", num);
}

void printStudent(Student students[], int n) {
    int i;
    printf("\nStudent List:\n");
    printf("ID   | Name                | Classroom | Gender    | Email                   | Phone\n");
    printf("-----------------------------------------------------------------------------------\n");
    for (i = 0; i < n; i++) {
        printf("%-4d | %-20s | %-9d | %-9s | %-23s | %-15s\n",
               students[i].id, students[i].name, students[i].classroomId, students[i].gender,
               students[i].email, students[i].phone);
    }
    pressToExitOrReturn();
}

void updateStudent(Student students[], int n) {
    int id, new_id, i,j, id_exists;
    printf("Enter the ID of the student to update: ");
    scanf("%d", &id);
    getchar(); 

    for (i = 0; i < n; i++) {
        if (students[i].id == id) {
            break;
        }
    }

    if (i == n) {
        printf("Student with ID %d does not exist.\n", id);
    } else {
        printf("Current information:\n");
        printf("Name: %s\n", students[i].name);
        printf("Classroom ID: %d\n", students[i].classroomId);
        printf("Gender: %s\n", students[i].gender);
        printf("Email: %s\n", students[i].email);
        printf("Phone: %s\n", students[i].phone);
        
        id_exists = 1;
        while (id_exists) {
            printf("Enter new student ID: ");
            scanf("%d", &new_id);
            getchar();

            id_exists = 0;
            for ( j = 0; j < n; j++) {
                if (students[j].id == new_id && new_id != students[i].id) {
                    id_exists = 1;
                    printf("ID already exists. Please enter a different ID.\n");
                    break;
                }
            }

            if (!id_exists) {
                students[i].id = new_id;
            }
        }
        printf("Enter new name: ");
        fgets(students[i].name, 50, stdin);
        students[i].name[strcspn(students[i].name, "\n")] = '\0';

        printf("Enter new classroom ID: ");
        scanf("%d", &students[i].classroomId);
        getchar();

        printf("Enter new gender: ");
        fgets(students[i].gender, 10, stdin);
        students[i].gender[strcspn(students[i].gender, "\n")] = '\0';

        printf("Enter new email: ");
        fgets(students[i].email, 50, stdin);
        students[i].email[strcspn(students[i].email, "\n")] = '\0';

        printf("Enter new phone number: ");
        fgets(students[i].phone, 20, stdin);
        students[i].phone[strcspn(students[i].phone, "\n")] = '\0';

        printf("Student information updated successfully.\n");
    }
    pressToExitOrReturn();
}



void deleteStudent(Student students[], int *n) {
    int id, i, j;
    char confirm;
    printf("Enter the ID of the student to delete: ");
    scanf("%d", &id);
    for (i = 0; i < *n; i++) {
        if (students[i].id == id) {
            break;
        }
    }

    if (i == *n) {
        printf("Student with ID %d does not exist.\n", id);
    } else {
        printf("\nStudent to be deleted:\n");
        printf("Name: %s\n", students[i].name);
        printf("Classroom ID: %d\n", students[i].classroomId);
        printf("Gender: %s\n", students[i].gender);
        printf("Email: %s\n", students[i].email);
        printf("Phone: %s\n", students[i].phone);
        printf("\nAre you sure you want to delete this student? (y/n): ");
        scanf(" %c", &confirm);  

        if (confirm == 'y' || confirm == 'Y') {
            for (j = i; j < *n - 1; j++) {
                students[j] = students[j + 1];
            }
            (*n)--;  
            printf("Student with ID %d has been deleted.\n", id);
        } else {
            printf("Deletion canceled.\n");
        }
    }

    pressToExitOrReturn();
}


void sortStudents(Student students[], int n) {
    int choice;
    printf("\nChoose sorting option:\n");
    printf("[1] Sort by ID\n");
    printf("[2] Sort by Name\n");
    printf("[3] Sort by Classroom ID\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    getchar();
    Student temp;
    int i,j;
    switch (choice) {
        case 1:
            for (i = 0; i < n - 1; i++) {
                for (j = i + 1; j < n; j++) {
                    if (students[i].id > students[j].id) {
                        temp = students[i];
                        students[i] = students[j];
                        students[j] = temp;
                    }
                }
            }
            break;
        case 2:
            for ( i = 0; i < n - 1; i++) {
                for (j = i + 1; j < n; j++) {
                    if (strcmp(students[i].name, students[j].name) > 0) {
                        temp = students[i];
                        students[i] = students[j];
                        students[j] = temp;
                    }
                }
            }
            break;
        case 3:
            for ( i = 0; i < n - 1; i++) {
                for ( j = i + 1; j < n; j++) {
                    if (students[i].classroomId > students[j].classroomId) {
                        temp = students[i];
                        students[i] = students[j];
                        students[j] = temp;
                    }
                }
            }
            break;
        default:
            printf("Invalid choice.\n");
            return;
    }

    printf("Students sorted successfully.\n");
    printStudent(students, n);
}

void displayStudentsMenu() {
    Student students[100];
    int n = 0;
    int studentChoice;
    loadStudentsFromFile(students, &n);
    do {
        printf("\n*** Student Management System Using C ***\n");
        printf("         =========MENU=========\n");
        printf("         [1] Input A New Student.\n");
        printf("         [2] Show All Students.\n");
        printf("         [3] Update A Student.\n");
        printf("         [4] Delete A Student.\n");
        printf("         [5] Sort Students\n");
        printf("         [6] Search Student By Name\n");
        printf("         [0] Exit Program.\n");
        printf("         ======================\n");
        printf("         Enter Your Choice: ");
        scanf("%d", &studentChoice);
        getchar();

        switch (studentChoice) {
            case 1:
                inputStudent(students, &n);
                saveStudentsToFile(students, n);
                break;
            case 2:
                printStudent(students, n);
            
                break;
            case 3:
                updateStudent(students, n);
                saveStudentsToFile(students, n);
                break;
            case 4:
                deleteStudent(students, &n);
                saveStudentsToFile(students, n);
                break;
            case 5:
                sortStudents(students, n);
                saveStudentsToFile(students, n);
                break;
            case 6:
 				 searchStudentByName( students,  n);
                saveStudentsToFile(students, n);
                break;
            case 0:
                printf("Returning to Main Menu...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (studentChoice != 0);
}

void displayMainMenu() {
    printf("***Student Management System Using C***\n");
    printf("       CHOOSE YOUR ROLE\n ");
    printf("\n===============================\n");
    printf("[1] Student\n");
    printf("[2] Teacher.\n");
    printf("[3] Classroom.\n");
    printf("[0] Exit The Program\n");
    printf("=================================\n");
    printf("Your choice: ");
}

void saveStudentsToFile(Student students[], int n) {
    FILE *file = fopen("student.bin", "wb");
    if (file == NULL) {
        printf("Could not open file.\n");
        return;
    }
    fwrite(students, sizeof(Student), n, file);
    fclose(file);
    printf("Student information saved successfully.\n");
}

void loadStudentsFromFile(Student students[], int *n) {
    FILE *file = fopen("student.bin", "rb");
    if (file == NULL) {
        printf("Could not open file.\n");
        return;
    }
    *n = fread(students, sizeof(Student), 100, file);
    fclose(file);
    printf("Student data loaded successfully.\n");
}

// jun teacher


void displayTeachersMenu() {
	Teacher teachers[100];
    int n = 0;
    int teacherChoice;
    loadTeachersFromFile(teachers, &n);
    
    do {
        printf("\n*** Student Management System Using C ***\n");
        printf("         =========MENU=========\n");
        printf("         [1] Display list of teachers.\n");
        printf("         [2] Add more teachers.\n");
        printf("         [3] Edit teacher information.\n");
        printf("         [4] Delete teacher.\n");
        printf("         [5] Search for teachers.\n");
        printf("         [6] Add classes for teachers.\n");
        printf("         [0] Exit Program.\n");
        printf("         ======================\n");
        printf("         Enter Your Choice: ");
        scanf("%d", &teacherChoice);
        getchar();

        switch (teacherChoice) { 
            case 1:
                
                printf("Displaying list of teachers...\n");
                break;
            case 2:
                printf("Adding more teachers...\n");
                break;
            case 3:
                printf("Editing teacher information...\n");
                break;
            case 4:
                printf("Deleting teacher...\n");
                break;
            case 5:
                printf("Searching for teachers...\n");
                break;
            case 6:
                printf("Adding classes for teachers...\n");
                break;
            case 0:
                printf("Returning to Main Menu...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (teacherChoice != 0);  
}
