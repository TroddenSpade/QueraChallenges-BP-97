#include<stdio.h>
#include<math.h>

double function(double x,double a ,double b,double c,double d, double e)
{
    return a*pow(x,4) + b*pow(x,3) + c*pow(x,2) + d*x + e;
}

double dFunction (double x,double a ,double b,double c,double d)
{
    return a*4*pow(x,3) + b*3*pow(x,2) + c*2*x + d;
}

double newton(double x_0,double a ,double b,double c,double d,double e){
    double x,temp;
    double khata = 0.001;
    for (int i=1; ; i++)
    {
        temp=function(x_0,a,b,c,d,e)/dFunction(x_0,a,b,c,d);
        x=x_0-temp;
        if (fabs(temp) < khata)
        {
            return x;
        }
        x_0=x;
    }
    return 0;
}

double disLine(double x ,double y , double a , double b){
    return fabs(y - a*x - b)/a ;
}


int main()
{
    double a,b,c,d,e;
    double distance;
    double dL , dW ;
    double vL , vW;
    double x1,y1 ,x2,y2;
    double aP,bP;

    scanf("%lf%lf",&vL,&vW);
    scanf("%lf%lf",&x1,&y1);
    scanf("%lf%lf",&x2,&y2);
    scanf("%lf%lf",&aP,&bP);


    dL = disLine(x1,y1,aP,bP);
    dW = disLine(x2,y2,aP,bP);

    distance = sqrt(pow(x1-x2,2)+pow(y1-y2,2)-pow(dL+dW,2));

    vL = vL*vL;
    vW = vW*vW;
    dL = dL*dL;
    dW = dW*dW;

    a = vW - vL;
    b = (vL-vW)*2*distance;
    c = (dL+distance*distance)*vW -(dW +distance*distance)*vL;
    d = 2*distance*vL*dW;
    e = vL*dW*distance*distance;


    printf("%f",newton(distance/2 , a,b,c,d,e));






    
    return 0;
}