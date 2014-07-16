#include "stdio.h"

/**
   build binary tree by using preorder and 
   inorder traverse sequence
**/
typedef struct TreeNode
{
   int value;
   TreeNode * p_left;
   TreeNode * p_right;
};

TreeNode * buildTree(int *pre, int *mid, int n)
{
   if (n==0) return NULL;
   int root = pre[0];
   int i;
   TreeNode * node = new TreeNode();
   node->value = root;
   node->p_left = node->p_right = NULL;
   for(i=0;i<n && mid[i] != root;i++);
   int lenL = i;
   int lenR = n-i-1;
   
   if (lenL > 0) node->p_left = buildTree(&pre[1],&mid[0],lenL);
   
   if (lenR > 0) node->p_right = buildTree(&pre[lenL+1],&mid[lenL+1],lenR);
   
   return node;
}

void Inorder(TreeNode* root)
{
   if (root==NULL)
      return;
   else
      {
         Inorder(root->p_left);
         printf("%d ",root->value);
         Inorder(root->p_right);
      }
}
int main()
{
   int pre[8] = {1,2,4,7,3,5,6,8};
   int in[8] = {4,7,2,1,5,3,8,6};
   TreeNode * root = new TreeNode();

   root = buildTree(pre,in,8);
   Inorder(root);
   getchar();
   
   return 1;
}
