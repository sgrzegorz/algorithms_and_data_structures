#include <iostream>
#include "x.cpp"



using namespace std;

struct BSTNode{
    BSTNode*right;
    BSTNode*left;
    BSTNode*up;
    int key;
};

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

/*
void *addNode(BSTNode *&tree,BSTNode *w)
{

    if(tree=NULL)
    {
        tree=w;
    }else{
        BSTNode *x=tree;
        while(true){
            if(w->key<=x->key)
            {
                if(x->left==NULL)
                {
                    x->left=w;
                    w->up=x;
                    break;
                }else{
                    x=x->left;
                }

            }else{
                if(x->right==NULL)
                {
                    x->right=w;
                    w->up=x;
                    break;
                }else{
                    x=x->right;
                }


            }
        }
    }
}
*/
void inorder(BSTNode *tree)
{
    if(tree!=NULL)
    {
        inorder(tree->left);
        cout<<tree->key<<" ";
        inorder(tree->right);
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
    return 0;
}
