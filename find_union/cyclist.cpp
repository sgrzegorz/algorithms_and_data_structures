#include <iostream>

using namespace std;

struct Cyclist{
    int id,n_id;
};

struct Node{
    Node *parent;
    int Rank;
    int id,n_id;
};

Node *makeSet(Cyclist x)
{
    Node *q=new Node;
    q->id=x.id;
    q->n_id=x.n_id;
    q->parent=q;
}

Node *findSet(Node *x)
{
    if(x->parent!=x)
        x->parent=findSet(x->parent);
    return x->parent;
}

void Union(Node *x,Node *y)
{
    x=findSet(x);
    y=findSet(y);
    if(x->Rank<y->Rank)
    {
        x->parent=y;
    }
    else
    {
        y->parent=x;
        if(y->Rank==x->Rank) x->Rank++;
    }
}

int smallestGroup(Cyclist cyclist[],int n)
{
    Node* tab[n];
    for(int i=0;i<n;i++)
    {
        tab[i]=MakeSet(t[i]);
    }
    for(int i=0;i<n;i++)
    {
        if(findSet(tab[i])!=findSet(tab[tab[i].n_id)])
        {
            Union(findSet(tab[i]),findSet(tab[tab[i].n_id)]);
        }
    }
    int suma=0;
    for(int i=0;i<n;i++)
    {
        if(t[i]->Rank>suma) suma=t[i]->Rank;
    }
    return suma;
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}






