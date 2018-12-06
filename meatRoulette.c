#include <stdio.h>

int abs(int);

int main(){
    int n;
    scanf("%d",&n);
    int roullet[n];
    int arr[n];
    int steps =0;
    
    for(int i=0;i<n;i++){
        scanf("%d",&roullet[i]);
        arr[i]=roullet[i];
    }

    ////////////////////////////////////////////////////////////
    int count=-1;
    for(int i=0;i<n;i++){
        if(arr[i]<0){
            continue ;
        }else{
            int num =i;
            while(1){
                arr[num]=count;
                steps += abs(num - roullet[num]);
                num = roullet[num];

                if(num == i) break;
            }
        }
        count --;
    }
    count = -count -2;

    //Err??//
    int num = arr[0];
    int antiCount =0;
    int counter = 0;
    for(int i=0;i<n;i++){
        
        if(arr[i]<num){
            num = arr[i];
            counter ++;
        }
        if(arr[i]>num){
            antiCount+=counter;
            counter =0;
        }  
    }

    int extraCount =0;
    for(int i=n-1;i>0;i--){
        if(roullet[i]==i){
            extraCount++;
        }else{
            break;
        }
        
    }

    steps -= 2*extraCount;
    
    steps +=2*(count-antiCount);
    
    // for(int i=0;i<n;i++){
        
    //     printf("%d",arr[i]);
    // }
    printf("%d",steps);
    return 0;

}

int abs(int n){
    if(n >=0)   return n;
    else    return -n;
}