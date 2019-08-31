#include <iostream>

using namespace std;

struct BSTNode {
    BSTNode * up;
    BSTNode * left;
    BSTNode * right;
    int key
};

void inorder(BSTNode * v)
{
    if(v!=NULL){
        inorder(v->left);
        cout<< v->key <<" ";
        inorder(v->right);
    }
}

void addNode(BSTNode *&tree,BSTNode *newNode){
    if(tree == NULL){
        tree=newNode;
    }else{
        BSTNode *cp=tree;
        while(true){
            if(newNode->key <= cp->key){
                if(cp->left == NULL)
                    break;
                else
                    cp=cp->left;
            }else{
                if(cp->right ==NULL)
                    break;
                else
                    cp=cp->right;
            }
        }
        newNode->up=cp;
        if(newNode->key <=cp->key)
            cp->left=newNode;
        else
            cp->right=Newnode;
    }
}


        }

    }





}


BSTNode * treeSuccesor(BSTNode *v){
    if(v->right!=NULL)
        return treeMin(v->right);
    BSTNode *y= v->up;
    while(y!=NULL && v== y->right){
        v=y;
        y=y->up;
    }
    return y;
}

BSTNode *treeSuccessor(BSTNode *x){
    if(v->right!=NULL)
        return treeMin(x->right);

    BSTNode *y=x->up;
    while(y!=NULL && x==y->right)
    {
        x=y;
        y=y->up;
    }
    return y;
}

BSTNode *treePredecessor(BSTNode *x)
{
    if(x->left !=NULL)
        return treeMax(x->left);
    BSTNode *y=x->up;
    while(y!=NULL && x==y->left){
        x=y;
        y=y->up;
    }
    return y;
}

BSTNode * Predecessor(BSTNode *x)
{
    if(x->left!=NULL)
        return treeMax(x->left);
    BSTNode * y=x->up;
    while(y!=NULL && x == y->left){
        x=y;
        y=y->up;
    }
    return y;
}

struct AVLNode{
    AVLNode *up;
    AVLNode *left;
    AVLNode *right;
    int key;
    int bf;
};

struct SLNode {
    int val;
    SLNode ** next;
};

struct SkipList{
    SLNode *head;
    int height;
};

int getHeight(int max_h,double p=1/2){
    int h=1;
    while(h<max_h && ran)
}

SLNode * find(Skiplist *skip,int key)
{


}


void member(skiplist &s,int key)
{
    slnode*v;
    slnode *prev[20];
    v=s.first;
    for(i=19;i>=0;i--)
    {
        while(v->next[i]->value<key)v=v->next[i];
        prev[i]=v;
    }
    v=v->next[0];

    if(v->value===key) return;

    int h=level();
    slnode*n=new slnode;
    s.tmplvl=max


}


void insert(SkipList *skip,int key){
    SLNode *it=skip->head;
    int getHeight(it->height);
    SLNode* newNode=new SLNode;
    newNode->val=key;
    newNode->next=new SLNode *[h];

    for(int i=skip->height-1;i>=0;i--)
    {
        while(it->next[i]!=NULL && it->next[i]->val<key
              {
                  it=it->next
              })
        if(i<h){
            newNode->next[i]=it->next[i];
            it->next[i]=newNode;
        }
    }
}

void insert(Skiplist *skip,int key){
    SLNode *it=skip->head;
    SLNode *c;
    for(int i=skip->height-1;i>=0;i--){
        while(it->next[i]!=NULL && it->next[i]<key
              it-it->next[i];
        if(it->next[i]->val==key){
            c=it->next;
            it->next[i]=c[i]
        }
    }
    if(it->next[0]->val!=key)return;
    delete c[0];

}

struct mydata{
    char *name,*surname;
    mydata *next;
    mydata{
        this->next=NULL'
    }
};

struct hashTable{
    mydata **T;
    int size;
};

typedef unsigned int hashType;
struct Data{
    char *firstName;
    char *lastName;
    int age;
    hashType hash;
};

hashType getHash(Data *data){
    int waga=65599,sum=0;
    for(int i=0;data->firstName[i]!=0;i++)
        sum=sum*waga+data->firstName[i];-
    for(int i=0;data->lastName[i]!=0;i++)
    {
        sum=sum*waga+data->lastName[i];
    }
    return sum*waga+data->age;
}

struct mydata{
    char *name ,*surname;
    mydata(){
        this->next=NULL;
    }
};

struct hashTable{
    mydata **T;
    int size;
};


void insert(hashTable *hTab,mydata *dat){
    hashType h= getHash(dat);
    hashType start=h%hTab->size;

    dat->next=hTab->T[start];
    hTab->T[start]=dat;
}

void insert(hashTable *hTab,mydata *dat){
    hashType h=getHash(dat);
    hashType start = h%hTab->size;

    dat->next=hTab->T[start];
    hTab->T[start]=dat;
}

void insert(hashTable *hTab,mydata *dat)
{
    hashType h=getHash(dat);
    hashType start= h%hTab->size;

    dat->next= hTab->T[start];
    hTab->T[start]=dat;

}

struct hashTable{
    mydata **T;
    int size;
};

void insert(hashTable *hTab,mydata *dat){
    hashType h=getHash(dat);
    hashType start= h%hTab->size;

    dat->next-hTab->T[start];
    hTab->T[start]=dat;
}

bool search(hashTable *htab,mydata *dat){
    hashType

}

int hashInsert(T,k){
    i=0;
    while(i!=m){
        j=h(k,i);
        if(T[j]==NULL){
            T[j]=k;
            return j;
        }
        i++;
    }
    return -1;
}

int hashSearch(T,k){
    int i=0;
    while(i!=m){
        j=h(k,i);
        if(T[j]==NULL) break;
        if(T[j]==k) return j;
        i++;
    }
    return -1;
}

struct BSTNode {
    BSTNode *up;
    BSTNode *left;
    BSTNode *right;
    int key;
};

void inorder(BSTNode *v)
{
    if(v!=NULL)
    {
        inorder(v->left);
        cout<< v->key<<" ";
        inorder(v->right);
    }
}

BSTNode *find(BSTNode *root,int key)
{
    if(root==NULL) return NULL;
    if(root->key == key) return root;
    else if(key<root->key)
        return find(root->left,key)
    else
        return find(root->right,key);
}

void addNode(BSTNode *&tree, BSTNode*new Node){
    if(tree==NULL){
        tree=newNode;
    }else{
        BSTNode *cp=tree;
        while(true){
            if(newNode->key <= cp->key){
                if(cp->left == NULL)
                    break;
                else
                    cp=cp->left;
            }else{
                if(cp->right == NULL)
                    break;
                else
                    cp=cp->right;
            }
        }

        newNode->up=cp;
        if(newNode->key<=cp->key)
            cp->left=newNode;
        else
            cp->right=newNode;
    }
}

BSTNode *TreeSuccessor(BSTNode *x){
    if(x->right != NULL)
        return treeMin(x->right);

    BSTNode *y=x->up;
    while(y!=NULL && x==y->right){
        x=y;
        y=y->up;
    }
    return y;
}


BSTNode *treePredecessor(BSTNode *x)
{
    if(x->left!=NULL)
        return treeMax(x->left);
    BSTNode*y=x->up;
    while(y!=NULL && x==y->left){
        x=y;
        y=y->up;
    }
    return y;
}

bool search(hashTable *hTab,mydata *dat){
    hashType h=getHash(dat);
    hashType start=h%hTab->size;
    mydata*tmp=hTab->T[start];
    while(tmp!=NULL){
        if(cmp(tmp,dat))
        {
            return true;
        }
        tmp=tmp->next;
    }
    return false;

}

BSTNode * deleteNode(BSTNode *&root,BSTNode *z)
{
    BSTNode *y,*x;
    if(z->left==NULL || z->right==NULL)
        y=z;
}

bool search(hastTable *hTab,mydata *dat){
    hashType h=getHash(dat);
    hashType start=h%hTab->size;

    mydata *tmp=hTab->T[start];
    while(tmp!=NULL){
        if(cmp())
    }
}
BSTNode * deleteNode(BSTNode *&root,BSTNode *z){
    BSTNode *y,*x;


}


int main()
{
    BSTNode Tree;
    Tree->
    cout << "Hello world!" << endl;
    return 0;
}
