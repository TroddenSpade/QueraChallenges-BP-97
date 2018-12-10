#include <stdio.h>

void maxRout(int m,int n,int array[n][m],int max[n][m],int direc);

int main(){
    int m ,n;
    scanf("%d%d",&n,&m);
    // n tool , m arz
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
    maxRout(m,n,a,lu,11);
    maxRout(m,n,a,rd,0);
    maxRout(m,n,a,ru,1);
    maxRout(m,n,a,ld,10);

    int max1, max2, maxi,maxj;
    int result =0;
    int max;
    for(int i=1;i<m-1;i++){// soton = x
        for(int j=1;j<n-1;j++){// satr = y
            // khat amodi
            max1 = lu[j-1][i] + rd[j+1][i] + ru[j][i+1] + ld[j][i-1];
            // khat ofoghi
            max2 = ru[j-1][i] + ld[j+1][i] + rd[j][i+1] + lu[j][i-1];

            max = max1 > max2 ? max1 : max2 ;

            if (result < max)  result = max ;

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

    for(int i=m-2;i>=0;i--){// soton = x
        for(int j=1;j<=n-1;j++){// satr = y
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

    for(int i=m-2;i>=0;i--){// soton = x
        for(int j=n-2;j>=0;j--){// satr = y
            int maxA = max[j+1][i] > max[j][i+1] ? max[j+1][i] : max[j][i+1] ;
            max[j][i] = array[j][i]+ maxA;
        }
    }


    }else if(direc == 10){// Left-Down/////////////////////////

    max[n-1][0]=array[n-1][0];
    for(int i=n-2;i>=0;i--){// y
        max[i][0] = max[i+1][0] + array[i][0];
    }
    for(int i=1;i<m;i++){// x
        max[n-1][i] = max[n-1][i-1] + array[n-1][i];
    }

    for(int i=1;i<=m-1;i++){// soton = x
        for(int j=n-2;j>=0;j--){// satr = y
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

    for(int i=1;i<=m-1;i++){// soton = x
        for(int j=1;j<=n-1;j++){// satr = y
            int maxA = max[j-1][i] > max[j][i-1] ? max[j-1][i] : max[j][i-1] ;
            max[j][i] = array[j][i]+ maxA;
        }
    }

    }
}