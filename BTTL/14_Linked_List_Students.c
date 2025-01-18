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
void addStudent(Student **head, char *name,int age){
    Student *newStudent =createStudent(name,age);
    newStudent -> next = *head;
    *head = newStudent 
}