#include <stdio.h>
#include <stdlib.h>


void inic(int t[],int N)
{
    for(int i=0;i<N;i++)
    {
        t[i]=rand()%10+1;
    }
}
void print(int t[],int N)
{

    for(int i=0;i<N;i++)
    {
        printf(" %i ",t[i]);
    }
  printf("\n");
}

void zamiana(int t[],int x,int y)
{
    int tmp=t[y];
    t[y]=t[x];
    t[x]=tmp;
}

void odwroc(int t[],int N)
{
    int i=0;
    int j=N-1;
    while(i<j)
    {
        zamiana(t,i,j);
        i++;
        j--;
    }
}

void wymien_tablice(int t1[],int t2[],int N)
{
    for(int i=0;i<N;i++)
    {
        int tmp=t1[i];
        t1[i]=t2[i];
        t2[i]=tmp;
    }
}


void QS(int A[],int p,int r)
{
    if(p<r)
    {
        int q=Partition(A,p,r);
        QS(A,p,q-1);
        QS(A,q+1,r);
    }
}

int Partition(int A[],int p,int r)
{
    int x=A[r];
    int i,j;
    i=p-1;
    for(j=p;j<r;j++)
    {
        if(A[j]<=x){
            i+=1;
            zamiana(A,i,j);
        }
    }
    zamiana(A,i+1,r);
    return i+1;
}


int one_two(int t1[], const int N1, int t2[], const int N2)
{
    int t[N1+N2];
    for(int i=0;i<N1;i++)
    {
        t[i]=t1[i];
    }
    for(int i=0;i<N2;i++)
    {
        t[i+N1]=t2[i];
    }
    QS(t,0,N1+N2-1);
    print(t,N1+N2);

    int k=0;

    int i=0;
    while(i<N1+N2)
    {
        t[k]=t[i];
        k++;

        int c=t[i];
        while(t[i]==c){i++;}
    }

    const int N3=k;
    int C[N3];
    for(int i=0;i<k;i++){C[i]=t[i];}

    printf("<<: ");
    print(C,k);
    return k;
}

int main()
{
    srand(time(NULL));

    const int N1=10;
    const int N2=5;
    int t2[N2];
    int t1[N1];
    inic(t1,N1);
    inic(t2,N2);
    QS(t1,0,N1);
    QS(t2,0,N2);

    print(t1,N1);
    printf("\n");
    print(t2,N2);
    printf("\n");

    int p=one_two(t1,N1,t2,N2);

}
