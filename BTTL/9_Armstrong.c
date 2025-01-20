#include <stdio.h>
#include <stdlib.h>

int main(){
    char charNum[100];
    int num;
    long int sumCubes=0;
    int i=0;                    // Counting variable
    printf("Nhap 1 so: ");
    scanf("%s",charNum);

    printf("The sum cube is:");
    num = atoi(charNum);
    while(charNum[i]!='\0'){
        sumCubes+=((int)charNum[i]-'0')*((int)charNum[i]-'0')*((int)charNum[i]-'0');
        i++;
        printf("%ld ",sumCubes);
    }

    if(sumCubes==num){
        printf("\nSo do la so Amstrong");
    } else {
        printf("Khong phai so Amstrong");
    }
    return 0;
}