#include <stdio.h>

int row(int n,int a[n][n],int x);
int column(int n ,int a[n][n],int x);

int main(){
    int n;
    scanf("%d",&n);
    int a[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }

    int result =-1;
    for(int i=0;i<n;i++){
        if(row(n,a,i)==1&&column(n,a,i)==1) result=i;
    }
    

    if(result == -1)  printf("%d",-1);
    else    printf("%d",result);

    return 0;
}

int row(int n,int a[n][n],int x){ //0
    for(int i=0;i<n;i++){
        if(a[x][i] != 0)    return 0;
    }
    return 1;
}

int column(int n,int a[n][n],int x){ // 1
    for(int i=0;i<n;i++){
        if(a[i][x]!=1 && i!=x)    return 0;
    }
    return 1;
}