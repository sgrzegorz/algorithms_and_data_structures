// Program to print binary tree in 2D
#include<stdio.h>
#define COUNT 10

// A binary tree node
struct RBNode{
    RBNode *left,*right,*up;
    int val;
    char colour;
};

RBNode *NULLT=new RBNode ;
// Helper function to allocates a new node
RBNode* newNode(int key)
{
    RBNode* node = new RBNode;
    node->val = key;
    node->left = node->right = NULL;
    return node;
}

// Function to print binary tree in 2D
// It does reverse inorder traversal
void print2DUtil(RBNode *root, int space)
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
    printf("%d%c\n", root->val,root->colour);

    // Process left child
    print2DUtil(root->left, space);
}

// Wrapper over print2DUtil()
void print2D(RBNode *root)
{
   // Pass initial space count as 0
   print2DUtil(root, 0);
}

