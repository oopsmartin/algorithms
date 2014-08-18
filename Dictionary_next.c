#include <stdio.h>

int Bitswap(int* a, int n);
void Bitsort(int* a, int n);
void Qsort(int start,int length,int a[]);

// 1. the n bit number is considered as a char *
int Bitswap(int* a, int n)
{
	int i;
	int j;
	int cursor;
	int minCursor = -1;
	int min;// the number which is minimum among the digits which are larger than the digit 
	
	for(i=n-2;i>=0;i--){
		printf("a[i] is %d\n",a[i]);	
		min = a[i];
		cursor = i;

		for(j=i+1;j<n;j++){
			if(a[i]<a[j]){
				if(min==a[i]){
					printf("yeah\n");
					min = a[j];
					cursor = i;
					minCursor = j;
					printf("min is %d\n",min);
				}	
				if(a[j]<min){
					min = a[j];
					cursor = i;
					minCursor = j;
					printf("now min is %d\n",min);
				}
			}			
		}// for j
		if(min!=a[i]){
			printf("cursor is %d\n",cursor);
			break;
		}
	}//for i
		
	int tmp;
	tmp = a[cursor];
	a[cursor] = a[minCursor];
	a[minCursor] = tmp;
	
	for(j=0;j<n;j++)
		printf("%d ",a[j]);
	printf("\n");
	return cursor+1;
}

// 2. the rest digits should be sorted from small to big
void Bitsort(int* a, int n)
{
	int i = Bitswap(a, n);
	printf("now i is %d\n",i);
	for(;i<n;i++){
		Qsort(i,n,a);
	}
}

//start排序的起始，length是要排序序列长度
void Qsort(int start,int length,int a[])
{
	int x = a[start];
	int i,j;
	i = start;
	j = length -1;
	while(i < j)
	{
		if(x < a[j])	
			j--;
		else if(x > a[j])
		{
			a[i] = a[j];
			a[j] = x; 
			i++;
		}
		else if(x < a[i])
		{
			a[j] = a[i];
			a[i] = x;
			j--;
		}
		else
			i++;
	}
	if(start < length-1)
	{
		Qsort(start,i,a);
		Qsort(i+1,length,a);
	}
}

int main()
{
	int i;
	int a[] = {2,3,5,4,1};
	int length = sizeof(a)/sizeof(int);
	printf("length is %d\n",length);
	Bitsort(a,5);
	for(i=0;i<length;i++)
		printf("%d ",a[i]);
	//printf("\n");
	getchar();
	getchar();
	return 0;
}
