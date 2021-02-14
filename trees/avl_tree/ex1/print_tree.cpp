// Program to print binary tree in 2D
#include<stdio.h>
#define COUNT 10

// A binary tree node
struct AVLNode{
    AVLNode *left,*right,*up;
    int val;
    int Rank;
};

AVLNode *NULLT=new AVLNode ;
// Helper function to allocates a new node
AVLNode* newNode(int key)
{
    AVLNode* node = new AVLNode;
    node->val = key;
    node->left = node->right = NULL;
    return node;
}

// Function to print binary tree in 2D
// It does reverse inorder traversal
void print2DUtil(AVLNode *root, int space)
{
    // Base case
    if (root == NULLT)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    print2DUtil(root->right, space);

    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d %d\n", root->val,root->Rank);

    // Process left child
    print2DUtil(root->left, space);
}

// Wrapper over print2DUtil()
void print2D(AVLNode *root)
{
   // Pass initial space count as 0
   print2DUtil(root, 0);
}

