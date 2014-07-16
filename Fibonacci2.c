#include <stdio.h>

// non-recursive implementation of fibonacci
int Fibonacci(int n)
{
	int result[2] = {0, 1};
	if(n < 2)
		return result[n];

	int fibOne = 1;
	int fibTwo = 0;
	int fibN = 0;

	int i;

	for(i=2;i<=n;i++)
	{
		fibN = fibOne+fibTwo;
		fibTwo = fibOne;
		fibOne = fibN;
	}
	return fibN;
}

int main()
{
	int n;
	while(scanf("%d",&n)>=0)
		printf("The Fibonacci number is %d\n", Fibonacci(n));
	return 0;
}