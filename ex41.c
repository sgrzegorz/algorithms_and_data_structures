#include <iostream>

using namespace std;

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



int main()
{

    int t[]={-1,232,6,-43,9,4,12,51,141,-12};
    node *p=buduj(t,10);
    wypisz(p);

    p=sortuj(p);
    wypisz(p);

}
=======================================================================================================================

node *odwrotnie(node *q) //odwrocenie listy jednokierunkowej 
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
====================================================================
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
==========================================================================