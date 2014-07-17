#include <stdio.h>
#include <malloc.h>

// find the k'th node in a linked list limited by traversing once

typedef struct tagNode
{
	int value;
	struct tagNode* pNext;
}Node;

Node* find(Node* root, int k)
{
	int i;
	Node* p1 = NULL;
	Node* p2 = NULL;

	p1 = root;

	for(i=0;i<k;i++)
	{
		if(p1 != NULL)
			p1 = p1->pNext;
		else
			return NULL;
	}

	p2 = root;

	while(p1 != NULL)
	{
		p2 = p2->pNext;
		p1 = p1->pNext;
	}
	return p2;
}

void insert(Node** root, int value)
{
	Node* tmp = *root;
	Node* node = NULL;

	if((*root) == NULL)
	{
		(*root) = (Node*)malloc(sizeof(Node));
		(*root)->value = value;
		(*root)->pNext = NULL;
	}
	else
	{
		while(tmp->pNext != NULL)
		{
			tmp = tmp->pNext;
		}

		node = (Node*)malloc(sizeof(Node));
		node->value = value;
		node->pNext = NULL;
		tmp->pNext = node;		
		printf("linked\n");
	}
	
}

void traverse(Node* root)
{
	
	while(root != NULL)
	{
		printf("%d ",root->value);
		root = root->pNext;
	}
	
}

int main()
{
	int i;
	Node* root = NULL;
	Node* node = NULL;
	int arr[] = {1,2,3,4,5,6,7,8,9,10};
	
	for(i=0;i<10;i++)
	{
		insert(&root, arr[i]);
		printf("added\n");
	}
	traverse(root);
	node = find(root,3);
	printf("the target value is %d\n",node->value);
	getchar();
	getchar();
}