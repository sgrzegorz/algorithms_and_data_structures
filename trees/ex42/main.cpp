#include <iostream>
#include "x.cpp"
using namespace std;
/*
struct RBNode{
    RBNode *left,*right,*up;
    int key;
    char colour;
};
*/
RBNode *NULLT;

void leftRotate(RBNode *&T,RBNode *x)
{
    RBNode *y=x->right;
    x->right=y->left;
    y->left->up=x;
    y->up=x->up;
    if(x->up==NULLT)
        T=y;
    else if(x==x->up->left)
        y->up->left=y;
    else
        y->up->right=y;
    y->left=x;
    x->up=y;
}

void rightRotate(RBNode *&T,RBNode *x)
{
    RBNode *y=x->left;
    x->left=y->right;
    y->right->up=x;
    y->up=x->up;
    if(x->up==NULLT)
        T=y;
    else if(x==x->up->right)
        y->up->right=y;
    else
        y->up->left=y;
    y->right=x;
    x->up=y;
}

void fixup(RBNode *&T,RBNode *z)
{
    RBNode*y;
    while(z->up->colour=='r')
    {
        if(z->up==z->up->up->left)
        {
            y=z->up->up->right;
            if(y->colour=='r')
            {
                z->up->colour='b';
                y->colour='b';
                z->up->up->colour='r';
                z=z->up->up;
            }
            else if(z==z->up->right)
            {
                z=z->up;
                leftRotate(T,z);
                z->up->colour='b';
                z->up->up->colour='r';
                rightRotate(T,z->up->up);
            }
        }
        else
        {
            y=z->up->up->left;
            if(y->colour=='r')
            {
                z->up->colour='b';
                y->colour='b';
                z->up->up->colour='r';
                z=z->up->up;
            }
            else if(z==z->up->left)
            {
                z=z->up;
                leftRotate(T,z);
                z->up->colour='b';
                z->up->up->colour='r';
                rightRotate(T,z->up->up);
            }
        }
    }
    T->colour='b';
}

void Insert(RBNode *&T,int key)
{
    RBNode *z=new RBNode;
    z->key=key;

    RBNode *x=T,*y=NULLT;
    while(x!=NULLT)
    {
        y=x;
        if(z->key<x->key)
            x=x->left;
        else
            x=x->right;
    }
    z->up=y;
    if(y==NULLT)
        T=z;
    else if(z->key<y->key)
        y->left=z;
    else
        y->right=z;

    z->left=NULLT;
    z->right=NULLT;
    z->colour='r';
    fixup(T,z);

}

int main()
{
    NULLT=new RBNode;
    NULLT->left=NULLT;
    NULLT->right=NULLT;
    NULLT->up=NULLT;
    NULLT->colour='c';
    NULLT->key=999;
    RBNode *x=NULLT;
    Insert(x,4);
    Insert(x,5);
    Insert(x,-4);
    Insert(x,43);
    //print2D(x);
    cout << "Hello world!" << endl;
    return 0;
}
