/*
Nguyen Khai
***** Viet chuong trinh doc du lieu tu file theo format sau
Time Temperature Humidity
1 25 75
2 26 76
...
a) Tao mot struct luu du lieu moi dong voi ten "DHT11" 
    va in ra man hinh những khoảng thời gian nhiệt độ lớn hơn 35 (Nhiệt độ cao)

b) Giả sử file được ghi liên tục bởi sensor thực, viết chương trình đọc liên tục
    nhiệt độ và độ ẩm của 3 giá trị gần nhất và in ra màn hình trung bình cộng giá trị này

c) Giả sử độ ẩm biến thiên tuyến tính theo nhiệt độ, hãy viết phương trình hồi quy
    tuyến tính với learning rate 0.1, epoch = 10, tính độ ẩm khi nhiệt độ = 30
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEARNING_RATE 0.1
#define EPOCHS 10

typedef struct{
    int time[256];
    int temp[256];
    int hum[256];
    int size;
}  DHT11;

typedef struct{
    float a;
    float b;
} LinearRegression;
// Read the value of sensor to object DHT11
int ReadValue(char *fileName, int *time,int*temp,int*hum){
    FILE *file = fopen(fileName,"r");
    char buffer[256];
    int index=0; // Count for each times sensor read

    while(fgets(buffer,sizeof(buffer),file)!=NULL){
        char *token = strtok(buffer," ");
        int i=0;
        while(token!=NULL && i<3){
            if(i==0){
                time[index]=atoi(token);
            }    
            else if(i==1){
                temp[index]=atoi(token);
            }   
            else if(i==2){
                hum[index]=atoi(token);
            }
            i++;
            token=strtok(NULL," ");
        }
        index++;
    }

    printf("Reading completed!\nThe last line is: \n%d %d %d\n",time[index-1],hum[index-1],temp[index-1]);
    fclose(file);
    return index;
}

int FindValueGreater(DHT11 dht11,char *unit,int value){
    if(unit=="temp"){
        for (int i = 0; i < dht11.size; i++)
        {
            if(dht11.temp[i]>value){
                printf("At time %d the %s is %d greater than %d\n",dht11.time[i],unit,dht11.temp[i],value);
            }
        }
        
    } else if(unit=="hum"){
        for (int i = 0; i < dht11.size; i++)
        {
            if(dht11.hum[i]>value){
                printf("At time %d the %s is %d greater than %d\n",dht11.time[i],unit,dht11.hum[i],value);
            }
        }
    } else return 1;
    return 0;
}
float MeanSquareError(int *x,int *y,int n, LinearRegression lr){
    float error=0;
    printf("The a and b is: %f %f\n",lr.a,lr.b);
    for(int i=0;i<n;i++){
         error = error + (lr.a*x[i]+lr.b-y[i])*(lr.a*x[i]+lr.b-y[i])/n;
         printf("%f\n",(lr.a*x[i]+lr.b-y[i])*(lr.a*x[i]+lr.b-y[i])/n);
         printf("error is: %.2f\n",error);
    }
   return error;
}
float GradientDecent(int epoch, float *x,float *y,int n,LinearRegression *lr){

}
int main(int agrc,char *argv[]){
    DHT11 dht11;
    LinearRegression lr;
    lr.a=atof(argv[2]);
    lr.b=atof(argv[3]);
    dht11.size = ReadValue(argv[1],dht11.time,dht11.temp,dht11.hum);
    if(FindValueGreater(dht11,"temp",26)){
        printf("Can't find the unit suitable\n");
    }
    printf("The MSE of the data is: %.2f\n",MeanSquareError(dht11.temp,dht11.hum,dht11.size,lr));
    return 0;
}

