#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

float taylor(float x)
{
    float s=0;
    float f=1;
    float n=0;
    float eps=1e-20;// 10 do potegi -10
    while(abs(f)>eps)
    {
        s+=f;
        if(n<7) printf("%f",f);
        f*=-1*(x*x)/(2*n+1)/(2*n+2);
        n++;
    }
    return s;
}

int main()
{
    printf("%f",taylor(2));
}
