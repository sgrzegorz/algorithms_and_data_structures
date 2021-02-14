#include <iostream>
#include "print_tree.cpp"
using namespace std;


AVLNode *Find(AVLNode *x,int key)
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


void leftRotate(AVLNode *&root, AVLNode *x)
{
    AVLNode *y=x->right;
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

void rightRotate(AVLNode *&root,AVLNode *x)
{
    AVLNode *y=x->left;
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


void Insert(AVLNode *&root,int key)
{
    AVLNode *k=new AVLNode;
    k->Rank=0;
    k->val=key;
    k->left=k->right=NULLT;
    AVLNode *x=root,*y=NULLT;

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

    //fix(root,k);
}

void Inorder(AVLNode *root)
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


    AVLNode *q=NULLT;

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



