#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double taylor(double x)
{
    long n=1;
    double s=0,f=1,eps=1e-10;// 10 do potegi -10
    while(fabs(f)>eps)
    {
        s+=f;
        f*=-(x*x)/((n)*(n+1));
        n+=2;
    }
    return s;
}

int main()
{
    double a,b;
    printf("a = ");
    scanf("%lf",&a);
    printf("b = ");
    scanf("%lf",&b);
    if(a>b)
    {
        double tmp=a;
        a=b;
        b=tmp;
    }
    int step=-1;
    while(step<=0)
    {
        printf("step = ");
        scanf("%i",&step);
    }
    printf("\n");

    printf("       x       ");
    printf("     cos(x)    ");
    printf("     taylor(x) ");
    printf("\n");
    for(int i=0;i<49;i++){printf("-");}
    printf("\n");

    for(double i=a;i<b;i+=step)
    {
        printf("%12.10f    %12.10f    %12.10f\n",i,cos(i),taylor(i));
    }
    printf("%12.10f    %12.10f    %12.10f\n",b,cos(b),taylor(b));
}
