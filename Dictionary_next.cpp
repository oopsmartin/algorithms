#include <stdio.h>

int Bitswap(char* a, int n);
void Bitsort(char* a, int n);
void Qsort(int start,int length,int a[]);

// 1. the n bit number is considered as a char *
int Bitswap(char* a, int n)
{
	int i;
	int j;
	for(i=n-2;i>=0;i--){
		for(j=i+1;j<n;j++){
			if(a[i]<a[j]){
				break;
			}
		}
	}
	char tmp = a[i];
	a[i] = a[j];
	a[j] = tmp;
	return i+1;
}

// 2. the rest digits should be sorted from small to big
void Bitsort(char* a, int n)
{
	int i = Bitswap(a, n);
	printf("%d ", a[0]);
	for(;i<n;i++){
		;//Qsort()
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
	char* a = {'2','1','3'};
	Bitsort(a,3);
	getchar();
	getchar();
	return 0;
}