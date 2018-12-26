#include <stdio.h>
#include <math.h>

int pemr(int n,int length);
int main(){
    int n;
    scanf("%d",&n);
    int arr1[n],arr2[n],arr1p[2*n-2],arr2p[n-1];
    int num1 = 0;
    int num2 = 0;

    for(int i=0;i<n;i++){
        scanf("%d",&arr1[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&arr2[i]);
    }
    int j=0;
    for(int i=0;i<n;i++){
        if(arr1[i]==0)  continue;
        else{
            arr1p[j]=arr1[i];
            j++;
        }
        
    }
    j=n-1;
    for(int i=n;i<2*n;i++){
        if(arr1[i-n]==0)  continue;
        else{
            arr1p[j]=arr1[i-n];
            j++;
        }
        
    }
    j=0;
    for(int i=0;i<n;i++){
        if(arr2[i]==0)  continue;
        else{
            arr2p[j]=arr2[i];
            j++;
        }
        
    }

    
    for(int i=0;i<n;i++){
        int count=0;
        for(int j=0;j<n-1;j++){
            if(arr1p[i+j]!=arr2p[j]) break;
            count ++;
        }
        if(count == n-1){
            printf("YES");
            return 0;
        }
    }

    printf("NO");
    return 0;
}
