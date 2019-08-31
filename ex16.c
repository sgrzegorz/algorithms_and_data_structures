#include <stdio.h>
#include <stdlib.h>

void print(int **t,int X,int Y)
{
    printf("\n");
    for(int y=0;y<Y;y++)
    {
        for(int x=0;x<X;x++)
        {
            printf("%i ",t[x][y]);
        }
        printf("\n");
    }
}

void wypelnij(int **t,int X,int Y)
{
    for(int y=0;y<Y;y++)
    {
        for(int x=0;x<X;x++)
        {
            scanf("%i",&t[x][y]);
        }
    }
}

void f(int **T,int **P,int N,int X, int Y)
{
    int suma=0;
    for(int y=0;y<Y;y++)
    {
        for(int x=0;x<X;x++)
        {
            if(P[x][y]==1) suma+=T[x][y];
        }
    }

    for(int y=0;y<N;y++)
    {
        for(int x=0;x<N;x++)
        {
            int s=0;
            if(y+Y-1<N && x+X-1<N)
            {
                for(int y1=0;y1<Y;y1++)
                {
                    for(int x1=0;x1<X;x1++)
                    {
                        if(P[x1][y1]==1)
                        {
                            s+= T[x+x1][y+y1];
                        }
                    }
                }

            }
            if(s>suma) suma=s;

        }
    }
    printf("%i",suma);
}


int main()
{
    int **P,**T;
    int k,l,N;
    while(k>N || l>N)
    {
         printf("wprowadz N,k,l:\n");
         scanf("%i %i %i",&N,&k,&l);
    }

    P=malloc(l*sizeof(int*));
    for(int i=0;i<l;i++)
    {
        P[i]=malloc(l*sizeof(int));
    }


    T=malloc(N*sizeof(int*));
    for(int i=0;i<N;i++)
    {
        T[i]=malloc(N*sizeof(int));
    }

    /*
    for(int i=0;i<l;i++)
    {
        for(int j=0;j<k;j++)
        {
            P[i][j]=rand()%2;
        }
    }
    print(P,l,k);// (P,ilosc kolumn, ilosc wierszy)


    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            T[i][j]=rand();
        }

    }
    */
    printf("Wprowadz obie tablice: \n");
    wypelnij(T,N,N);
    wypelnij(P,l,k);

    //print(T,N,N);
    //print(P,l,k);// (P,ilosc kolumn, ilosc wierszy)
    printf("\nOdpowiedz: ");
    f(T,P,N,l,k);

    return 0;
}
