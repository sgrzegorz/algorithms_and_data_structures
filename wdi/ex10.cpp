#include <iostream>
#include <cstdlib>

using namespace std;
 const int N=20;
void print(int t[])
{
    for(int i=0;i<N;i++)
    {
        cout<<t[i]<<" ";
    }
}

int main()
{

    int A[N];

    for(int i=0;i<N;i++)
    {
        A[i]=rand()%10;
    }
    print(A);

    int F[N];

    for(int i=0;i<N;i++)
    {
        F[i]=1; int p[N];
        for(int j=0;j<i;j++)
        {
            if(A[j]<A[i])
            {
                if(max(F[j]+1,1)>F[i])
                {
                    F[i]=max(F[j]+1,1);
                }
            }
        }
    }
  cout<<endl;
    print(F);



    return 0;
}
