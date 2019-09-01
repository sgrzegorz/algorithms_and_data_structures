#include <iostream>

using namespace std;
const int N=4;
int INF = 99999;

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



struct Node{
    int val;
    Node *next;
    int w; //weight
};

Node * t[N];

void add(int vertex, int sasiad,int waga)
{
    Node *s=new Node;
    s->w=waga;
    s->val=sasiad;
    s->next=NULL;

    Node *q=t[vertex];

    if(q==NULL)
    {
        t[vertex]=s;
        return;
    }


    while(q->next!=NULL)
    {
        q=q->next;
    }
    q->next=s;
}
bool edge(int A, int B)
{
    Node *q=t[A];
    while(q!=NULL)
    {
        if(q->val==B) return true;
        q=q->next;
    }
    return false;
}

Node *wsk(int A,int B)
{
    Node *q=t[A];
    if(q==NULL) return NULL;
    while(q->next!=NULL)
    {
        if(q->val==B)
        {
            return q;
        }
        q=q->next;
    }
    return NULL;
}

void print(){
    for(int i=0;i<N;i++)
    {
        Node *q=t[i];
        cout<<i<<"| ";
        while(q!=NULL)
        {
            cout<<"("<<q->val<<",w: "<<q->w<<") ";;
            q=q->next;
        }
        cout<<endl;
    }

}

int main()
{
    for(int i=0;i<N;i++)
    {
        t[i]=NULL;
    }
    add(1,3,1);
    add(1,2,1);

    print();




}
