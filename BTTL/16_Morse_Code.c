// VuNhatcuong_20191722 CTTN Dieu khien tu dong k64
// lenh chay:  .\morse InputFile.txt OutputFile.txt


#include <string.h>
#include <ctype.h>
#include <stdio.h>
/**
 * @brief 
 * 
 */
const char characterSet[] = "abcdefghijklmnopqrstuvwxyz1234567890.,?:-#";
char morseCodeSymbol[][9] =
{".-" ,"-..." ,"-.-." ,"-.." ,"." ,"..-."
,"--." ,"...." ,".." ,".---" ,"-.-" ,".-.."
,"--" ,"-." ,"---" ,".--." ,"--.-" ,".-."
,"..." ,"-" ,"..-" ,"...-" ,".--" ,"-..-"
,"-.--" ,"--.." ,".----" ,"..---" ,"...--"
,"....-","....." ,"-...." ,"--..." ,"---.."
,"----." ,"-----",".-.-.-" ,"--..--","..--.."
,"---...","-....-","........"};
char input[5000][1000]; // lưu dữ liệu đầu vào, tối đa 5000 dòng, mỗi dòng tối đa 1000 kí tự
char output[5000][1000]; // lưu dữ liệu qua xử lí, tối đa 5000 dòng, mỗi dòng tối đa 1000 kí tự
int LineNumberOfFile = 0; // số dòng của file

/**
 * @brief 
 * kiểm tra xem có phải file morse( chỉ chứa '/', '.', '-', ' ')
 * 
 */
int isMorseFile() {
     char line[1000];
     for(int i = 0 ; i <  LineNumberOfFile; i ++) {
          strcpy(line,input[i]);
          for(int i = 0 ; i < strlen(line); i ++) {
               if((line[i] != '.') && (line[i] != '/') && (line[i] != '-') && (line[i] != ' ')) {
                    return 0;
               }
          }
     }
     return 1;
}

/**
 * @brief 
 * @param filename 
 * @return int 
 * đọc theo dòng từ file vào mảng input[][]
 * chuẩn hoá xâu do file đầu vào thành kí tự thường
 */
int readFile (char* filename) {
     FILE* inputFile = fopen(filename, "r");
     // thông báo lỗi nếu không đọc được
     if(inputFile == NULL) {
          printf("Error: %s could not be opened.\n",filename);
     }
     char line[1000];
     int line_count = 0;
     // đọc từng dòng
     while (fgets(line, 1000, inputFile) != NULL) {
          int len = strlen(line);
          // bỏ \n
          if(line[len - 1 ] == '\n') {
               line[len -1 ] = '\0';
          }
          // chuẩn hoá
          for(int i = 0 ; i < strlen(line); i ++ ) {
               line[i] = tolower(line[i]);
          }
          // lấy dữ liệu
          strcpy(input[line_count],line);
          line_count ++;
     }
    
     fclose(inputFile);
     return line_count;
}

/**
 * @brief 
 * chuyển mã morse thành các kí tự
 * @param morseCode : đoạn morse của 1 kí tự
 * @param index : vị trí(dòng) của morseCode trong file
 */
char morseCodeToText(char* morseCode, int index) {
     // kiểm tra morse rỗng
     if(strcmp(morseCode,"\0") == 0) return ' ';
     // duỵet lấy kí tự char tương ứng với đoạn morse
     for(int j = 0; j < 42; j ++) {
          if(strcmp(morseCode,morseCodeSymbol[j]) == 0) {
               return characterSet[j];
          }
     }
     // trả về '*' nếu không tìm được
     printf("Error: Invalid Morse code %s on line %d.\n",morseCode,  index + 1);
     return '*';
}

/**
 * @brief 
 * @param wordMorse // 1 xâu morsecode là 1 từ txt
 * @param index // vị trí(dòng) trong file
 * @param word // lấy từ đã xử lí xong
 * @return * void 
 *  tách từ thành các chứ cái (morse code)
 */
void wordSeparation(char* wordMorse, int index, char* word) {//     / -..... ..-/
     char morseCode[10]; //  xâu chứa 1 đoạn morse (1 kí tự txt)
     int j = 0; // biến ghi kí tự cho morseCode
     char str[30]; // xâu lưu 1 từ (txt)
     int k = 0;// biến ghi kí tự cho str
     for(int i = 0 ; i < strlen(wordMorse) ; i ++) {
          if(wordMorse[i] != ' ') { // tách từng chữ cái
               morseCode[j] = wordMorse[i];
               j ++;
          }
          else { // hết 1 chữ cái thì chuẩn mã morse cảu chữ cái đó thì txt
               morseCode[j ] = '\0';        
               str[k] = morseCodeToText(morseCode,index);
               j = 0;
               k ++;
          }
     }
     // lấy kí tự chuối cùng
     morseCode[j] = '\0';
     str[k] = morseCodeToText(morseCode,index);
     k ++;
     // đánh dấu kết thúc từ
     str[k] = '\0';
     strcpy(word,str);
}


/**
 * @brief 
 * chuyển kí tự mã morse sang txt, kết quả được lưu vào output[][] 
 */
void convertToText() {
     // duyệt lần lượt các dòng
     for(int i = 0 ; i < LineNumberOfFile; i ++) {
          char line [1000] = ""; // xâu kí tự chứa 1 dòng các kí tự trong file (dã xử lí)
          char wordMorse[200]; // xâu lưu 1 các từ(txt) dưới dạng morsecode đã được tách
          char word[30]; // 1 từ dạng txt
          int i_wordMorse = 0; // biến ghi dữ liệu cho wordMorse
          // duyệt các kí tự trên 1 dòng
          for (int k = 0 ; k <= strlen(input[i]); k ++) { // -.. --- .. /-.- .... .. /-- .- -.-- /--.- ..- . -. /- .... . --- /--. .. --- /- .-. --- ..
               // gặp các kí tự / \0 \n thì đánh dấu kết thúc 1 từ (thực hiện tách)
               if(input[i][k] != '/' && input[i][k] != '\0' && input[i][k] != '\n') {
                    wordMorse[i_wordMorse] = input[i][k];
                    i_wordMorse ++;
               } else {// tách từ
                    wordMorse[i_wordMorse] = '\0';
                    wordSeparation(wordMorse, i, word);
                    strcat(line,word);    
                    i_wordMorse = 0;
               }
          }
          // lấy dữ liệu vào output[]
          strcpy(output[i],line);
     }
}

/**
 * @brief 
 * chuyển kí tự chữ cái thành mã morse
 * @param c : kí tự cần chuyển
 * @param c_morse : xâu lấy dữ liệu ra (là xâu morsecode cảu 1 kí tự txt)
 * @param index : vị trí(số dòng) trong file
 */
void textToMorseCode (char c, int index, char* c_morse) {
     // duyệt tìm kí tự giống vói đầu vào
     for(int i = 0 ; i < 42; i ++) {
          if(c == characterSet[i]) {
               strcpy(c_morse, morseCodeSymbol[i]);
               return;
          }
     }
     // nếu không tìm thấy trả về xâu rỗng
     printf("Error: Unrecognised character %c on line %d.\n",c ,index + 1);
     strcpy(c_morse, "");
}

/**
 * @brief 
 * chuyển txt sang morsecode
 * dữ liệu sau xử lí được lưu voà output[][]
 * 
 */
void convertToMorseCode() {
     // duyệt lần lượt các dòng của input
     for(int i = 0 ; i < LineNumberOfFile; i ++) {
          char c_morse[10]; // mảng chứa xâu kí tự mã morse
          char line[1000] = ""; // mảng chứa dòng là xâu kí tự của 1 dòng mã morse
          // duyệT cá kí tự trên 1 dòng
          for(int j = 0 ; j < strlen(input[i]); j ++ ) {
               // nếu ' ' là hết 1 từ -> tách
               if(input[i][j] != ' ') {
                    textToMorseCode(input[i][j], i,c_morse);
                    strcat(line,c_morse);
                    strcat(line," ");
               }
               else {
                    // đánh dấu hết 1 từ
                    strcat(line,"/");
               }
          }
          // lấy dữ liệu
          strcpy(output[i],line);
     }
}

/**
 * @brief 
 * 
 * @param filename 
 * ghi dữ liệu ra file
 */
void writeFile (char* filename) {
     FILE* outputFile = fopen(filename,"r");

     // nếu file đã tồn tại
     if(outputFile != NULL) {
          printf("Warning: %s already exists. Do you wish to overwrite (y,n)? ",filename);
          fflush(stdin);
          char yesNo;
          scanf("%c", &yesNo);
          if ((yesNo == 'Y') || (yesNo == 'y')) {
               outputFile = fopen(filename,"w");              
          } else {
               return ;
          }
     }
     // nếu fiel chưua tồn tại tạo file mớ
     outputFile = fopen(filename,"w");
     // in ra file
     for (int i = 0 ; i < LineNumberOfFile ; i++) {
          fputs(output[i],outputFile);
          fputs("\n",outputFile);
     }
     fclose(outputFile);
}


int main(int argc, char* argv[])
{
     char nameFileIn[34];  // tên file input
     char nameFileOut[34]; // lưu tên file ra
     strcpy(nameFileIn, argv[1]);
     strcpy(nameFileOut, argv[2]);
     // nhap lenh
     LineNumberOfFile = readFile(nameFileIn);
     if(LineNumberOfFile == 0) return 0;

     // xử lí
     if(isMorseFile()) {  // check morse
          convertToText();
     }else {
          convertToMorseCode();
     }  
     // ghi ra file output
     writeFile(nameFileOut);
    
     return 0;
}


// lenh chay:  .\morse InputFile.txt OutputFile.txt
