#include <stdio.h>
#include <string.h>

void findCharacters(const char *str) {
    int freq[256] = {0}; // Mảng lưu trữ tần suất xuất hiện của các ký tự

    // Duyệt qua từng ký tự trong chuỗi và tăng tần suất tương ứng
    for (int i = 0; str[i] != '\0'; i++) {
        freq[(unsigned char)str[i]]++;
    }

    // In ra các ký tự có trong chuỗi và tần suất của chúng
    printf("Cac ky tu co trong chuoi:\n");
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            printf("'%c' xuan hien %d lan\n", i, freq[i]);
        }
    }
}

int main() {
    char str[] = "hello world";
    int stringlen;
    findCharacters(str);
    stringlen=strlen(str);

    
    return 0;
}
