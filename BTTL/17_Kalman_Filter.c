#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Kalman Filter structure
typedef struct {
    float Q; // Nhiễu quá trình
    float R; // Nhiễu đo 
    float x; // Giá trị trạng thái
    float P; // Sai số dự đoán
    float K; // Hệ số Kalman 
} KalmanFilter;

// Hàm khởi tạo bộ lọc Kalman
void Kalman_Init(KalmanFilter *kf,float process_noise,float measurement_noise, float initial_estimate, float initial_error){
    kf->Q = process_noise;
    kf->R = measurement_noise;
    kf->x = initial_estimate;
    kf->P = initial_error;
    kf->K = 0;
}

// Hàm cập nhật bộ lọc Kalman
float Kalman_Update(KalmanFilter *kf, float measurement){
    // Dự đoán
    kf->P += kf->Q;
    
    // Tính toán hệ số Kalman
    kf->K = kf->P/(kf->P +kf->R);

    // Cập nhật trạng thái
    kf->x = kf->x + kf->K*(measurement - kf->x);

    // Cập nhật sai số dự đoán 
    kf->P = (1-kf->K)*kf->P;

    return kf->x;
}

int main(int argc,char *argv[]){
    FILE *inputFile = fopen(argv[1],"r");
    if (inputFile == NULL){
        perror("Can not open input file");
    }

    // Đọc dữ liệu từ file 
    char timeLine[1024];
    char valueLine[1024];

    if(fgets(timeLine,sizeof(timeLine),inputFile)==NULL || fgets(valueLine,sizeof(valueLine),inputFile)==NULL){
        perror("Reading input error");    // Hàm fgets sẽ đọc đến khi có dấu xuống dòng 
        fclose(inputFile);
        return 1;
    }

    fclose(inputFile);
    
    //  Chuyển đổi chuỗi thành mảng số
    // Tạo mảng lưu trữ giá trị thời gian và cảm biến
    float times[1024],values[1024];
    int timeCount=0,valueCount=0;

    // Tách chuỗi cách nhau bởi ký tự " "
    char *token = strtok(timeLine," ");
    while (token != NULL){
        times[timeCount++]=atof(token); // append token vào times[timeCount] sau đó tăng timeCount lên 1
        token = strtok(NULL," ");
    }

    token = strtok(valueLine," ");
    while (token != NULL){
        values[valueCount++]=atof(token);   // a to float  while (token != NULL){
        token = strtok(NULL," ");
    }

    if (timeCount != valueCount) {
        fprintf(stderr, "Times and Values count does not match\n");
        return 1;
    }
    printf("\n Reading times and values:");
    for(int i=0;i<timeCount;i++){
        printf("\n%.2f\t%.2f",times[i],values[i]);
    }

    KalmanFilter kf;
    Kalman_Init(&kf,0.01,0.1,0,1);

    // Dữ liệu đo (example)
    // float measurements[] = {1.0, 2.0, 1.5, 2.5, 3.0, 2.8, 3.2};
    // int num_measurements = sizeof(measurements) / sizeof(measurements[0]);

    // Mở file đầu ra 
    FILE *outputFile = fopen(argv[2],"w");
    if (outputFile == NULL){
        perror("Không thể tạo/ mở file");
        return 1;
    }

    // Ghi tiêu đề vào file đầu ra
    fprintf(outputFile,"Times\tMeasurement\tEstimate\n");


    // Cập nhật bộ lọc Kalman với từng phép đo
    for (int i = 0; i < timeCount; i++) {
        float estimate = Kalman_Update(&kf, values[i]);
        fprintf(outputFile, "%.2f\t%.2f\t%.2f\n",times[i],values[i],estimate);
    }
    fclose(outputFile);

    printf("\nDone converting");
    return 0;
}