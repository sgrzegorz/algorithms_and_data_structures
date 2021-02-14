#include <iostream>

using namespace std;



struct RBNode{
    RBNode *left,*right,*up;
    int val;
    char colour;
};

RBNode *NULLT=new RBNode ;

void leftRotate(RBNode *&root, RBNode *x)
{
    RBNode *y=x->left;
    x->right=y->left;
    y->left->up=x;
    y->up=x->up;
    if(x->up==NULLT)
        y=root;
    else if(x->up->left==x)
        x->up->left=y;
    else
        x->up->right=y;
    x->up=y;
    y->left=x;
}

void rightRotate(RBNode *&root,RBNode *x)
{
    RBNode *y=x->left;
    x->right=y->left;
    y->left->up=x;
    y->up=x->up;
    if(x->up==NULLT)
        root=y;
    else if(x->up->left==x)
        x->up->left=y;
    else
        x->up->right=y;
    y->left=x;
    x->up=y;

}

void Insert(RBNode *&root,int key)
{
    RBNode *k=new RBNode;
    k->colour='r';
    k->left=k->right=NULLT;
    RBNode *x=root,*y=NULLT;

    while(x!=NULLT)
    {
        y=x;
        if(key<x->val)
            x=x->left;
        else
            x=x->right;
    }
    if(y==NULLT)
        root=k;
    else if(key<y->val)
        y->left=k;
    else
        y->right=k;

}

int main()
{
    NULLT->colour='b';

    RBNode *q=NULLT;


    Insert(q,1);
    Insert(q,8);
    Insert(q,10);


    return 0;
}



