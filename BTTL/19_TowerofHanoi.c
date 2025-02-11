#include <stdio.h>
#include <stdlib.h>

void TowerOfHanoi(int n,char* fromRod,char *auRod,char *toRod){
    if(n==1){
        printf("Move plate %d from %s to %s\n",n,fromRod,toRod);
        return;
    }
    TowerOfHanoi(n-1,fromRod,toRod,auRod);
    printf("Move plate %d from %s to %s\n",n,fromRod,toRod);
    TowerOfHanoi(n-1,auRod,fromRod,toRod);
}

int main(int argc, char *argv[]){
    TowerOfHanoi(atoi(argv[1]),argv[2],argv[3],argv[4]);
    return 0;
}