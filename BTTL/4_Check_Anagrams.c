#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 100


void bubbleSort(char array[]) {
    
    int i=0, j, temp,n=0;
    while(array[i]!=0){
        n++;
        i++;
    }
    printf("\nThe unsort array is %s",array);

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (array[j] >= array[j + 1]) {
                // Swap array[j] and array[j + 1]
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    printf("\nThe sorted array is %s",array);
}

int main(){
    char firstString[MAX_LENGTH];
    char secondString[MAX_LENGTH];

    // Scan the strings, first string comes first
    scanf("%s", firstString);
    scanf("%s", secondString);

    bubbleSort(firstString);
    printf("\n");
    bubbleSort(secondString);
    printf("\n");
    printf("\nThe first string is %s, The second string is %s",firstString,secondString);
    
    if(strcmp(firstString,secondString)==0){
        printf("\nThese two are anagrams");
    } else printf("\nNo anagrams");
    return 0;
}