#include <stdio.h>
#include <stdlib.h>


int f(int t[],const int N)
{
    int j;
    int flaga=0;
    for(j=0;j<N;j++)
    {
        if(t[j]>=0) flaga=1;
    }
    int SUMA=t[0];
    int p,k,i;
    for(p=0;p<N;p++)
    {
        for(k=p;k<N;k++)
        {
            int suma=0;
            for(i=p;i<=k;i++)
            {
                suma+=t[i];
            }
            if(suma>SUMA) SUMA=suma;
        }
    }
    if(flaga) return SUMA;
    return 0;
}


int main()
{
int t[]={1,4,5,-32,-1,0,999,-19,44,2};
printf("%d",f(t,10));

}
