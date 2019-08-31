#include <iostream>

using namespace std;

struct BSTNode{
    BSTNode *up;
    BSTNode *right;
    BSTNode *left;
    int key;
};
void inorder(BSTNode *v){
    if(v!=NULL){
        inorder(v->left);
        cout<<v->key<<" ";
        inorder(v->right);
    }
}

BSTNode *Find(BSTNode *root,int key)
{
    if(root==NULL) return NULL;
    if(root==key) return root;
    else if(key<root->key)
    {
        return Find(root->left,key);
    }else{
        return Find(root->right,key);
    }
}

void addNode(BSTNode *&tree, BSTNode *newNode){
    if(tree==NULL){
        tree=newNode;
    }else{
        BSTNode *cp=tree;
        while(true){
            if(newNode->key<=cp->key)
            {
                if(cp->left ==NULL) break;
                else
                    cp=cp->left;
            }else{
                if(cp->right==NULL)
                    break;
                else
                    cp=cp->right;
            }
        }
    }
    newNode->up=cp;
    if(newNode->key<=cp->key)
        cp->left=newNode;
    else
        cp->right=newNode;

}

BSTNode * Successor(BSTNode *x)
{
    if(x->right!=NULL)
        return Min(x->right);
    BSTNode *y=x->up;
    while(y!=NULL && x==y->right){
        x=y;
        y=y->up;
    }
    return y;
}

BSTNode *Predeccessor(BSTNode *x)
{
    if(x->left!=NULL)
        return Max(x->left);
    BSTNode *y=x->up;
    while(y!=NULL && x==y->left){
        x=y;
        y=y->up;
    }
    return y;
}
BSTNode *deleteNode(BSTNode *&root,BSTNode *z)
{
    BSTNode *y,*x;
    if()
}



int main()
{


    return 0;
}
