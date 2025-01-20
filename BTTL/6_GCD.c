#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long GCD(long a, long b){
    if(b>=a){
        long temp = b;
        b=a;
        a= temp;
    }
    long thuong,du;
    while (a%b != 0){
        du = a%b;
        a=b;
        b=du;
    }
    return b;
}
int main(int argc, char *argv[]){
    long a=atol(argv[1]);
    long b=atol(argv[2]);
    printf("The GCD is: %ld",GCD(a,b));
}
