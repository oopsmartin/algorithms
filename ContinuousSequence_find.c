#include <stdio.h>

// find the sub array in an continuous array which has the sum of k

void findContinuousSequence(int* a, int n, int k)
{
	int i;
	int* start = a;
	int* end = a+1;
	int tmp = 0;
	for(i=start-a;i<=end-a;i++){
		tmp += a[i];
	}	
	printf("tmp now is %d\n",tmp);
	while(end<a+n && start<=end){
		while(tmp!=k && end<a+n && start<=end){
			if(tmp<k){
				end++;
				tmp += *end;
			}
			else{			
				tmp -= *start;
				start++;
			}
		}
		printf("here i am\n");
		if(tmp==k){
			for(i=start-a;i<=end-a;i++)
				printf("%d ",a[i]);
			printf("\n");
		}
		end++;
		tmp += *end;
	}
}

int main()
{
	int a[] = {1,2,3,4,5,6,7,8};
	int length = sizeof(a)/sizeof(int);
	findContinuousSequence(a,length,15);
	getchar();
	getchar();
	return 0;
}