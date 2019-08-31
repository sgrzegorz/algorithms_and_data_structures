#include <iostream>
#include <cstdlib>
using namespace std;
const int N=9;

int main()
{
    int d[N][N];
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            d[i][j]=rand()%10;
        }
    }

    for(int k=0;k<N;k++)
    {
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                if( d[i][j]>d[i][k]+d[k][j]) d[i][j]=d[i][k]+d[k][j];
            }
        }
    }

    return 0;
}
