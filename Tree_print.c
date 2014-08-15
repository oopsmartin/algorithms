#include <stdio.h>
#include <malloc.h>

#define MAX 255
#define INCREMENT 48

// print binary tree by layer

typedef struct BinTree{
	int element;
	struct BinTree* pLeft;
	struct BinTree* pRight;
}BinTree;

typedef struct BTQueue{
	BinTree* root;
	int start;
	int end;
}BTQueue;

BTQueue* initBTQueue(){

	BTQueue* queue = (BTQueue*)malloc(sizeof(BTQueue));
	queue->root = (BinTree*)malloc(sizeof(BinTree)*MAX);
	queue->start = queue->end = 0;
	return queue;
}

void BTenqueue(BTQueue** queue, BinTree* node)
{
	int i;

	// empty queue
	if((*queue)->end == (*queue)->start){
		(*queue)->end++;
		*((*queue)->root+(*queue)->end) = *node;
	}

	// not empty
	else{
		// out of boundary
		if((*queue)->end > MAX-1){

			BTQueue* newQueue = (BTQueue*)malloc(sizeof(BTQueue));
			newQueue->root = (BinTree*)malloc(sizeof(BinTree)*(MAX+INCREMENT));

			// align original values
			for(i=0; i<MAX+INCREMENT; i++)
				*(newQueue+i) = *(*queue+i);

			newQueue->end = (*queue)->end+1;
			*(newQueue->root+newQueue->end) = *node;

			// the newly added node has a parent
			if((newQueue->end-1)/2 >= newQueue->start){

			// the newly added node be linked to its parent
			// right child
				if(newQueue->end%2 == 0)
					(newQueue->root+(newQueue->end-1)/2)->pRight = newQueue->root+newQueue->end;
			// left child
				else
					(newQueue->root+(newQueue->end-1)/2)->pLeft = newQueue->root+newQueue->end;
			}
			*queue = newQueue;
		}
		// normal case
		else{
			(*queue)->end++;
			*((*queue)->root+(*queue)->end) = *node;

			if((*queue)->end%2 == 0)
				((*queue)->root+((*queue)->end-1)/2)->pRight = (*queue)->root+(*queue)->end;
			else
				((*queue)->root+((*queue)->end-1)/2)->pLeft = (*queue)->root+(*queue)->end;
		}
	}
}

BinTree* BTdequeue(BTQueue** queue)
{
	BinTree* node = NULL;

	if(*queue == NULL){
		return NULL;
	}
	else{
		*node = *((*queue)->root+(*queue)->start);
		(*queue)->start++;
	}
	return node;
}

BinTree* BTinit(int* a, int sum)
{
	int i;
	BTQueue* queue = initBTQueue();

	for(i=0; i<sum; i++){
		BinTree* node = (BinTree*)malloc(sizeof(BinTree));
		node->element = a[i];
		node->pLeft = node->pRight = NULL;
		BTenqueue(&queue, node);
	}
}

int main()
{
	BinTree* bt0 = (BinTree*)malloc(sizeof(BinTree));
	int a[]={8, 6, 10, 5, 7, 9, 11};
	int sum = sizeof(a)/sizeof(int);
	BTinit(a, sum);
	getchar();
	getchar();
	return 0;
}
