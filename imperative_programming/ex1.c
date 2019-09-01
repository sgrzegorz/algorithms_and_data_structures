#include <stdio.h>
#include <stdlib.h>


void inic(int **t,int N)
{
    for(int y=0;y<N;y++)
    {
        for(int x=0;x<N;x++)
        {
            scanf("%i",&t[x][y]);
        }
    }
}

void print(int **t,int N)
{
    for(int y=0;y<N;y++)
    {
        for(int x=0;x<N;x++)
        {
            printf("%i ",t[x][y]);
        }
        printf("\n");
    }
}



int main()
{
    int **t;
    int N,r;
    scanf("%i %i",&N,&r);
    t=malloc(N*sizeof(int*));
    for(int i=0;i<N;i++)
    {
        t[i]=malloc(N*sizeof(int));
    }

    int **W;
    W=malloc(N*sizeof(int*));
    for(int i=0;i<N;i++)
    {
        W[i]=malloc(N*sizeof(int));
    }

    inic(t,N);

    zad2(t,W,N,r);
    printf("\n");
    print(W,N);



    return 0;
}
