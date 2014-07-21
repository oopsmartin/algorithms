#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

// this function judges whether treeA is subtree of treeB or the opposite

typedef struct TreeNode{
	int value;
	struct TreeNode* pLeft;
	struct TreeNode* pRight;
}TreeNode;

bool ASubOfB(TreeNode* treeA, TreeNode* treeB)
{
	
	if(treeB==NULL)
		return true;
	if(treeA==NULL)
		return false;
	if(treeA->value != treeB->value)
		return false;

	if(ASubOfB(treeA->pLeft,treeB->pLeft) &&
			ASubOfB(treeA->pRight,treeB->pRight))
		return true;
	else
		return false;

}

bool hasSubTree(TreeNode* treeA, TreeNode* treeB)
{
	bool result = false;

	if(treeA != NULL && treeB != NULL){
		if(treeA->value == treeB->value)
			result = ASubOfB(treeA,treeB);
		if(!result)
			result = hasSubTree(treeA->pLeft,treeB);
		if(!result)
			result = hasSubTree(treeA->pRight,treeB);
	}
	return result;
}



TreeNode* initTreeA()
{	

	TreeNode* node1_right = (TreeNode*)malloc(sizeof(TreeNode));
	node1_right->value = 7;
	node1_right->pRight = node1_right->pLeft = NULL;
	

	TreeNode* node3_right = (TreeNode*)malloc(sizeof(TreeNode));
	node3_right->value = 7;
	node3_right->pRight = node3_right->pLeft = NULL;

	TreeNode* node3_left = (TreeNode*)malloc(sizeof(TreeNode));
	node3_left->value = 4;
	node3_left->pRight = node3_left->pLeft = NULL;

	TreeNode* node2_right = (TreeNode*)malloc(sizeof(TreeNode));
	node2_right->value = 2;
	node2_right->pRight = node3_right;
	node2_right->pLeft = node3_left;

	TreeNode* node2_left = (TreeNode*)malloc(sizeof(TreeNode));
	node2_left->value = 9;
	node2_left->pRight = node2_left->pLeft = NULL;

	TreeNode* node1_left = (TreeNode*)malloc(sizeof(TreeNode));
	node1_left->value = 8;
	node1_left->pRight = node2_right;
	node1_left->pLeft = node2_left;

	TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
	root->value = 8;
	root->pRight = node1_right;
	root->pLeft = node1_left;

	return root;

}

TreeNode* initTreeB()
{
	TreeNode* node1_right = (TreeNode*)malloc(sizeof(TreeNode));
	node1_right->value = 8;
	node1_right->pRight = node1_right->pLeft = NULL;

	TreeNode* node1_left = (TreeNode*)malloc(sizeof(TreeNode));
	node1_left->value = 8;
	node1_left->pRight = node1_left->pLeft = NULL;

	TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
	root->value = 8;
	root->pRight = node1_right;
	root->pLeft = node1_left;

	return root;
}

int main()
{
	TreeNode* treeA = initTreeA();
	TreeNode* treeB = initTreeB();

	if(hasSubTree(treeA,treeB))
		printf("true\n");
	else
		printf("false\n");

	getchar();
	getchar();

	return 0;
}