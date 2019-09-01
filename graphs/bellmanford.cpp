#include <iostream>
int INF=999999;
using namespace std;



struct edge{
    int u;
    int v;
    int value;
    edge *next;
};

edge *start=NULL;
void add(int u,int v,int value)
{
    edge *e=new edge;
    e->u=u;
    e->v=v;
    e->value=value;
    e->next=NULL;

    edge* q=new edge;
    q->next=start;
    edge* p=q;

    while(p->next!=NULL)
    {
        if(p->next->value>=value) break;
        p=p->next;
    }
    e->next=p->next;
    p->next=e;
    start=q->next;
    delete q;
}


void wypisz()
{
    cout<<"u->v, value\n";
    for(edge*e=start;e!=NULL;e=e->next)
    {
        cout<<e->u<<"->"<<e->v<<", "<<e->value<<endl;
    }
}

struct vertex{
    int pred;
    double dist;
};

vertex* BF(edge *E,int V,int S)
{
    vertex *output=new vertex[10];
    for(int i=0;i<V;i++)
    {
        output[i].pred=-1;
        output[i].dist=INF;
    }
    output[0].pred=0;
    output[0].dist=0;

    for(int i=0;i<V;i++)
    {
        for(edge *e=E;e!=NULL;e=e->next)
        {
            if(output[e->v].dist>output[e->u].dist+e->value)
            {
                output[e->v].dist=output[e->u].dist+e->value;
                output[e->v].pred=e->u;
            }
        }
    }

    for(edge*e=E;e!=NULL;e=e->next)
    {
        if(output[e->v].dist>output[e->u].dist+e->value)
        {
            delete[] output;
            return NULL;
        }
    }

    return output;
}

int main()
{
    add(0,1,5);
    add(1,4,9);
    add(1,3,3);
    add(2,0,3);
    add(2,1,-4);
    add(3,4,3);
    add(3,5,2);
    add(4,2,-1);
    add(4,5,-5);
    add(5,0,9);
    add(5,2,8);

    wypisz();

    vertex *output=BF(start,6,0);
    for(int i=0;i<6;i++)
    {
        cout<<output[i].dist<<"  ";
    }
    cout<<endl;
    for(int i=0;i<6;i++)
    {
        cout<<output[i].pred<<"  ";
    }
    cout<<endl;
    return 0;
}
