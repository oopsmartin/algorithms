#include <stdio.h>
#include <malloc.h>

typedef struct tagNode
{
	int value;
	struct tagNode* pLink;
}Node;

Node* reverse(Node** pHead)
{
	Node* reversedHead = NULL;
	// point to the current node's previous
	Node* pPrev = NULL;
	// point to the current node
	Node* pNode = *pHead;
	// point to the current node's next
	Node* pNext = NULL;

	if(pNode == NULL)
		return;
	else
	{
		while(pNode != NULL)
		{
			pNext = pNode->pLink;
			pNode->pLink = pPrev;

			if(pNext == NULL)			
				reversedHead = pNode;
			
			pPrev = pNode;
			pNode = pNext;
		}
	}
	return reversedHead;
}

void insert(Node** head, int value)
{
	Node* ptr = NULL;
	Node* node = NULL;

	if(*head == NULL)
	{
		*head = (Node*)malloc(sizeof(Node));
		(*head)->value = value;
		(*head)->pLink = NULL;
		printf("if case\n");
	}
	else
	{
		ptr = *head;
		while(ptr->pLink != NULL)
		{
			ptr = ptr->pLink;
		}
		node = (Node*)malloc(sizeof(Node));
		node->value = value;
		node->pLink = NULL;
		ptr->pLink = node;
		printf("else case\n");
	}

}

void traverse(Node* head)
{
	Node* ptr = head;

	if(head == NULL)
		return;
	else
	{
		while(ptr != NULL)
		{
			printf("%d ",ptr->value);
			ptr = ptr->pLink;
		}
		printf("\n");
	}
}

int main()
{
	int i;
	Node* head = NULL;
	Node* newHead = NULL;
	int a[] = {2,4,8,31,12,84,33,11,23,40};
	int sum = sizeof(a)/sizeof(int);
	for(i=0;i<sum;i++)
	{
		insert(&head,a[i]);
	}
	traverse(head);
	newHead = reverse(&head);
	traverse(newHead);
	getchar();
	getchar();
	return 1;
}