#include <iostream>

using namespace std;

void f(int t[],int n)
{
    int maks;
    int mini;
    if(t[0]<t[1])
    {
        maks=t[1];
        mini=t[0];
    }else
    {
        maks=t[0];
        mini=t[1];
    }

    for(int i=0,j=1;j<n;i+=2,j+=2)
    {
        if(t[i]>t[j])
        {
            if(maks<t[i]) maks=t[i];
            if(mini>t[j]) mini=t[j];
        }else
        {
            if(maks<t[j]) maks=t[j];
            if(mini>t[i]) mini=t[i];
        }



    }
    cout<<"mini="<<mini<<" max="<<maks;



}
int main()
{
    int t[]={0,1,4,5,-123,-1};
    f(t,6);


    return 0;
}
