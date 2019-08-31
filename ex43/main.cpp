#include <iostream>
#include "x.cpp"
using namespace std;


void addNode(BSTNode * &tree, int klucz)
{

    BSTNode *newNode=new BSTNode;
    newNode->right=NULL;
    newNode->left=NULL;
    newNode->up=NULL;
    newNode->key=klucz;

	if (tree == NULL) {
		tree = newNode;
	} else {
		BSTNode * cp = tree;
		while (true) {
			if (newNode->key <= cp->key) {
				if (cp->left == NULL)
					break;
				else
					cp = cp->left;
			} else {
				if (cp->right == NULL)
					break;
				else
					cp = cp->right;
			}
		}

		newNode->up = cp;
		if (newNode->key <= cp->key)
			cp->left = newNode;
		else
			cp->right = newNode;
	}
}

void inorder(BSTNode *tree)
{
    if(tree!=NULL)
    {
        inorder(tree->left);
        cout<<tree->key<<" ";
        inorder(tree->right);
    }

}


BSTNode *Find(BSTNode *root,int key)
{
    if(root==NULL)return NULL;
    if(root->key==key){
        return root;
    }else if(key<root->key){
        return Find(root->left,key);
    }else{
        return Find(root->right,key);
    }
}

BSTNode *Max(BSTNode *root){
     if(root==NULL) return NULL;
     BSTNode* w=root;
     while(w->right!=NULL){
        w=w->right;
     }
    return w;
}

BSTNode *Predecessor(BSTNode *x)
{
    if(x->left!=NULL)
    {
        return Max(x->left);
    }
    BSTNode *y=x->up;
    while(y!=NULL && x==y->left){
        x = y;
        y = y->up;
    }
    return y;
}

BSTNode *Min(BSTNode *root){
    BSTNode *x=root;
    while(x->left!=NULL)
    {
        x=x->left;
    }
    return x;
}

BSTNode *Successor(BSTNode *x)
{
    if(x->right!=NULL)
    {
        return Min(x->right);
    }
    BSTNode*y=x->up;
    while(y!=NULL && x==y->right)
    {
        x=y;
        y=y->up;
    }
    return y;
}


BSTNode* Delete(BSTNode *T,BSTNode *z)
{
    BSTNode *x,*y;
    if(z->left==NULL or z->right==NULL){ y=z;}
    else { y=Successor(z);}

    if(y->left!=NULL)
    {
        x=y->left;
    }else{
        x=y->right;
    }

    if(x!=NULL){
        x->up=y->up;
    }

    if(y->up==NULL){
        T=x;
    }
    else if(y=y->up->left){
        y->up->left=x;
    }else{
        y->up->right=x;
    }
    if(y!=z){
        z->key=y->key;
    }
    return y;
}




BSTNode * deleteNode(BSTNode * &root, BSTNode * z) {
	BSTNode * y, * x;
	if (z->left == NULL || z->right == NULL)
		{y = z;}
	else
		{y = Successor(z);}

	if (y->left != NULL)
		{x = y->left;}
	else
		{x = y->right;}

	if (x != NULL)
		{x->up = y->up;}

	if (y->up == NULL)
		{root = x;}
	else if (y == y->up->left)
		{y->up->left = x;}
	else
		{y->up->right = x;}

	if (y != z)
		{z->key = y->key;}

	return y;
}

void insertSplay(BSTNode * & root, int k) {
	BSTNode * x = new BSTNode; // Tworzymy nowy wêze³

	x->left = x->right = NULL; // Ustawiamy pola nowego wêz³a
	x->key = k;

	if (!root) {                          // Jeœli drzewo jest puste,
		x->up = NULL;            // to wêze³ x staje siê korzeniem
		root = x;
	} else {
		splay(root, k);          // W korzeniu pojawia siê nastêpnik lub poprzednik
		x->up = root;           // Bêdzie on zawsze ojcem wêz³a x
		if (k < root->key) {      // Wybieramy miejsce dla x
			x->left = root->left;
			root->left = x;       // x staje siê lewym synem korzenia
			if (x->left) x->left->up = x;
		} else {
			x->right = root->right;
			root->right = x;      // x staje siê prawym synem korzenia
			if (x->right) x->right->up = x;
		}
	}
}

int main()
{


    BSTNode *tree=new BSTNode;
    tree->right=NULL;
    tree->left=NULL;
    tree->up=NULL;
    tree->key=5;


    addNode(tree,7);
    addNode(tree,9);
    addNode(tree,1);
    addNode(tree,12);
    addNode(tree,-3);
    addNode(tree,0);
    inorder(tree);
    cout<<endl;

    cout<<"-----------------------------------------"<<endl;
    print2D(tree);
    cout<<"-----------------------------------------"<<endl;

    print2D(deleteNode(tree,Find(tree,-3)));
    return 0;
}
