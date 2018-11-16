#include <stdio.h>

int main(){
    int p , r;
    double dor , sum ,result ;
    double giah1 , giah2 , giah3 , giah4 , giah5 ;
    double nerkh1 , nerkh2 , nerkh3 , nerkh4 , nerkh5;
    double tala1S,tala2S,tala3S,tala4S,tala5S;
    scanf("%d%d",&p,&r);
    scanf("%lf%lf",&giah1,&nerkh1);
    scanf("%lf%lf",&giah2,&nerkh2);
    scanf("%lf%lf",&giah3,&nerkh3);
    scanf("%lf%lf",&giah4,&nerkh4);
    scanf("%lf%lf",&giah5,&nerkh5);

    dor = (p+r)/(double)60 ;
    sum = (giah1 * nerkh1 + giah2 * nerkh2 + giah3 * nerkh3 + giah4 * nerkh4 + giah5 * nerkh5)* p ;
    
    result = sum / dor ;

    printf("%f",result);


    return 0;
}