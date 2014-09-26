#include <stdio.h>
#include <stdbool.h>

// Judge a whether a sequence is a post order traversed Binary Search Tree
bool judge_BST(int* a, int length)
{
	if(length<=0)
		return true;
	int i,j;
	for(i=0;i<length-1;i++)
		if(a[i]>a[length-1])
			break;
	for(j=i;j<length-1;j++)
		if(a[j]<a[length-1])
			return false;

	bool left = false;
	bool right = false;
	left = judge_BST(a,i);
	right = judge_BST(a+i,length-1-i);
	return (left && right);
}

int main()
{
	int a[] = {4,7,6,9,11,10,5};
	int length = sizeof(a)/sizeof(int);
	if(judge_BST(a,length))
		printf("true\n");
	else
		printf("false\n");
	getchar();
	getchar();
	return 0;
}
