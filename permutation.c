#include <stdio.h>

// Permutate recursively

void swap(char* src, char* tgt);
void permutate(char* str, int k, int n);


void swap(char* src, char* tgt)
{
	char tmp = *src;
	*src = *tgt;
	*tgt = tmp;
}

// k represents for what the digit position is now
// n implies the length of str
// 1. swap the i'th digit with the other positions one by one
// 2. get the remaining n-1 length's array's permutation recursively
// 3. each time having done the operation we should regain the order in order that we don't miss some cases
void permutate(char* str, int k, int n)
{
	int i;
	if(k==n){
		printf("%s\n", str);		
	}
	else
	{
		for(i=k;i<n;i++){
			swap(str+k, str+i);
			permutate(str, k+1, n);
			swap(str+k, str+i);			
		}
	}
}

int main()
{
	char array[] = "abc";
	printf("array's size is %d\n",sizeof(array));
	permutate(array, 0, 3);
	getchar();
	getchar();
	return 0;
}