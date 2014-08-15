#include "stdio.h"
#include "BinaryTree.h"

void convertNode(BinTree* root, BinTree** lastNodeInList);
BinTree* convert(BinTree* root);
void traverseDul(BinTree* root);

BinTree* convert(BinTree* root)
{
	BinTree* lastNodeInList = NULL;
	convertNode(root, &lastNodeInList);
	BinTree* pHeadOfList = lastNodeInList;
	while(pHeadOfList!=NULL && pHeadOfList->pLeft!=NULL){
		pHeadOfList = pHeadOfList->pLeft;
	}
	return pHeadOfList;
}

void convertNode(BinTree* root, BinTree** lastNodeInList)
{
	// inOrder traverse

	if(root==NULL)
		return;
	BinTree* pCurrent = root;
	if(pCurrent->pLeft!=NULL)
		convertNode(pCurrent->pLeft, lastNodeInList);
	pCurrent->pLeft = *lastNodeInList;
	if(*lastNodeInList!=NULL)
		(*lastNodeInList)->pRight = pCurrent;
	*lastNodeInList = pCurrent;
	if(pCurrent->pRight!=NULL)
		convertNode(pCurrent->pRight, lastNodeInList);
}

// the both-way node list is not recyclable
void traverseDul(BinTree* root)
{	
	BinTree* pNode = root;
	if(pNode==NULL)
		return;
	while(pNode->pRight!=NULL){
		printf("%d ", pNode->value);
		pNode = pNode->pRight;
	}
	printf("%d ",pNode->value);

}

int main()
{	
	BinTree* root = NULL;
	BinTree* pNode = NULL;
	int a[] = {10,14,16,12,6,4,8};
	int size = sizeof(a)/sizeof(int);
	int i;
	for(i=0;i<size;i++)
		insert(&root, a[i]);
	traverse(root);
	printf("\n");
	traverseDul(root);
	printf("\n");
	pNode = convert(root);
	traverseDul(pNode);
	getchar();
	getchar();
	return 0;
}
