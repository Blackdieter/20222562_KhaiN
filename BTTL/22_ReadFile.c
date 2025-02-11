#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void SearchLine(char *fileName,char *str){
    FILE *file = fopen(fileName,"r");
    int line=0;
    char buffer[256];
    while(fgets(buffer,sizeof(buffer),file)!=NULL){
        line++;
        if(strstr(buffer,str)==NULL) continue;
        buffer[strcspn(buffer,"\n")]='\0';
        printf("Line %d: %s\n",line,buffer);
    }

    fclose(file);
}

char *ReadFileLine(char *fileName,int line){
    FILE *file = fopen(fileName,"r");
    char buffer[256];
    for(int i=0;i<line;i++){
        fgets(buffer,sizeof(buffer),file);
    }
    printf("The line is %s",buffer);
    fclose(file);
    return buffer;
}

void AddStudent(char *fileName, char *name,int age){
    FILE *file = fopen(fileName,"a");
    fprintf(file,"%s\t%d\n",name,age);
    printf("Writen %s\t%d",name,age);
    fclose(file);
}
int main(int argc, char *argv[]){
    char* fileName=argv[2];
    char* str=argv[3];
    int age=atoi(argv[4]);
    if (strcmp(argv[1], "s") == 0) {
        SearchLine(fileName, str);
    } else if (strcmp(argv[1], "r") == 0) {
        ReadFileLine(fileName, atoi(str));
    } else if (strcmp(argv[1], "w") == 0) {
        AddStudent(fileName, str, age);
    } else {
        return 1;
    }

    return 0;
}