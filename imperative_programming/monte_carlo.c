#include <stdio.h>
#include <conio.h>
#include <math.h>
#define RAND_MAX
#include <time.h>
#include <stdlib.h>

float MonteCarlo(float a, float b, long long int N )
{
    srand(time(NULL));
    float positive = 0;// number of points (x,y): 0<y<sinx
    float negative = 0;// number of points (x,y): sinx<y<0
    int i;
    for(i=0;i<N;i++)
    {
        float x= ((float) rand()) / (float) RAND_MAX*(b-a)+a;
        float y= ((float) rand()) / (float) RAND_MAX*2 -1 ;
        if( sin(x)>0 && y<sin(x) ) positive++;
        if( sin(x)<0 && y>sin(x) ) negative++;
        //printf("%f %f\n",x,y);
    }

    positive=fabs(a-b)*2*(positive/ (float) N);//positive area
    negative=fabs(a-b)*2*(negative/ (float) N);//negative area

    return (float) positive-negative;
}

int main()
{
    //printf("%f", sin(3.4));
    printf("%f",MonteCarlo(108,110,9087888));

}
