#include <stdio.h>
#include <stdlib.h>

void zad2()
{
    const int N;
    scanf("%d",&N);
    int t1[N];

    int i;
    for(i=0;i<N;i++)
    {
        t1[i]=(rand()%57)+55;
    }

    int t2[(N+1)/2];
    int nr=0;
    for(i=0;i<(N+1)/2;i++)
    {
        if(nr==N-1)
        {
            t2[i]=t1[nr];
            break;
        }
        t2[i]=(t1[nr]+t1[nr+1])/2;
        nr+=2;
        if(nr>N) break;
    }
    printf("t1[]=");
    for(i=0;i<N;i++)
    {
        printf(" %d ",t1[i]);
    }
    printf("\nt2[]=");
    for(i=0;i<(N+1)/2;i++)
    {
        printf(" %d ",t2[i]);
    }
}

int main()
{
    zad2();




}
