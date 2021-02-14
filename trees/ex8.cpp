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
    RBNode *NULLT=T->up;
    RBNode *y=x->right;
    x->right=y->left;
    y->left->up=x;
    y->up=x->up;
    if(x->up==NULLT){
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
    RBNode *NULLT=T->up;
    RBNode *y=x->left;
    x->left=y->right;
    y->right->up=x;
    y->up=x->up;
    if(x->up->left==NULLT)
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
    RBNode *NULLT=T->up;
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
        }else{   // PRZYPADEK SYMETRYCZNY
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

void RBinsert(RBNode *T,RBNode *z)
{
    RBNode *NULLT=T->up;
    RBNode*y=NULLT;
    RBNode*x=T;
    while(x!=NULLT)
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
    if(y==NULLT){
        T=z;
    }else if(z->key<y->key){
        y->left=z;
    }else{
        y->right=z;
    }
    z->left=NULLT;
    z->right=NULLT;
    z->colour='r';
    rbInsertFixup(T,z);
}

int main()
{
    RBNode *NULLT;
    NULLT->left=NULLT;
    NULLT->right=NULLT;
    NULLT->colour='b';
    NULLT->up=NULLT;
    RBNode *p;
    p->key=6;
    RBinsert(NULLT,p);


    cout << "Hello world!" << endl;
    return 0;
}
