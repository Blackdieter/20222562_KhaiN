#include <stdio.h>

int main(){
    for(int i=1;i<=100;i++){
        if(i%10==3 || i/10==3){
            if (i%5==0){
                printf("FizzBuzz\n");
            } else {
                printf("Fizz\n");
            }
            continue;
        } else if (i%15 == 0){
            printf("FizzBuzz\n");
        } else if (i%5==0){
            printf("Buzz\n");
        } else if (i%3==0){
            printf("Fizz\n");
        } else {
            printf("%d\n",i);
        }
    }
    return 0;
}