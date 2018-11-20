#include<stdio.h>
#include<math.h>

int main()
{
    
    double vL , vW;
    double r1,s1 ,r2,s2;
    double a,b;
    double x1,x0,x2;
    double sqL0 , sqW0 ,sqL1 ,sqW1;
    double f0,f1;
    double result;

    scanf("%lf%lf",&vL,&vW);
    scanf("%lf%lf",&r1,&s1);
    scanf("%lf%lf",&r2,&s2);
    scanf("%lf%lf",&a,&b);

    x0 = r1;
    x1 = r2;
    
    
    for (int i=1; i <=40 ; i++)
    {
        sqL0 =sqrt( pow(x0-r1,2) + pow(a*x0 +b-s1 ,2) );
        sqW0 =sqrt( pow(x0-r2,2) + pow(a*x0 +b-s2 ,2) );
        sqL1 =sqrt( pow(x1-r1,2) + pow(a*x1 +b-s1 ,2) );
        sqW1 =sqrt( pow(x1-r2,2) + pow(a*x1 +b-s2 ,2) );
        
        

        f0 = ((a*a +1)*x0 +a*b-a*s1-r1 )/(vL*sqL0) + ((a*a +1)*x0 +a*b-a*s2-r2)/(vW*sqW0);
        f1 = ((a*a +1)*x1 +a*b-a*s1-r1 )/(vL*sqL1) + ((a*a +1)*x1 +a*b-a*s2-r2)/(vW*sqW1);
    

        x2=(x0*f1-x1*f0)/(f1-f0);
        if (f1-f0 == 0){
            break;
        }
        x0=x1;
        x1=x2;
        
    }

    printf("%f\n",sqL1/vL + sqW1/vW);



    
    return 0;
}