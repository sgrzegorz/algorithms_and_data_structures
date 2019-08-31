#include <stdio.h>
#include <stdlib.h>

const int N=5;

void print(int t[N][N])
{
    int x,y;
    for(y=0;y<N;y++)
    {
            for(x=0;x<N;x++)
            {
                printf("%i ",t[x][y]);
            }
            printf("\n");
    }
}

int diagonal(int t[N][N])
{
    int i,j;
    int suma=0;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            if(i==j)  suma+=t[i][j];
        }
    }
    return suma;
}

int below(int t[N][N])
{
    int x,y;
    int suma=0;
    for(y=0;y<N;y++)
    {
        for(x=0;x<N;x++)
        {
            if(x<y)  suma+=t[x][y];
        }
    }
    return suma;
}
int all(int t[N][N])
{
    int i,j;
    int suma=0;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            suma+=t[i][j];
        }
    }
    return suma;
}

int f(int A[N][N],int B[N][N],int x,int y)
{
    int i;
    int suma=0;
    for(i=0;i<N;i++)
    {
        suma+=A[x][i]*B[i][y];
    }
    return suma;
}

void matrix(int A[N][N],int B[N][N],int t[N][N])
{
        int x,y;
        for(y=0;y<N;y++)
        {
            for(x=0;x<N;x++)
            {
                t[x][y]=f(A,B,x,y);
            }
        }
}


int main()
{
    int A[N][N];
    int B[N][N];
    int C[N][N];

    int i,j;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            A[i][j]=rand()%2;
            B[i][j]=rand()%2;
            C[i][j]=0;
        }
    }


    print(A);
    printf("\n");
    print(B);
    printf("\n");
    //matrix(A,B,C);
    printf("%i",f(A,B,0,2));
    return 0;
}
