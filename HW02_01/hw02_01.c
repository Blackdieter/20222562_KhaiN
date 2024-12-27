#include <stdio.h>

#define MAX_DIGIT 90

void sum_array(int firstNum[MAX_DIGIT],int secondNum[MAX_DIGIT],int result[MAX_DIGIT])
{
    int temp;
    int ac = 0;
    for(int i=0;i<MAX_DIGIT;i++)
    {
        result[i]=temp;
        temp = (firstNum[i]+secondNum[i]+ac)%10;
        ac = (firstNum[i]+secondNum[i]+ac)/10;
        result[i]=temp; 
    }
}

void copy_array(int dest[MAX_DIGIT],int src[MAX_DIGIT])
{
    for(int i=0;i<MAX_DIGIT;i++)
    {
        dest[i]=src[i];
    }
}

int main()
{
    int firstNum[MAX_DIGIT] = {0};
    int secondNum[MAX_DIGIT] = {1};
    int nResult[MAX_DIGIT] = {0};
    long long n;

    printf("Nhap so nguyen n: ");
    scanf("%d",&n);

    // In 2 so dau tien
    printf("%d - %d\n",1,0);
    printf("%d - %d\n",1,1);
    
    // Tinh toan so fibonacy thu n
    for(int j=3;j<n+1;j++)
    {
        // Tinh so tiep theo
        sum_array(firstNum, secondNum, nResult);

                /* In ket qua ra man hinh */ 
        printf("%d - ",j);

        // Xoa cac con so 0 dang truoc ket qua
        int zeroCut = MAX_DIGIT;
        do
        {
            zeroCut--;
        } while (nResult[zeroCut]==0);

        // In tung ky tu cua ket qua
        for(int k=zeroCut;k>=0;k--)
        {
            printf("%d",nResult[k]);
        }
        printf("\n");

        // Chuan bi tiep vong lap 
        copy_array(firstNum,secondNum);
        copy_array(secondNum,nResult);
    }

    return 0;
}