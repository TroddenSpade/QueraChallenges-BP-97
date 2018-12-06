#include <stdio.h>
#include <math.h>

int func(int);
int tedad(int,int);

int main(){
    int min , max , n;
    scanf("%d%d%d",&min,&max,&n);

    printf("%d",tedad(max,n)-tedad(min,n));
    
    return 0;
}

int func(int k){
    if (k == 0)
        return 0 ;
    else
        return 9*func(k-1) + pow(10,k-1);
}

int tedad(int m,int n){
    int count =0 ;
    int digit,temp , power , function;
    int result = 0;
    temp = m;
    while(temp>0){
        digit = temp%10;
        power = ceil(pow(10,count));
        function = func(count);
        if (digit > n){
            result = result + (digit-1)*function + power;

        }else if (digit < n){
            result = result + digit*function;

        }else{
            result = m%power + 1 + digit*function ;
        }

        temp=temp/10;
        count ++;
    }
    return result ;
}