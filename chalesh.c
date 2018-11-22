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
    double tempR , tempS;

    scanf("%lf%lf",&vL,&vW);
    scanf("%lf%lf",&r1,&s1);//bala khat
    scanf("%lf%lf",&r2,&s2);// zir khat
    scanf("%lf%lf",&a,&b);

    if(s2==a*r2+b && s1==a*r1+b){
        if(vL>vW){
            sqL1 = 0;
            sqW1 = sqrt(pow(r1-r2,2)+pow(s1-s2,2)); 
        }else{
            
            sqL1 = sqrt(pow(r1-r2,2)+pow(s1-s2,2));
            sqW1 = 0;
        }
    }else if(s2>=a*r2+b && s1> a*r1+b){//////// Hardo bala khat dar water hastan
        sqL1 = 0;
        sqW1 = sqrt(pow(r1-r2,2)+pow(s1-s2,2));
    
    }else if(s2<=a*r2+b && s1< a*r1+b){///////// Hardo zir khat dar land hastan
        sqW1 = 0;
        sqL1 = sqrt(pow(r1-r2,2)+pow(s1-s2,2));

    }else if(s2>a*r2+b && s1>=a*r1+b){//////// Hardo bala khat dar water hastan
        sqL1 = 0;
        sqW1 = sqrt(pow(r1-r2,2)+pow(s1-s2,2));
    
    }else if(s2<a*r2+b && s1<=a*r1+b){///////// Hardo zir khat dar land hastan
        sqW1 = 0;
        sqL1 = sqrt(pow(r1-r2,2)+pow(s1-s2,2));

    }else{

        x0 = (r1 + s1*a)/(a*a +1);
        x1 = (r2 + s2*a)/(a*a +1);
        
        for (int i=1 ;; i++){
            if (s1 > a*r1+b){
                tempS = s1;
                s1 = s2;
                s2 = tempS;

                tempR = r1;
                r1 = r2;
                r2 = tempR;
            }

            sqL0 =sqrt( pow(x0-r1,2) + pow(a*x0 +b-s1 ,2) );
            sqW0 =sqrt( pow(x0-r2,2) + pow(a*x0 +b-s2 ,2) );
            sqL1 =sqrt( pow(x1-r1,2) + pow(a*x1 +b-s1 ,2) );
            sqW1 =sqrt( pow(x1-r2,2) + pow(a*x1 +b-s2 ,2) );

            f0 = ((a*a +1)*x0 +a*b-a*s1-r1 )/(vL*sqL0) + ((a*a +1)*x0 +a*b-a*s2-r2)/(vW*sqW0);
            f1 = ((a*a +1)*x1 +a*b-a*s1-r1 )/(vL*sqL1) + ((a*a +1)*x1 +a*b-a*s2-r2)/(vW*sqW1);

            x2=(x0*f1-x1*f0)/(f1-f0);

            if (fabs(f1-f0) < 0.01){
                break;
            }
            x0=x1;
            x1=x2;
            
        }


    }
    printf("%f",2 *(sqL1/vL + sqW1/vW));



    
    return 0;
}