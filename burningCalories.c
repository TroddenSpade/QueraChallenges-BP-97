#include <stdio.h>

int maxRout(int m,int n,int array[n][m],int x,int y,int direc);

int main(){
    int m ,n;
    scanf("%d%d",&m,&n);
    // m tool , n arz
    int a[n][m];
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&a[i][j]);
        }
    }

    // Right-Down => 0 = direct
    // Right-Up => 1 = direct
    // Left-Up => 11 = direct
    // Left-Down => 10 = direct
    int max1, max2, maxi,maxj;
    int result =0;
    int max;
    for(int i=1;i<m-1;i++){// soton = x
        for(int j=1;j<n-1;j++){// satr = y
            // khat amodi
            max1 = maxRout(m,n,a,i,j-1,11) + maxRout(m,n,a,i,j+1,0) + maxRout(m,n,a,i+1,j,1) + maxRout(m,n,a,i-1,j,10);
            // khat ofoghi
            max2 = maxRout(m,n,a,i,j-1,1) + maxRout(m,n,a,i,j+1,10) + maxRout(m,n,a,i+1,j,0) + maxRout(m,n,a,i-1,j,11);

            max = max1 > max2 ? max1 : max2 ;

            if(max > result){    result = max;  maxi =i;  maxj = j;    }
        
        }
    }
    int i = maxi;
    int j = maxj;
    
    printf("%d",result);

    return 0;
}

// x , y bar Ax
int maxRout(int m,int n,int array[n][m],int x,int y,int direc){
    if (direc == 1){// Right-Up///////////////////////////////
    int sum =0;
    if (y == 0){
        for(int i=x;i<m;i++){
            sum += array[0][i];
        }
        return sum;
    }
    if(x == m-1){
        for(int i=y;i>=0;i--){
            sum += array[i][m-1];
        }
        return sum;
    }
    int max1 = maxRout(m,n,array,x,y-1,1) + array[y][x];
    int max2 = maxRout(m,n,array,x+1,y,1) + array[y][x];
    return max1 > max2 ? max1 : max2 ;

    }else if(direc == 0){// Right-Down////////////////////////
    int sum =0;
    if (y == n-1){
        for(int i=x;i<m;i++){
            sum += array[n-1][i];
        }
        return sum;
    }
    if(x == m-1){
        for(int i=y;i<n;i++){
            sum += array[i][m-1];
        }
        return sum;
    }
    int max1 = maxRout(m,n,array,x,y+1,0) + array[y][x];
    int max2 = maxRout(m,n,array,x+1,y,0) + array[y][x];
    return max1 > max2 ? max1 : max2 ;

    }else if(direc == 10){// Left-Down/////////////////////////
    int sum =0;
    if (y == n-1){
        for(int i=x;i>=0;i--){
            sum += array[n-1][i];
        }
        return sum;
    }
    if(x == 0){
        for(int i=y;i<n;i++){
            sum += array[i][0];
        }
        return sum;
    }
    int max1 = maxRout(m,n,array,x,y+1,10) + array[y][x];
    int max2 = maxRout(m,n,array,x-1,y,10) + array[y][x];
    return max1 > max2 ? max1 : max2 ;

    }else{// Left-Up//////////////////////////////////////////
    int sum =0;
    if (y == 0){
        for(int i=x;i>=0;i--){
            sum += array[0][i];
        }
        return sum;
    }
    if(x == 0){
        for(int i=y;i>=0;i--){
            sum += array[i][0];
        }
        return sum;
    }
    int max1 = maxRout(m,n,array,x,y-1,11) + array[y][x];
    int max2 = maxRout(m,n,array,x-1,y,11) + array[y][x];
    return max1 > max2 ? max1 : max2 ;
    }
}