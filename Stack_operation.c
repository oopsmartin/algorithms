#include <stdio.h>
#include <malloc.h>

#define MAX 255
#define INCREMENT 48
// the function stores a minimum stack and accomplishes push and pop

typedef struct Stack{
	int* element;
	int top;
}Stack;

Stack* initStack()
{
	Stack* root = NULL;
	int* element = (int*)malloc(sizeof(int)*MAX);
	root = (Stack*)malloc(sizeof(Stack));
	root->element = element;
	root->top = 0;

	return root;
}

void push(Stack** root, int value)
{
	if((*root)->top <= MAX-1){
		(*root)->top++;
		*((*root)->element+(*root)->top) = value;
		printf("push top is %d\n",(*root)->top);
	}
	else{
		int i;
		int* element = (int*)malloc(sizeof(int)*((*root)->top+INCREMENT));
		Stack* newStack = (Stack*)malloc(sizeof(Stack));
		newStack->element = element;
		newStack->top = (*root)->top;
		for(i=0;i<(*root)->top;i++){
			*(newStack->element+i) = *((*root)->element+i);			
		}
		*root = newStack;
		(*root)->top++;
		*((*root)->element+(*root)->top) = value;
		
	}
}

int pop(Stack** root)
{
	int element = -1;

	if(*root != NULL){
		printf("top is %d\n", (*root)->top);
		element = *((*root)->element+(*root)->top);
		(*root)->top--;		
	}
	
	return element;
}

void push_Min(Stack** root, int value)
{
	if(*root != NULL){
		int min = *((*root)->element+(*root)->top);
		if(value < min)
			push(root, value);
		else
			push(root, min);
	}
	else
		push(root, value);
}


int main()
{
	int i;
	Stack* root = NULL;
	Stack* min = NULL;
	int a[] = {3,4,2,1};
	int sum = (sizeof(a))/sizeof(int);

	root = initStack();
	min = initStack();
	
	for(i=0; i<sum; i++)
	{
		push(&root,a[i]);
		push_Min(&min,a[i]);
	}
	printf("250\n");
	for(i=sum; i>0; i--)
	{
		printf("%d ",pop(&root));
		printf("%d ",pop(&min));
	}
	printf("\n");
	getchar();
	getchar();
	return 0;
}