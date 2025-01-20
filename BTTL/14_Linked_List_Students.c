#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define teh structure for a student
typedef struct Student {
    char name [50];
    int age;
    struct Student *next;
} Student;

// Function to create a new student node 
Student* createStudent(char *name,int age){
    Student *newStudent = (Student*)malloc(sizeof(Student));
    strcpy(newStudent->name, name);
    newStudent -> age = age;
    newStudent -> next = NULL;
    return newStudent;
}

// Function to add a student to the linked list 
void addStudent(Student **head , char *name,int age){
    Student *newStudent =createStudent(name,age);
    newStudent -> next = *head;
    *head = newStudent;
    printf("Student %s added successful",name); 
}

void showAllStudents(Student *head){
    Student *temp = head; // Bảo toàn con trỏ gốc
    printf("Name\tAge\n");
    while(temp!=NULL){
        printf("%s\t%d\n",temp->name,temp->age);
        temp = temp->next;
    }
    printf("NULL\n");
}

void deleteClass(Student **class){
    Student *temp;
    while(*class!=NULL){
        temp = *class;
        *class = temp->next;
        free(temp);
    }
}

Student **findStudent(Student *class, char *name, int age){
    Student *temp = class;
    Student *studentList[20];
    int studentNum=0;
    printf("Num\tName\tAge\n");
    while(temp!=NULL){
        if(temp->name == name || temp->age == age){
            printf("%d\t%s\t%d\n",studentNum+1,temp->name,temp->age);
            studentList[studentNum++]=temp;
        }
        temp = temp->next;
    }
    return studentList;
}

int main(int agrc, char *argv[]){
    Student *class = NULL;
    char className[20];
    char studentName[20];
    int studentAge;
    int choice;

    // Add student to the class (add to the first)
    addStudent(&class,"Susan",19);
    addStudent(&class,"Alice",20);
    addStudent(&class,"Bob",20);

    printf("Hi master! which action would you like to choose: \n[1] Add new student\t[2] Show the whole class\n");
    scanf("%d",&choice);
    switch(choice){
        case 1:
            printf("Student name:"); scanf("%s",&studentName);
            printf("Student age:"); scanf("%d",&studentAge);
            addStudent(&class,studentName,studentAge);
            break;
        case 2:
            fgets(className,sizeof(className),stdin);
            char *token = strtok(className,"\n");
            showAllStudents(class);
            break;
    }   

    FILE *file;
    file = fopen(argv[1],"w");
    Student *temp = class;
    fprintf(file,"Name\tAge\n");
    while(temp!=NULL){
        fprintf(file,"%s\t%d\n",temp->name,temp->age);
        temp = temp->next;
    }
    fclose(file);
    // showAllStudents(class);
    // findStudent(class,"",20);
    deleteClass(&class);
    // showAllStudents(class);
    return 0;
}