#include "stdio.h"
#include "BinaryTree.h"
#include "malloc.h"

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