#include <iostream>

using namespace std;

const int N=8;

void sortuj(string t[],int p)
 {
     for(int i=0;i<N;i++)
     {
        int mi=i;
        for(int j=i;j<N;j++)
        {

            if(t[j][p]<t[mi][p])
            {
                mi =j;

                 cout<<" "<<t[j][p]<<" "<<t[mi][p]<<endl;
            }
        }
        string tmp=t[mi];
        t[mi]=t[i];
        t[i]=tmp;

     }
     cout<<p<<endl;
     for(int i=0;i<N;i++)
    {
        cout<<t[i]<<endl;
    }
    cout<<endl<<endl;

 }

 void sortString(string A[])
 {
     int m=A[0].length();
     for(int i=0;i<N;i++)
     {
         if(A[i].length()>m)
         {
             m=A[i].length();
         }
     }
     for(int i=0;i<N;i++)
     {
         while(A[i].length()!=m)
         {
             A[i]+='1';
         }
     }
     for(int i=N-1;i>=0;i--)
     {
         sortuj(A,i);
     }
     for(int i=0;i<N;i++)
     {
         string s="";
         for(int j=0;j<A[i].length();j++)
         {
             if(A[i][j]!='1')
             {
                 s+=A[i][j];
             }
         }
         A[i]=s;
     }

 }

int main()
{
    string t[]={"abcde","abd","abcdcf","akb","wbc","abwdefg","ab","woandaof"};

    sortString(t);

    for(int i=0;i<N;i++)
    {
        cout<<t[i]<<endl;
    }
}
