#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include "BinaryTree.h"
using namespace std;

// Find the path in which all elements added to a specific one

void findPath1(BinTree* root, int sum, std::vector<int>& path, int& currentSum)
{
	currentSum += root->value;
	path.push_back(root->value);
	bool isLeaf = root->pLeft==NULL && root->pRight==NULL;
	if(currentSum==sum && isLeaf)
	{
		printf("A path is found:");
		std::vector<int>::iterator iter = path.begin();
		for(;iter!=path.end();++iter)
			printf("%d\t",*iter);

		printf("\n");
	}

	// if it is not leaf, then traverse its childs
	if(root->pLeft!=NULL)
		findPath1(root->pLeft, sum, path, currentSum);
	if(root->pRight!=NULL)
		findPath1(root->pRight, sum, path, currentSum);

	// delete the node before returning
	currentSum -= root->value;
	path.pop_back();
}

void findPath(BinTree* root, int sum)
{
	if(root == NULL)
		return;
	std::vector<int> path;
	int currentSum = 0;
	findPath1(root, sum, path, currentSum);
}

int main()
{
	int i;
	BinTree* root = NULL;
	int a[] = {10,12,5,4,7};
	int size = sizeof(a)/sizeof(int);
	for(i=0;i<size;i++)
		insert(&root,a[i]);
	traverse(root);
	printf("\n");
	findPath(root,22);
	getchar();
	getchar();
	return 0;
}

