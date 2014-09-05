#include <stdio.h>

// get the greatest common divide of two digits

int gcd(int x, int y)
{
	if(x<y)
		return gcd(y,x);
	if(y==0)
		return x;
	else
		return gcd(x-y,y);
}

int main()
{
	int x,y;
	scanf("%d",&x);
	scanf("%d",&y);
	int result = gcd(x,y);
	printf("the greatest common divide of the two is %d\n",result);
	getchar();
	getchar();
	return 0;
}