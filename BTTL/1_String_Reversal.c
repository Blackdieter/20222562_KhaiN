#include <stdio.h>

int reverse_array(char inArray[], int N) {
    int i;
    char tmp[N];
    for (i = 0; i < N; i++) {
        tmp[i] = inArray[N - 1 - i];
    }
    for (i = 0; i < N; i++) {
        inArray[i] = tmp[i];
    }
    return 0;
}

int main() {
    char inputString[100];

    printf("Enter a string: ");
    scanf("%s", inputString);
    printf("Original string: %s\n", inputString);

    int length = 0;
    while (inputString[length] != '\0') {
        length++;
    }

    reverse_array(inputString, length);
    printf("Reversed string: %s\n", inputString);

    return 0;
}
