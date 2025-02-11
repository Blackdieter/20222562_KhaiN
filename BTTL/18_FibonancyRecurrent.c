#include <stdio.h>
#include <stdlib.h>
long fibonacy(int n){
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    return fibonacy(n-1)+fibonacy(n-2);
}

int main(int argc, char *argv[]){
    printf("The fibonacy number %d is %ld",atoi(argv[1]),fibonacy(atoi(argv[1])));
    return 0;
}