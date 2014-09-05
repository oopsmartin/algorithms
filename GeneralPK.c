#include <stdio.h>

int main()
{
	unsigned char i = 81;

	while(i--){
		if(i/9%3==i%9%3)
			continue;
		printf("A = %d, B = %d\n", i/9+1, i%9+1);
	}
	getchar();
	getchar();
	return 0;
}