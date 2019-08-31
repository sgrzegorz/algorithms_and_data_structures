#include <iostream>

using namespace std;

struct RBNode{
    RBNode*left;
    RBNode*right;
    RBNode*up;
    char colour;
    int key;
};


leftRotate(RBNode *T,RBNode *x)
{

    RBNode *y=x->right;
    x->right=y->left;
    y->left->up=x;
    y->up=x->up;
    if(x->up==NULL){
        T=y;
    }else if(x->up->left==x){
        y=x->up->left;
    }else{
        y=x->up->right;
    }
    y->left=x;
    x->up=y;
}

rightRotate(RBNode *T,RBNode *x)
{
    RBNode *y=x->left;
    x->left=y->right;
    y->right->up=x;
    y->up=x->up;
    if(x->up->left==NULL)
    {
        T=y;
    }else if(x->up->left==x){
        x->up->left=y;
    }else{
        x->up->right=y;
    }
    y->left=x;
    x->up=y;
}

void rbInsertFixup(RBNode *T,RBNode *z)
{
    while(z->up->colour=='r')
    {
        if(z->up==z->up->up->left)
        {
            RBNode*y=z->up->up->right;
            if(y->colour=='r') //P1
            {
                z->up->colour='b';
                y->colour='b';
                z->up->up->colour='r';
                z=z->up->up;
            }
            else if(z==z->up->right)
            {
                z=z->up;           //P2
                leftRotate(T,z);   //P2
                z->up->colour='b';                 //P3
                z->up->up->colour='r';
                rightRotate(T,z->up->up);
            }
        }else{   //JEBANY PRZYPADEK SYMETRYCZNY
                 RBNode*y=z->up->up->left;
            if(y->colour=='r') //P1
            {
                z->up->colour='b';
                y->colour='b';
                z->up->up->colour='r';
                z=z->up->up;
            }
            else if(z==z->up->left)
            {
                z=z->up;           //P2
                rightRotate(T,z);   //P2
                z->up->colour='b';                 //P3
                z->up->up->colour='r';
                leftRotate(T,z->up->up);
            }

        }
    }

}

void TreeDelete(BSTNode *T,BSTNode *z)
{
    if(z->left==NULL or z->right=NULL)
        y=z;
    else
        y=Successor(z);


}

void RBinsert(RBNode *T,RBNode *z)
{
    RBNode*y=NULL;
    RBNode*x=T;
    while(x!=NULL)
    {
        y=x;
        if(z->key<x->key)
        {
            x=x->left;
        }else{
            x=x->right;
        }
    }
    x->up=y;
    if(y==NULL){
        T=z;
    }else if(z->key<y->key){
        y->left=z;
    }else{
        y->right=z;
    }
    z->left=NULL;
    z->right=NULL;
    z->colour='r';
    rbInsertFixup(T,z);
}

int main()
{
    RBNode *

    cout << "Hello world!" << endl;
    return 0;
}
