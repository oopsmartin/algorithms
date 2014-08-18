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

	for(i=0;i<n;i++)
	{
		// left[i]
		for(j=i;j>=0;j--)
		{
			if(height[j]>=height[i])
			{
				left[i]++;
				printf("left\n");		
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
				printf("right\n");			
			}
			else
				break;
		}
		printf("the %d'th width is %d\n",i,left[i]+right[i]-1);
	}
	return 0;
}

int main()
{
	int a[] = {2,1,5,6,2,3};
	largestRectangle(a,6);
	printf("done\n");
	getchar();
	getchar();
	return 0;
}