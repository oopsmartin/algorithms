#include <stdio.h>
#define MAX 10
/*
  A[] is an array and B[] is also an array
  B[i] = A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]
  1. design an algorithm which is o(N) in time consuming
  2. no division method is allowed
  3. space consuming is o(1)
*/
int A[MAX];
int B[MAX];

void func(int* a, int* b)
{
	int i,j;
	int temp = 1;
	b[0] = 1;
	for(i=1;i<MAX;i++){
		b[i] = b[i-1]*a[i-1];
	}
	for(j=MAX-2;j>=0;j--){
		temp = temp*a[j+1];
		b[j] = b[j]*temp;
	}
}

int main()
{
	int i;
	for(i=0;i<MAX;i++)
		A[i] = i+1;
	func(A,B);
	for(i=0;i<MAX;i++)
		printf("%d ",B[i]);
	printf("\n");
	getchar();
	getchar();
	return 0;
}

