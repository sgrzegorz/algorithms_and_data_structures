#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define RAND_MAX 0x7fff
int N=4;

typedef struct {
    float x;
    float y;
} complex;

void print(complex *t)
{
    for(int i=0;i<N;i++)
    {
        printf("%i (%f,%f) \n",i,t[i].x,t[i].y);
    }
}


int compare(const int *p, const int *q)
{
    float p1=sqrt ( pow( ((complex*)p)->x , 2 ) + pow( ((complex*)p)->y ,2 ));
    float p2=sqrt( pow( ((complex*)q)->x,2 ) + pow( ((complex*)q)->y,2 ));
    return (int) p1-p2;
}


/*
void qsort(void* base, size_t num, size_t width, int (*compare)(const void*, const void*));
{

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
*/

//compare(const void *)



int main()
{
    srand(time(NULL));
    complex *t = (complex*) malloc(sizeof(complex)*N);
    for(int i=0;i<N;i++)
    {
        t[i].x= (float) rand()/ (float) RAND_MAX *20 -10;
        t[i].y= (float) rand()/ (float) RAND_MAX *20 -10;
    }

   //printf("%d",compare(&t[1],&t[2]));
   void const * p;
   p=&t[1];
   t[1].x=5.0;
   printf("%zu",sizeof(complex));
   //complex *r= t+sizeof(complex);
   //printf("%f",r->x);
   void const *k;
   k=&t[1];
   k=&t[2];
   sqrt(2);
   //printf("%f",sqrt(2.1));


    return 0;
}
