#include <stdio.h>

// lD got some problems !!
// and LU cant do the sum !!




void maxRout(int m,int n,int array[n][m],int max[n][m],int direc);

int main(){
    int m ,n;
    scanf("%d%d",&m,&n);
    // m tool , n arz
    int a[n][m];

    // Right-Down => 0 = direct
    // Right-Up => 1 = direct
    // Left-Up => 11 = direct
    // Left-Down => 10 = direct
    int rd[n][m];
    int ru[n][m];
    int lu[n][m];
    int ld[n][m];
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&a[i][j]);
        }
    }

    // Right-Down => 0 = direct
    // Right-Up => 1 = direct
    // Left-Up => 11 = direct
    // Left-Down => 10 = direct
    maxRout(m,n,a,lu,11);
    maxRout(m,n,a,rd,0);
    maxRout(m,n,a,ru,1);
    maxRout(m,n,a,ld,10);


    puts("");
    puts("LU");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%d ",lu[i][j]);
        }
        puts("");
    }
    puts("LD");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%d ",ld[i][j]);
        }
        puts("");
    }
    puts("RU");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%d ",ru[i][j]);
        }
        puts("");
    }
    puts("RD");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%d ",rd[i][j]);
        }
        puts("");
    }





    int max1, max2, maxi,maxj;
    int result =0;
    int max;
    for(int i=1;i<m-1;i++){// soton = x
        for(int j=1;j<n-1;j++){// satr = y
            // khat amodi
            max1 = lu[i][j-1] + rd[i][j+1] + ru[i+1][j] + ld[i-1][j];
            // khat ofoghi
            max1 = ru[i][j-1] + ld[i][j+1] + rd[i+1][j] + lu[i-1][j];

            max = max1 > max2 ? max1 : max2 ;

            if ( result < max)  result = max ;

        }
    }
    
    printf("%d",result);

    return 0;
}

// x , y bar Ax
void maxRout(int m,int n,int array[n][m],int max[n][m],int direc){
    if (direc == 1){// Right-Up///////////////////////////////
    for(int i=0;i<n;i++){
        if(i == 0)  max[i][m-1]=array[i][m-1];
        else    max[i][m-1] = max[i-1][m-1]+array[i][m-1];
    }
    for(int i=m-1;i>=0;i--){
        if(i == m-1)  max[0][i]=array[0][i];
        else    max[0][i] = max[0][i+1]+array[0][i];
    }

    for(int i=m-2;i>0;i--){// soton = x
        for(int j=1;j<n-1;j++){// satr = y
            int maxA = max[j-1][i] > max[j][i+1] ? max[j-1][i] : max[j][i+1] ;
            max[j][i] = array[j][i]+ maxA;
        }
    }


    }else if(direc == 0){// Right-Down////////////////////////
    for(int i=n-1;i>=0;i--){// y
        if(i == n-1)  max[i][m-1]=array[i][m-1];
        else    max[i][m-1] = max[i+1][m-1]+array[i][m-1];
    }
    for(int i=m-1;i>=0;i--){// x
        if(i == m-1)  max[n-1][i]=array[n-1][i];
        else    max[n-1][i] = max[n-1][i+1]+array[n-1][i];
    }

    for(int i=m-2;i>0;i--){// soton = x
        for(int j=n-2;j>0;j--){// satr = y
            int maxA = max[j+1][i] > max[j][i+1] ? max[j+1][i] : max[j][i+1] ;
            max[j][i] = array[j][i]+ maxA;
        }
    }


    }else if(direc == 10){// Left-Down/////////////////////////
    for(int i=n-1;i>=0;i--){// y
        if(i == n-1)  max[i][0]=array[i][0];
        else    max[i][0] = max[i+1][0] + array[i][0];
    }
    for(int i=0;i<m;i++){// x
        if(i == 0)  max[n-1][i]=array[n-1][i];
        else    max[n-1][i] = max[n-1][i-1] + array[n-1][i];
    }

    for(int i=1;i<m-1;i++){// soton = x
        for(int j=n-1;j>0;j--){// satr = y
            int maxA = max[j+1][i] > max[j][i-1] ? max[j+1][i] : max[j][i-1] ;
            max[j][i] = array[j][i]+ maxA;
        }
    }

    }else{// Left-Up//////////////////////////////////////////
    for(int i=0;i<n;i++){ // y
        if(i == 0)  max[i][0]=array[i][0];
        else    max[i][0] = max[i-1][0]+array[i][0];
    }
    for(int i=0;i<m;i++){// x
        if(i == 0)  max[0][i]=array[0][i];
        else    max[0][i] = max[0][i-1]+array[0][i];
    }

    for(int i=1;i<m-1;i++){// soton = x
        for(int j=1;j<n-1;j++){// satr = y
            int maxA = max[j-1][i] > max[j][i-1] ? max[j-1][i] : max[j][i-1] ;
            max[j][i] = array[j][i]+ maxA;
        }
    }

    }
}