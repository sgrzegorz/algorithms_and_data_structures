#include <iostream>

using namespace std;
const int N=4;
const int T=13;

int knapsack(int P[N], int W[N])
{
    int F[N+1][T+1];
    for(int i=0;i<N+1;i++){F[i][0]=0;}
    for(int t=0;t<T+1;t++){F[0][t]=0;}

    for(int i=1;i<=N;i++)
    {
        for(int t=1;t<=T;t++)
        {
            if(W[i]>t)
                F[i][t]=F[i-1][t];
            else
                F[i][t]=max(P[i]+F[i-1][t-W[i]],F[i-1][T]);
        }
    }
    return F[N][T];
}


int main()
{
    int P[]={-122,9,11,2,5};
    int W[]={-78,6,7,3,20};
    cout<<knapsack(P,W);




    return 0;
}
