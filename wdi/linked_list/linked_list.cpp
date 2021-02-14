#include <iostream>
#include "linked_list.h"





void wypisz(node *f)
{
    cout<<endl;
    node* q=f;
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