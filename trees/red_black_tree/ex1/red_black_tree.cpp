#include <iostream>
#include "print_binary_tree.cpp"
using namespace std;


RBNode *Find(RBNode *x,int key)
{
    if(x==NULLT or x->val==key)
        return x;
    else{
        if(key<x->val)
            return Find(x->left,key);
        else
            return Find(x->right,key);
    }
}


void leftRotate(RBNode *&root, RBNode *x)
{
    RBNode *y=x->right;
    x->right=y->left;
    y->left->up=x;
    y->up=x->up;
    if(x->up==NULLT)
        root=y;
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
    //cout<<x->val<<" "<<y->val;
    cout<<y->right;
    x->left=y->right;
    cout<<x->left;
    y->right->up=x;
    y->up=x->up;
    if(x->up==NULLT)
        root=y;
    else if(x->up->left==x)
        x->up->left=y;
    else
        x->up->right=y;
    y->right=x;
    x->up=y;

}

void fix(RBNode*&root,RBNode *z)
{
    RBNode *y;
    while(z->up->colour=='r')
    {
        if(z->up==z->up->up->left)
        {
            cout<<"a";
            y=z->up->up->right;
            if(y->colour=='r')
            {
                z->up->colour='b';
                y->colour='b';
                z->up->up->colour='r';
                z=z->up->up;
            }
            else
            {
                cout<<"B";
                if(z=z->up->right)
                {
                    z=z->up;
                    leftRotate(root,z);
                }
                z->up->colour='b';
                z->up->up->colour='r';
                rightRotate(root,z->up->up);
            }
        }
        else
        {
            cout<<"c";
            y=z->up->up->left;
            if(y->colour=='r')
            {
                z->up->colour='b';
                y->colour='b';
                z->up->up->colour='r';
                z=z->up->up;
            }
            else
            {
                cout<<"d";
                if(z=z->up->left)
                {
                    z=z->up;
                    rightRotate(root,z);
                }
                z->up->colour='b';
                z->up->up->colour='r';
                leftRotate(root,z->up->up);
            }
        }
    }
    root->colour='b';

}


void Insert(RBNode *&root,int key)
{
    RBNode *k=new RBNode;
    k->colour='r';
    k->val=key;
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
    k->up=y;

    fix(root,k);
}

void Inorder(RBNode *root)
{
    if(root!=NULLT)
    {
        Inorder(root->left);
        cout<<root->val<<" ";
        Inorder(root->right);
    }
}

int main()
{
    NULLT->colour='b';

    RBNode *q=NULLT;

    Insert(q,11);
    Insert(q,8);
    Insert(q,10);
    Insert(q,0);
    Insert(q,9);
    Insert(q,2);
    print2D(q);
    //Inorder(q);
    //cout<<Find(q,2)->up->val;
    //leftRotate(q,Find(q,0));
    cout<<";=======================";
    //print2D(q);

    return 0;
}



