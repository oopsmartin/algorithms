#include <stdio.h>
#include <malloc.h>

// find two linked lists' first common node

typedef struct Node{
	int value;
	struct Node* next;
}Node;

Node* findFirstCommonNode(Node* listA, Node* listB)
{
	int i;
	int lengthA, lengthB;
	int diff = 0;
	Node* pNodeA = listA;
	Node* pNodeB = listB;
	lengthA = getLength(listA);
	lengthB = getLength(listB);

	if(lengthA > lengthB){
		diff = lengthA-lengthB;
		for(i=0;i<diff;i++){
			pNodeA = pNodeA->next;
		}
		while(pNodeA!=NULL && pNodeB!=NULL && pNodeA!=pNodeB){
			pNodeA = pNodeA->next;
			pNodeB = pNodeB->next;
		}
		return pNodeA;
	}
	else{
		diff = lengthB-lengthA;
		for(i=0;i<diff;i++){
			pNodeB = pNodeB->next;
		}
		while(pNodeA!= NULL && pNodeB!=NULL && pNodeA!=pNodeB){
			pNodeA = pNodeA->next;
			pNodeB = pNodeB->next;
		}
		return pNodeA;
	}

}

int getLength(Node* list)
{
	int count = 0;
	Node* pNode = list;
	
	if(pNode==NULL)
		return count;
	else
		while(pNode!=NULL){
			count++;
			pNode = pNode->next;
		}
	return count;
}

void insert(Node** root, int value)
{
	Node* pNode = NULL;
	Node* tmp = NULL;

	if(*root==NULL){
		(*root) = (Node*)malloc(sizeof(Node));
		(*root)->value = value;
		(*root)->next = NULL;
	}
	else{
		pNode = *root;
		tmp = (Node*)malloc(sizeof(Node));
		tmp->value = value;
		tmp->next = NULL;
		while(pNode->next){
			pNode = pNode->next;
		}
		pNode->next = tmp;
	}
}

void traverse(Node* root)
{
	Node* pNode = NULL;

	if(root==NULL)
		return ;
	else{
		pNode = root;
		while(pNode){
			printf("%d ",pNode->value);
			pNode = pNode->next;
		}
	}
}

int main()
{
	int i;
	int a[] = {2,3,4,5,6,7,8};
	int b[] = {12,3,2,1,11};
	Node* root = NULL;
	for(i=0;i<sizeof(a)/sizeof(int);i++){
		insert(&root,a[i]);
	}
	traverse(root);
	getchar();
	getchar();
	return 0;
}