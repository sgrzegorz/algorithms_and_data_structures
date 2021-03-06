#include <iostream>



using namespace std;

struct ekstrema
{
    int maks;
    int mini;
};

struct node
{
    int w;
    node*next;
};

void wypisz(node *q)
{
    cout<<endl;
    while(q!=NULL)
    {
        cout<<q->w<<"  ->  ";
        q=q->next;
    }
    cout<<"NULL"<<endl;

}

node *buduj(int t[],int n)
{
    if(n==0) return NULL;
    node *p=new node;
    p->next=NULL;
    p->w=t[n-1];
    if(n>1)
    {
        for(int i=n-2;i>=0;i--)
        {
            node *q=new node;
            q->next=p;
            q->w=t[i];
            p=q;
        }
    }
    return p;
}

node *odwrotnie(node *q)
{

    node *j=NULL;
    for(;q!=NULL;q=q->next)
    {
        node *x=new node;
        x->w=q->w;
        x->next=j; // j <- x ...
        j=x;
    }
    return j;
}


node *wstaw(int value, node *head)
{

    node *p=new node; p->next=head;
    head=p;
    node *q=p->next;
    bool flaga=true;

    for(;q!=NULL;p=q,q=q->next)
    {
        if(value < q->w)
        {
            node *r=new node;
            r->w=value;
            p->next=r;
            r->next=q;
            flaga=false;
            break;
        }
    }
    if(flaga)
    {
        node *r=new node;
        r->w=value;
        r->next=NULL;
        p->next=r;
    }
    return head->next;
}

node *sortuj(node *head)
{
    if(head==NULL) return NULL;

    node *first=new node;
    first->w=head->w;
    first->next=NULL;
    head=head->next;

    while(head!=NULL)
    {
        first=wstaw(head->w,first);
        head=head->next;

    }
    return first;

}


ekstrema f(node *p)
{
    ekstrema x;
    if(p->next==NULL)
    {
        x.maks=p->w;
        x.mini=p->w
        return x;
    }

}

int main()
{

    int t[]={1};
    node *p=buduj(t,1);
    wypisz(p);

    p=odwrotnie(p);
    wypisz(p);

}
