#include <stdio.h>

// find the more than half number by using a memorable one and a count

int findMiddle(int* a, int n)
{
	int i;
	int number = -1;
	int count = 0;

	for(i=0; i<n; i++)
	{
		if(a[i]==number)
			count++;
		else if(count==0){
			number = a[i];
			count = 1;
		}
		else
			count--;
	}
	return number;
}

int main()
{
	int a[] = {2,3,2,2,2,2,1,5,4};
	int result = findMiddle(a,9);
	printf("result is %d\n",result);
	getchar();
	getchar();
	return 0;
}