#include <iostream>

using namespace std;
int l=0;
int f(int x,int y)
    {
        int z;
        while(1)
        {
            if(x==2016)
            {
                cout<<"out";
                return 1;

            }
             if(x>2016)
            {
                l+=1;
                cout<<"out"<<l<<endl;
                return 0;
            }

            z=x+y;
            x=y;
            y=z;

        }
    }

int main()
{
    int a=1;
    int b=1;

    while(b<500)
    {
        if(f(a,b))
            cout<<a<<" "<<b;
        else
            b+=1;
    }
    while(a<500)
    {
        if(f(a,b))
            cout<<"---"<<a<<" "<<b;

        else
            a+=1;
    }


}
