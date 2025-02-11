#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    char *name;
    long long phoneNum;
    Student *next;
    Student *prev;
} Student;

Student *CreateStudent(char *name,int phoneNum){
    Student *newStudent=(Student *)malloc(newStudent,sizeof(Student));
    newStudent->name=name;
    newStudent->phoneNum=phoneNum;
    newStudent->next=NULL;
    newStudent->prev=NULL;
    return newStudent;
}

void AddStudent(Student **head,Student **tail,char*name,int phoneNum){
    *head
    *head=CreateStudent(char *name,int phoneNum);

}
int main(){
    char input[256];
    char day[20];
    int h,min,sec;
    fgets(input,sizeof(input),stdin);
    // input[strstr(input,"\n")]="\0";
    sscanf(input,"%s %d %d %d",&day,&h,&min,&sec);
    printf("Today is %s %dh%dm%ds",day,h,min,sec);
    return 0;
}