// Online C compiler to run C program online
#include <stdio.h>
int a[10][10];

int dequy(int dong, int cot)
{
    if(cot==0) return 1;
    if(cot==dong) return 1;
    return dequy(dong-1,cot)+dequy(dong-1,cot-1);
}
int main() {
    a[0][0]=1;
    a[1][0]=1;
    a[1][1]=1;
    int n; 
    scanf("%d",&n);
    for(int i =2;i<n+1;i++)
        for(int j=0;j<=i;j++)
            a[i][j]=dequy(i,j); 
    for(int i =2;i<11;i++){
        for(int j=0;j<=i;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
    return 0;
}