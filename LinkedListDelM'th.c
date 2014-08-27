#include <stdio.h>
#include <malloc.h>

// delete m'th node of a linked list

typedef struct LNList{
	int value;
	struct LNList* next;
}LNList;

LNList* remian(LNList** root, int m);
void deleteM(LNList** root, int m);
void insert(LNList** root, int value);
void traverse(LNList* root);

LNList* remain(LNList** root, int m)
{
	while(sizeof((*root))/sizeof(LNList)>1){
		deleteM(root, m);
	}
	return *root;
}

void deleteM(LNList** root, int m)
{
	int i;
	LNList* listNode = NULL;
	if((*root)==NULL || m<2)
		return;
	else{
		listNode = *root;
		for(i=1;i<m-1;i++){
			listNode = listNode->next;
		}
		LNList* tmp = listNode->next;
		listNode->next = listNode->next->next;
		free(tmp);
		*root = listNode->next;
	}
}

void insert(LNList** root, int value)
{
	if(*root==NULL){
		*root = (LNList*)malloc(sizeof(LNList));
		(*root)->value = value;
		(*root)->next = (*root);
	}
	else{
		LNList* pList = *root;
		while(pList->next!=(*root)){
			pList = pList->next;			
		}
		LNList* tmp = (LNList*)malloc(sizeof(LNList));
		tmp->value = value;
		tmp->next = *root;
		pList->next = tmp;
	}
}

void traverse(LNList* root)
{
	if(root==NULL)
		return;
	else{
		LNList* pList = root;
		if(pList==root && pList->next==root){
			printf("%d\n",pList->value);
			return;
		}
		while(pList->next!=root){
			printf("%d ", pList->value);
			pList = pList->next;
		}
		printf("%d\n",pList->value);
	}
}

int main()
{
	int a[] = {1,2,3,4,5,6,7,8,9,10};
	LNList* root = NULL;
	int length = sizeof(a)/sizeof(int);
	int i;	
	
	for(i=0;i<length;i++){
		insert(&root,a[i]);
	}
	
	traverse(root);
	int remaining = (remain(&root, 4))->value;
	printf("remaining %d\n",remaining);
	getchar();
	getchar();
	return 0;
}