#include <stdio.h>
#include <stdlib.h>

const int N1=5;
const int N2=5;


void wypelnij(int t[],const int N)
{
    int i=0;
    for(i=0;i<N;i++)
    {
        t[i]=rand()%10;
    }
}

void drukuj(int t[],const int N)
{
    int i=0;
    for(i=0;i<N;i++)
    {
        printf("%i ",t[i]);
    }
    printf("\n");
}
void zamiana(int t[],int x,int y)
{
    int tmp=t[x];
    t[x]=t[y];
    t[y]=tmp;
}

void odwroc(int t[],const int N)
{
    int i;
    for(i=0;i<N/2;i++)
    {
         zamiana(t,i,N-1-i);
    }
}

void wymien_tablice(int A[],int B[],int N)
{
    int i;
    for(i=0;i<N;i++)
    {
        int tmp=A[i];
        A[i]=B[i];
        B[i]=tmp;
    }
}

void QS(int t[],int p,int k)
{
    if(p<k)
    {
        int q=Partition(t,p,k);
        QS(t,p,q-1);
        QS(t,q+1,k);
    }

}

int Partition(int t[],int p,int k)
{

    int x=t[k];
    int i,j;
    i=p-1;
    for(j=p;j<k;j++)
    {
        if(t[j]<=x)
        {
            i++;
            zamiana(t,i,j);
        }
    }
    zamiana(t,i+1,k);
    return i+1;

}

int one_two(int A[], int N1, int B[], int N2,int C[])
{


}


int main()
{
    int A[N1];
    int B[N2];
    wypelnij(A,N1);


    drukuj(A,N1);
    QS(A,0,N1-1);
    QS(B,0,N2-1);
    //odwroc(A,N1);
    drukuj(A,N1);


}
