#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;
double drand48(void);
struct SLNode{
    int val;
    SLNode **next;//tablica wskaznikow
};
struct Skiplist{
    SLNode *first;
    SLNode *last;
    int height;
};

int getHeight(int max_h)
{
    double p=1/2;
    int h=1;
    while(h<max_h &&  p< drand48()) h++;
    return h;
}

int main()
{
    Skiplist *lista=new Skiplist;
    lista->height=5;
    cout<<getHeight(2);
    cout << "Hello world!" << endl;
    return 0;
}
