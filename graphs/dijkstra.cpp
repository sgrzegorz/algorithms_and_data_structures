#include <iostream>
#include <cstdlib>
#include <limits>

using namespace std;
const int N=4;
double INF = std::numeric_limits<int>::max();
void wypelnij(int t[N][N])
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            t[i][j]=INF;
        }
        t[i][i]=0;
    }


}

void print(int t[N][N])
{   cout<<"      ";
    for(int i=0;i<N;i++)
    {
        cout<<i<<"     ";
    }
    cout<<endl;
    cout<<"--------------------------"<<endl;
    for(int i=0;i<N;i++)
    {
        cout<<i<<" |";
        for(int j=0;j<N;j++)
        {
            if(t[i][j]==INF)
            {
                cout<<"     "<<"oo";
                continue;
            }
            cout<<"     "<<t[i][j];
        }
        cout<<endl;
    }
}

struct vertex{
    int pred;
    double dist;
};

vertex* dijkstra(double **w,int N,int s)
{
    vertex *t=new vertex;
    bool visited[N];
    for(int i=0;i<N;i++)
    {
        t[i].dist=INF;
        t[i].pred=-1;
        visited[i]=false;
    }
    visited[s]=true;
    t[s].pred=s;
    t[s].dist=0;
    for(int i=0;i<N;i++) // N razy wybierz najmniejszy wierzcho³ek
    {
        int current=0;
        double current_dist=INF;
        for(int j=0;j<N;j++)
        {
            if(t[j].dist<t[current].dist && !(visited[j]))
            {
                current=j;
                current_dist=t[j].dist;
            }
        }

        for(int j=0;j<N;j++) // Czy przechodz¹c przez j mo¿na odnalezc krotsza od dotychczasowej najkrotszej sciezki do V.
        {
            if(t[j].dist+w[current][j]<t[current].dist)
            {
                t[current].dist=t[j].dist+w[current][j];
                t[current].pred=j;
            }
        }
        visited[current]=true;
    }
    return t;
}


int main()
{
    int t[N][N];
    wypelnij(t);
    t[1][3]=-2;
    t[2][1]=4;
    t[2][3]=3;





    print(t);

}
