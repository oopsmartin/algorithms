#include "stdio.h"
#include "malloc.h"
#include "stdbool.h"

// This program will verify whether an array is 
// a back-ordered traverse of a binary search tree

typedef struct BinTree{
	int value;
	struct BinTree* pLeft;
	struct BinTree* pRight;
}BinTree;

/*
void insert(BinTree** root, int value)
{
	if((*root)==NULL){
		*root = (BinTree*)malloc(sizeof(BinTree));
		(*root)->value = value;
		(*root)->pLeft = (*root)->pRight = NULL;
	}
	else{
		if((*root)->value > value)
			insert(&((*root)->pLeft), value);
		else
			insert(&((*root)->pRight), value);
	}
}

void traverse(BinTree* root)
{
	if(root != NULL){
		traverse(root->pLeft);
		printf("%d ", root->value);
		traverse(root->pRight);
	}
	else
		return;
}
*/

bool verifyBST(int* a, int length)
{
	int i,j;
	if(a == NULL || length <= 0)
		return false;

	for(i=0;i<length-1;i++)
		if(a[i]>a[length-1])
			break;
	for(j=i;j<length-1;j++)
		if(a[j]<a[length-1])
			return false;

	// judge whether the left tree is BST
	bool left = true;
	if(i>0)
		left = verifyBST(a,i);
	// judge whether the right tree is BST
	bool right = true;	
	if(i < length-1)
	{
		right = verifyBST(a+i, length-i-1);
	}

	return (left && right);

}

int main()
{
	int a[] = {5,7,6,9,11,8,10};
	BinTree* root = NULL;
	int size;
	int i;
	size = sizeof(a)/sizeof(int);
	for(i=0;i<size;i++){
		insert(&root,a[i]);
	}
	traverse(root);
	if(verifyBST(a,size))
		printf("yes\n");
	else
		printf("no\n");
	getchar();
	getchar();
	return 0;
}