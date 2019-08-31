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
void add(int u,int v,int value){ //DODAJ KRAWEDZ u->v O WARTOŒCI VALUE DO ZBIORU EDGE
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
void krawedzie(){ //WYPISZ ZBIOR KRAWEDZI EDGE
    cout<<"u->v, value\n";
    for(edge*e=start;e!=NULL;e=e->next)
    {
        cout<<e->u<<"->"<<e->v<<", "<<e->value<<endl;
    }
}

struct Queue{
    int val;
    Queue *next;
};
Queue *start=NULL;
void push(int value){   //PUSH INT TO PRIORITY QUEUE
    Queue *e=new Queue;
    e->val=value;
    e->next=NULL;

    Queue *p=new Queue;
    p->next=start;
    Queue *q=p;
    while(q->next!=NULL)
    {
        if(q->next->val>=value) break;
        q=q->next;
    }
    e->next=q->next;
    q->next=e;
    start=p->next;

}
bool isEmpty(){
    if(start == NULL) return true;
    return false;
}
void printQ(){         //PRINT ALL ELEMENTS OF PRIORITY QUEUE
    cout<<endl;
    Queue *q=start;
    while(q!=NULL)
    {
        cout<<q->val<<" -> ";
        q=q->next;
    }
    cout<<"NULL"<<endl;

}
int pop(){             //POP SMALLEST ELEMENT FROM PRIORITY QUEUE

    if(start==NULL) return INF;

    int tmp=start->val;
    Queue *p=start;

    start=start->next;
    delete p;
    return tmp;

}


struct vertex{
    int pred;
    double dist;
};




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



    return 0;


}
