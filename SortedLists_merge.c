#include <stdio.h>
#include <malloc.h>

// merge two sorted lists into one list

typedef struct Node
{
	int value;
	struct Node* pNext;
}Node;

Node* merge(Node* listA, Node* listB)
{
	Node* targetList = NULL;
	Node* ptr = NULL;
	Node* ptrA = listA;
	Node* ptrB = listB;

	if(listA == NULL)
		return listB;
	if(listB == NULL)
		return listA;

	targetList = listA==NULL?listB:
	(listB==NULL?listA:
		(listA->value<listB->value?listA:listB));
	ptr = targetList;
	ptrA = ptr==listA?(listA==NULL?NULL:listA->pNext):listA;
	ptrB = ptr==listB?(listB==NULL?NULL:listB->pNext):listB;

	while(ptrA != NULL || ptrB != NULL)
	{

		if(ptrA == NULL){
			ptr->pNext = ptrB;
			return targetList;
		}
		if(ptrB == NULL){
			ptr->pNext = ptrA;
			return targetList;
		}

		if(ptrA->value < ptrB->value){
			printf("<\n");
			printf("a is %d\n",ptrA->value);			
			ptr->pNext = ptrA;
			ptrA = ptrA->pNext;
			ptr = ptr->pNext;
						
		}
		else{
			printf(">\n");			
			printf("b is %d\n",ptrB->value);
			ptr->pNext = ptrB;
			ptrB = ptrB->pNext;
			ptr = ptr->pNext;
			
		}
	}

	return targetList;
}

void insert(Node** root, int value)
{
	Node* ptr = *root;

	if(*root == NULL){
		(*root) = (Node*)malloc(sizeof(Node));
		(*root)->value = value;
		(*root)->pNext = NULL;
		printf("if\n");
	}
	else{
		while(ptr->pNext != NULL){
			ptr = ptr->pNext;
		}
		Node* tmp = (Node*)malloc(sizeof(Node));
		tmp->value = value;
		tmp->pNext = NULL;
		ptr->pNext = tmp;
		printf("else\n");
	}
}

void traverse(Node* root)
{
	Node* ptr = root;

	while(ptr != NULL){
		printf("%d ",ptr->value);
		ptr = ptr->pNext;
	}
	printf("\n");
}

int main()
{
	Node* listA = NULL;
	Node* listB = NULL;
	Node* root = NULL;
	int count;
	int i;
	//int a[] = {1,3,5,7,9};
	int* a = NULL;
	int b[] = {2,4,6,8,10};
	
	if(a != NULL){
		count = (sizeof(a)/sizeof(int));
		for(i=0;i<count;i++){
			insert(&listA,a[i]);
		}
		traverse(listA);
	}

	if(b != NULL){

		count = (sizeof(b)/sizeof(int));
		for(i=0;i<count;i++){
			insert(&listB,b[i]);
		}
		traverse(listB);
	}
	
	root = merge(listA,listB);
	traverse(root);

	getchar();
	getchar();

}