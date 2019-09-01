#include <iostream>
#include "x.cpp"

using namespace std;
/*
struct BSTNode{
    BSTNode *right;
    BSTNode *left;
    BSTNode *up;
    int key;
};
*/
BSTNode *Min(BSTNode *T)
{
    while(T->left!=NULL)
    {
        T=T->left;
    }
    return T;
}

BSTNode *Successor(BSTNode *x)
{
    if(x->right!=NULL)
        return Min(x->right);
    BSTNode *y=x->up;
    while(y->right!=NULL)
    {
        x=y;
        y=y->up;
    }
    return y;
}
BSTNode *Find(BSTNode *T,int x)
{
    if(T==NULL) return NULL;
    if(T->key==x) return T;
    if(x<T->key)
        return Find(T->left,x);
    else
        return Find(T->right,x);
}

BSTNode *Delete(BSTNode *T,BSTNode *z)
{
    BSTNode *x,*y;
    if(z->right==NULL or z->left==NULL)
        y=z;
    else
        y=Successor(z);
    if(y->left!=NULL)
        x=y->left;
    else
        x=y->right;
    if(x!=NULL)
        x->up=y->up;
    if(y->up==NULL)
        T=x;
        else if(y==y->up->left)
            y->up->left=x;
        else
            y->up->right=x;
    if(y->key!=z->key)
    {
        z->key=y->key;
    }
    return T;
}

void Insert(BSTNode *&T,int key)
{
    BSTNode *z=new BSTNode;
    z->key=key;
    z->left=NULL;
    z->right=NULL;
    z->up=NULL;
    BSTNode *y=NULL;
    BSTNode *x=T;

    while(x!=NULL)
    {
        y=x;
        if(z->key<x->key)
            x=x->left;
        else
            x=x->right;
    }

        z->up=y;
        if(T==NULL)
            T=z;
        else if(z->key<y->key)
            y->left=z;
        else
            y->right=z;
}


int main()
{
    BSTNode *x=NULL,*y;
    Insert(x,18);
    Insert(x,7);
    Insert(x,-2);
    Insert(x,4);
    Insert(x,17);
    Insert(x,-4);
    y=Find(x,18);
    x=Delete(x,y);
    print2D(x);
    return 0;
}
