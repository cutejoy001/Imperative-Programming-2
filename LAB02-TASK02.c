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
    printf("Enter name: ");
    scanf("%s", s->name);
    printf("Enter roll number: ");
    scanf("%d", &s->roll_number);
    printf("Enter age: ");
    scanf("%d", &s->age);
    printf("Enter GPA: ");
    scanf("%f", &s->GPA);
}

void displayStudent(struct Student s){
    printf("Name: %s\n", s.name);
    printf("Roll number: %d\n", s.roll_number);
    printf("Age: %d\n", s.age);
    printf("GPA: %f\n", s.GPA);
}

void searchStudent(struct Student *s, int roll_number){
    if(s->roll_number == roll_number){
        displayStudent(*s);
    }
}

void deleteStudent(struct Student *s, int roll_number){
    if(s->roll_number == roll_number){
        s->roll_number = -1;
    }
}


int main(){

    struct Student *s;
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);
    s = (struct Student *)malloc(n * sizeof(struct Student));
    for(int i = 0; i < n; i++){
        addStudent(&s[i]);
    }
    for(int i = 0; i < n; i++){
        displayStudent(s[i]);
    }
    int roll_number;
    printf("Enter roll number to search: ");
    scanf("%d", &roll_number);
    for(int i = 0; i < n; i++){
        searchStudent(&s[i], roll_number);
    }
    printf("Enter roll number to delete: ");
    scanf("%d", &roll_number);
    for(int i = 0; i < n; i++){
        deleteStudent(&s[i], roll_number);
    }
    for(int i = 0; i < n; i++){
        displayStudent(s[i]);
    }
    
    return 0;
}