#include "DulNode.h"
#include "malloc.h"

// new data will be inserted in the rear
void insert(DulNode** root, int value)
{
	if(*root==NULL){
		*root = (DulNode*)malloc(sizeof(DulNode));
		(*root)->value = value;
		(*root)->prev = NULL;
		(*root)->next = NULL;
	}
	else{
		DulNode* pNode = (DulNode*)malloc(sizeof(DulNode));
		pNode->value = value;
		pNode->prev = pNode->next = NULL;
		(*root)->prev->next = pNode;
		pNode->prev = (*root)->prev;
		pNode->next = (*root);
		(*root)->prev = pNode;
	}

}

void traverse(DulNode* root)
{
	DulNode* pNode = root;
	if(pNode==NULL)
		return;
	else{
		while(pNode->next!=root){
			printf("%d\n", pNode->value);
			pNode = pNode->next;
		}
	}
}