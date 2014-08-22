#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

// get the tree's depth
// structure is binary tree instead of tree which is easier for insert operation

typedef struct TreeNode{
	int value;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode;

void insert(TreeNode** root, int value)
{
	if(*root==NULL){
		*root = (TreeNode*)malloc(sizeof(TreeNode));
		(*root)->value = value;
		(*root)->left = (*root)->right = NULL;
	}
	else if((*root)->value>value){
		insert(&(*root)->left, value);
	}
	else{
		insert(&(*root)->right, value);
	}
}

void traverse(TreeNode* root)
{
	if(root==NULL)
		return ;
	else{
		traverse(root->left);
		printf("%d ",root->value);
		traverse(root->right);
	}
}

int getDepth(TreeNode* root)
{	
	int depth = 0;
	if(root==NULL)
		return 0;
	else{
		depth = (getDepth(root->left)>getDepth(root->right))?
			getDepth(root->left):
			getDepth(root->right);
		++depth;
	}
	return depth;
}

bool IsAVL(TreeNode* root)
{
	bool flag = false;
	if(root==NULL){
		flag = true;		
	}
	else{		
		int diff = 0;
		diff = (getDepth(root->left)>getDepth(root->right))?
			getDepth(root->left)-getDepth(root->right):
			getDepth(root->right)-getDepth(root->left);		
		if(diff>1)
			flag = false;
		else
			flag = true;		
		flag &= IsAVL(root->left) & IsAVL(root->right);		
	}
	return flag;
}

int main()
{
	int a[] = {4,2,7,19,18,5,1,3};
	int length = sizeof(a)/sizeof(int);
	int i;
	TreeNode* root = NULL;
	int depth;
	for(i=0;i<length;i++){
		insert(&root, a[i]);
	}
	traverse(root);
	depth = getDepth(root);
	printf("depth is %d\n",depth);
	if(IsAVL(root))
		printf("AVL\n");
	else
		printf("not AVL\n");
	
	getchar();
	getchar();
	return 0;
}