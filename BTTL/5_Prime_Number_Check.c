#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int PrimeCheck(int num){
    if(num==0 || num==1){
        return 0;
    }

    for (int p=2;p<=num/2;p++){
        if(num%p==0) return 0;
    } // Neu p co nghiem khac 1 va chinh no thi no la prime number
    return 1;
}

int main(int argc, char *argv[]){
    // Convert char to number
    long listNum[1024];
    for(int i=1; i<argc;i++){
        listNum[i-1]=atol(argv[i]);
    }
    // The numbers to check
    printf("The numbers inputed:\n");
    for(int i=0; i<argc-1; i++){
        printf("%d\t%d\n",listNum[i],PrimeCheck(listNum[i]));
    }

    return 0;
}