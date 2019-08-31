#include <stdio.h>
#include <stdlib.h>

void moveBack(int t[])
{

    int A[100];
    int last,i;
    for(i=0;i<100;i++){A[i]=0;}


    for(i=0;i<100;i++)
    {
        if(t[i]==-1)
        {
            last=i-1;

            break;
        }
    }



    int j=99;
    for(i=last;i>=0;i--)
    {
        A[j]=t[i];
        j--;
    }
    for(i=0;i<100;i++){t[i]=A[i];}
}

void moveForeward(int t[])
{
    int i;
    for(i=199;i>=1;i--)
    {
        int n=t[i]-t[i]%10;
        t[i-1]+=n/10;
        t[i]=t[i]%10;
    }
}

int main()
{
     //srand( time( NULL ) );
    int A[100];
    int B[100];
    int t[200];
    int i;
    for(i=0;i<100;i++)
    {
        A[i]=-1;
        B[i]=-1;
    }
    for(i=0;i<200;i++){t[i]=0;}

    for(i=0;i<11;i++)
    {
        A[i]=rand()%10;
        B[i]=rand()%10;

    }


    moveBack(A);
    moveBack(B);


int j;
for(i=99;i>=0;i--)
{
    for(j=99;j>=0;j--)
    {
        t[100+j]+=A[j]*B[i];


int main()
{
}
