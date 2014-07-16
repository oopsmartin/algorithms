#include <stdio.h>


typedef struct Node
{
	int value;
	struct Node* pLeft;
	struct Node* pRight;
}Node;

// insert node
Node* insertNode(Node* root, int value)
{
	if(root == NULL)
	{
		root = (Node *)malloc(sizeof(Node));
		root->value = value;
		root->pRight = root->pLeft = NULL;
	}
	else
	{
		if(value > root->value)
		{
			root->pRight = insertNode(root->pRight, value);
		}
		else if(value < root->value)
		{
			root->pLeft = insertNode(root->pLeft, value);
		}
	}
	return root;
}

// get the node's parent
Node* getParent(Node* root, Node* node)
{
	Node* parent = NULL;

	while(root != NULL)
	{
		if(root->value > node->value)
		{
			parent = root;
			root = root->pLeft;
		}
		else if(root->value < node->value)
		{
			parent = root;
			root = root->pRight;
		}
		else
			break;
	}
	return parent;
}

// get the minimal node
Node* getMin(Node *root)
{
	Node* res = root;
	while(root!=NULL)
	{
		res = root;
		root = root->pLeft;
	}
	return res;
}

// delete node
void deleteNode(Node* root, Node* node)
{
	if(root == NULL)
		return;

	// the node has 2 children
	if((node->pLeft != NULL) && (node->pRight != NULL))
	{
		// get the minimal node among the right children
		Node* min = getMin(node->pRight);
		node->value = min->value;
		deleteNode(node->pRight, min);
	}

	// the node has 0 or 1 child
	else
	{
		// get the node's father
		Node* parent = getParent(root, node);
		// get the child node
		Node* child = NULL;
		if(node->pLeft != NULL)
			child = node->pLeft;
		else if(node->pRight != NULL)
			child = node->pRight;

		// change the father's pointer field
		if(parent->value < node->value)
			parent->pRight = child;
		else if(parent->value > node->value)
			parent->pLeft = child;
	}
}

// middle traverse the tree
void midTraverse(Node* root)
{
	if(root == NULL)
		return;
	else
	{
		midTraverse(root->pLeft);
		printf("%d ",root->value);
		midTraverse(root->pRight);
	}
}

// get the node whose value is ...
Node* getNode(Node* root, int value)
{
	Node* target = NULL;

	if(root != NULL)
	{
		if(value > root->value)
		{
			target = getNode(root->pRight, value);
		}
		else if(value < root->value)
		{
			target = getNode(root->pLeft, value);
		}
		else
			target = root;
	}

	return target;
}

int main()
{
	int i;
	Node* root = NULL;
	int arr[] = {10,4,16,8,1,12,15,5,23,17};
	int size = sizeof(arr)/sizeof(*arr);
	for(i=0;i<size;i++)
	{
		root = insertNode(root, arr[i]);
	}
	midTraverse(root);
	printf("\n");

	Node* pNode = getNode(root,12);
	
	deleteNode(root, pNode);
	midTraverse(root);
	
	getchar();
	getchar();
	return 0;
}