#include <stdio.h>
#include <malloc.h>

// this function gets the mirror of a tree(subtree will recursively reversed)

typedef struct BinaryTree{
	int value;
	struct BinaryTree* pLeft;
	struct BinaryTree* pRight;
}BinaryTree;

void getMirror(BinaryTree* root)
{
	if(root == NULL)
		return;

	BinaryTree* tmp = root->pLeft;
	root->pLeft = root->pRight;
	root->pRight = tmp;

	getMirror(root->pLeft);

	getMirror(root->pRight);
}

BinaryTree* initTreeA()
{	

	BinaryTree* node1_right = (BinaryTree*)malloc(sizeof(BinaryTree));
	node1_right->value = 7;
	node1_right->pRight = node1_right->pLeft = NULL;
	

	BinaryTree* node3_right = (BinaryTree*)malloc(sizeof(BinaryTree));
	node3_right->value = 7;
	node3_right->pRight = node3_right->pLeft = NULL;

	BinaryTree* node3_left = (BinaryTree*)malloc(sizeof(BinaryTree));
	node3_left->value = 4;
	node3_left->pRight = node3_left->pLeft = NULL;

	BinaryTree* node2_right = (BinaryTree*)malloc(sizeof(BinaryTree));
	node2_right->value = 2;
	node2_right->pRight = node3_right;
	node2_right->pLeft = node3_left;

	BinaryTree* node2_left = (BinaryTree*)malloc(sizeof(BinaryTree));
	node2_left->value = 9;
	node2_left->pRight = node2_left->pLeft = NULL;

	BinaryTree* node1_left = (BinaryTree*)malloc(sizeof(BinaryTree));
	node1_left->value = 8;
	node1_left->pRight = node2_right;
	node1_left->pLeft = node2_left;

	BinaryTree* root = (BinaryTree*)malloc(sizeof(BinaryTree));
	root->value = 8;
	root->pRight = node1_right;
	root->pLeft = node1_left;

	return root;

}