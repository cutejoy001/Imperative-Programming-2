    /**
     * Instructions: 
1. Define a structure named Student that contains the following information about each student: name, roll 
number, age, and GPA. 
2. Implement  a  function  called  addStudent  that  allows  users  to  add  a  new  student  to  the  record.  This 
function  should  dynamically  allocate  memory  for  the  new  student  and  prompt  the  user  to  enter  the 
student's details. Store the information in the dynamically allocated memory. 
3. Implement a function called displayStudents that displays the information of all students in the record. 
This function should iterate over the dynamically allocated memory and print the details of each student. 
4. Implement  a  function  called  searchStudent  that  allows  users  to  search  for  a  student  by  name.  This 
function  should  prompt  the  user  to  enter  the  name  of  the  student  and  then  search  the  dynamically 
allocated memory  to  find  a  match.  If  found,  display  the student's details; otherwise,  display a message 
indicating that the student was not found. 
5. Implement  a  function  called  updateStudent  that  allows  users  to  update  a  student's  information.  This 
function  should  prompt  the  user  to  enter  the  roll number  of  the  student  to  be  updated.  It  should  then 
search for the student in the dynamically allocated memory and allow the user to update the student's 
details if found. 
6. Implement a function called deleteStudent that allows users to delete a student's  record. This function 
should prompt the user to enter the roll number of the student to be deleted. It should then search for 
the student in the dynamically allocated memory, free the memory occupied by the student's record, and 
remove the student from the record. 
7. In  the  main  function,  provide  a  menu-driven  interface  that  allows  users  to  select  various  operations, 
including adding a student, displaying all students, searching for a student, updating a student's details, 
deleting a student's record, and exiting the program. 
8. Handle appropriate error cases, such as invalid user inputs.
    */


#include<stdio.h>
struct Student{
    char name[20];
    int roll_number;
    int age;
    float GPA;
};

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
    printf("Student added successfully !\n")
}

void displayStudent(struct Student s){
    printf("Student Record:\n");
    printf("Name: %s\n", s.name);
    printf("Matric Number: %d\n", s.roll_number);
    printf("Age: %d\n", s.age);
    printf("GPA: %f\n", s.GPA);
}

void searchStudent(struct Student *s, int roll_number){
    printf("Enter the name of the student to search: ");
    char search_name[20];
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
    int roll_number;
    printf("Enter the matric number of the student to update: ");
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
    int roll_number;
    printf("Enter the matric number of the student to delete: ");
    if(s->roll_number == roll_number){
        printf("Student record deleted successfully! \n");
        s->roll_number = -1;
    }
}


int main(){

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

    struct Student *s;
    s = (struct Student *)malloc(sizeof(struct Student));

    switch(choice){
        case 1:
            addStudent(s);
            break;
        case 2:
            displayStudent(*s);
            break;
        case 3:
            searchStudent(s, s->roll_number);
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

    return 0;
}