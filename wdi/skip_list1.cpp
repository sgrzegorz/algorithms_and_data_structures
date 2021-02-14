#include <iostream>

using namespace std;

const int max_level;

struct SLNode{
    int val;
    int level;
    SLNode **next;
};

struct SkipList{
    SLNode *first;
    SLNode *last;
};

Skiplist Merge(SkipList A,SkipList B)
{
    for(SLNode *q=A.first->next[0];q!=A.last;q=q->next[0])
    {
        Insert(B,q);
    }
    return B;
}

void Insert(Skiplist A,SLNode w)
{
    SLNode *x=A.first->next[0];
    for(int i=max_level-1;i>=0;i--)
    {
        while(x->next[i]!=A.last and w->val <x->next[i]->val)
        {
            x=x->next;
        }
        if(i<w->level)
        {
            w->next[i]=x->next[i];
            x->next[i]=w;
        }
    }
}

int main()
{



}
