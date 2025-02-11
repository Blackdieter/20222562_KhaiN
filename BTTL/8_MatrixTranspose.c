#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int cols=0,rows=0;
    char stringMatrix[2048]; // Contain the inpput 
    float matrix[10][10]; // Ma tran 2 chieu
    char *rowMatrix[3]; // Contain the pointers to the rows
    // String input of a matrix
    printf("Nhap ma tran: ");
    fgets(stringMatrix,sizeof(stringMatrix),stdin);
    stringMatrix[strcspn(stringMatrix,"\n")]='\0';
    printf("The matrix string is: %s\n",stringMatrix);

    // Extract the rows of a matrix
    char *token = strtok(stringMatrix,";,");
    while (token!=NULL){
        rowMatrix[rows]=token;
        rows++;
        token = strtok(NULL,";,");
    }
    // Extract the celss of a matrix
    for(int i=0;i<rows;i++){
        cols = 0;
        char *cellToken=strtok(rowMatrix[i]," ");
        while(cellToken!=0){
            matrix[i][cols]=atof(cellToken);
            printf("%.2f\t",matrix[i][cols]);
            cellToken=strtok(NULL," ");
            cols++;
        }
        printf("\n");
    }

    // In ra ma tran nghich dao
    printf("The inversed of %d x %d  matrix is: \n",rows,cols);
    for(int i=0;i<cols;i++){
        for(int j=0;j<rows;j++){
            printf("%.2f\t",matrix[j][i]);
        }
        printf("\n");
    }

    return 0;
}