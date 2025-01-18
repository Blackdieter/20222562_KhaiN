#include <stdio.h>
int main(){
    int N,i; // The number of numbers, and the counting variable
    scanf("%d",&N);
        int listOfNum[N]; // Container

    for (i=0;i<N;i++){
        scanf("%d",&listOfNum[i]);
    }

    // Check even
    for (i=0;i<N;i++){
        if (listOfNum[i]%2==0) printf("%d ",listOfNum[i]);
    }
    return 0;
}