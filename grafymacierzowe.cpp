#include <iostream>
#include <cstdlib>
#include <limits>

using namespace std;
const int N=6;
int inf = 99999;
void wypelnij(int t[N][N])
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            t[i][j]=inf;
        }
        t[i][i]=0;
    }


}

void print(int t[N][N])
{   cout<<"      ";
    for(int i=1;i<N-1;i++)
    {
        cout<<i<<"     ";
    }
    cout<<endl;
    cout<<"--------------------------"<<endl;
    for(int i=1;i<N-1;i++)
    {
        cout<<i<<" |";
        for(int j=1;j<N-1;j++)
        {
            if(t[i][j]==inf)
            {
                cout<<"     "<<"oo";
                continue;
            }
            cout<<"     "<<t[i][j];
        }
        cout<<endl;
    }
}

void floyd(int t[N][N])
{
    for(int k=1;k<N;k++)
    {
        for(int i=1;i<N;i++)
        {
            for(int j=1;j<N;j++)
            {
                t[i][j]=min(t[i][j],t[i][k]+t[k][j]);
            }
        }
    }
}


int main()
{
    int t[N][N];
    wypelnij(t);
    t[1][3]=-2;
    t[2][1]=4;
    t[2][3]=3;
    t[3][4]=2;
    t[4][2]=-1;
    floyd(t);
    print(t);

}
