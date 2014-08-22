#include <stdio.h>

// two digits in an array has the sum of k,then find it out
// conditions: the array is already sorted

void findSumKDigits(int* a, int n, int k)
{
	int* start = a;
	int* end = a+n-1;
	int tmp = 0;
	tmp = (*start)+(*end);
	while(tmp!=k){
		if(tmp>k){
			end--;
			tmp = (*start)+(*end);
		}
		else{
			start++;
			tmp = (*start)+(*end);
		}
	}
	printf("two digits are: %d, %d\n",*start,*end);
}

int main()
{
	int a[] = {1,2,4,7,11,15};
	int length = sizeof(a)/sizeof(int);
	findSumKDigits(a,length,15);
	getchar();
	getchar();
	return 0;
}