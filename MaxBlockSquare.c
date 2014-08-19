#include <stdio.h>

int left[1024] = {0};
int right[1024] = {0};

// square = height[i]*width[i]
// height[i] is the i'th element's height
// width[i] is the max width of i
// The problem can be divided into two sub problems
// width[i] = left[i]+right[i]-1

int largestRectangle(int* height, int n)
{
	int i,j,k;
	int max = -1;
	int auxiliaryArray[1024] = {0};

	for(i=0;i<n;i++)
	{
		// left[i]
		for(j=i;j>=0;j--)
		{
			if(height[j]>=height[i])
			{
				left[i]++;					
			}
			else
				break;
		}
		// right[i]
		for(k=i;k<n;k++)
		{
			if(height[k]>=height[i])
			{
				right[i]++;					
			}
			else
				break;
		}
		printf("the %d'th width is %d\n",i,left[i]+right[i]-1);
		auxiliaryArray[i] = left[i]+right[i]-1;
	}
	max = maxOfArray(auxiliaryArray,n);
	return max;
}

int maxOfArray(int* a, int n)
{
	if(a==NULL || n<=0)
		return NULL;
	int i;
	int max = a[0];
	for(i=0;i<n;i++)
	{
		if(a[i]>max)
			max = a[i];
	}
	return max;
}

int main()
{
	int a[] = {2,1,5,6,2,3};
	int max;
	max = largestRectangle(a,6);
	printf("done\n");
	printf("max is %d\n",max);
	getchar();
	getchar();
	return 0;
}