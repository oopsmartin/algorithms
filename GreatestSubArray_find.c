#include <stdio.h>

// find the sub array which has the greatest sum

int findGreatestSubArray(int* a, int n)
{
	int i;
	int cursor = 0;
	int max = 0;
	int currentSum = 0;
	for(i=0; i<n; i++)
	{
		if(currentSum<0){
			currentSum = a[i];
		}
		else
			currentSum += a[i];

		if(currentSum > max)
			max = currentSum;
	}
	return max;
}

int main()
{
	int a[] = {1, -2, 3, 10, -4, 7, 2, -5};
	int max = findGreatestSubArray(a, sizeof(a)/sizeof(int));
	printf("the max is %d\n", max);
	getchar();
	getchar();	
	return 0;
}