#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


struct Student{
    char name[20];
    int roll_number;
    int age;
    float GPA;
};

bool validation(struct Student *s){
    if(s->name[0] == '\0' && s->roll_number == -1 && s->age == -1 && s->GPA == -1){
        return true;
    }
    else return false;
}
void addStudent(struct Student *s){
    printf("Enter student details:\n");
    printf("Name: ");
    scanf("%s", s->name);
    printf("Matric Number: ");
    scanf("%d", &s->roll_number);
    printf("Age: ");
    scanf("%d", &s->age);
    printf("GPA: ");
    scanf("%f", &s->GPA);
    printf("Student added successfully !\n");
}

void displayStudent(struct Student s, bool validation){
    bool validation = false;
    if(validation==false){
        printf("No student record found !\n");
        return;
    }
    printf("Student Record:\n");
    printf("Name: %s\n", s.name);
    printf("Matric Number: %d\n", s.roll_number);
    printf("Age: %d\n", s.age);
    printf("GPA: %f\n", s.GPA);
}

void searchStudent(struct Student *s, char search_name[50]){
    printf("Enter the name of the student to search: ");
    scanf("%s", search_name);

    
    if(s->name == search_name){
        printf("Student found: \n");
        displayStudent(*s);
    }
    else{
        printf("Student not found !\n");
    }
}


void updateStudent(struct Student *s, int roll_number){
    printf("Enter the matric number of the student to update: ");
    scanf("%d", &roll_number);
    if(s->roll_number == roll_number){
        printf("Enter updated details:\n");
        printf("Name: ");
        scanf("%s", s->name);
        printf("Matric Number: ");
        scanf("%d", &s->roll_number);
        printf("Age: ");
        scanf("%d", &s->age);
        printf("GPA: ");
        scanf("%f", &s->GPA);
        printf("Student  details updated successfully !\n");
    }
}

void deleteStudent(struct Student *s, int roll_number){
    printf("Enter the matric number of the student to delete: ");
    scanf("%d", &roll_number);
    if(s->roll_number == roll_number){
        printf("Student record deleted successfully! \n");
        for(int i = 0; i < 20; i++){
            s->name[i] = '\0';
        }
        s->roll_number = 0;
        s->age = 0;
        s->GPA = 0.0;

    }
}


int main(){

    struct Student *s;
    s = (struct Student *)malloc(sizeof(struct Student));
    s->name[0] = '\0';
    s->roll_number = -1;
    s->age = -1;
    s->GPA = -1;

    bool flag = true;

    while(flag){
    printf("Welcome to Student Record Management System\n\n");
    printf("Menu:\n\n");
    printf("1. Add Student\n");
    printf("2. Display Students\n");
    printf("3. Search for a Student\n");
    printf("4. Update student details\n");
    printf("5. Delete a student\n");
    printf("6. Exit\n\n");

    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);



    switch(choice){
        case 1:
            addStudent(s);
            break;
        case 2:
            displayStudent(*s, validation(s));
            break;
        case 3:
            searchStudent(s, s->name);
            break;
        case 4:
            updateStudent(s, s->roll_number);
            break;
        case 5:
            deleteStudent(s, s->roll_number);
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("Invalid choice !\n");
    }
    }

    free(s);
    return 0;
}