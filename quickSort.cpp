#include <stdio.h>
#define N 10   //������������Ԫ�ظ���
int Qsort(int start,int length,int a[])//start�������ʼ��length��Ҫ�������г���
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
	int a[N] = {0};
	int i;
        for(i = 0;i < N;i++)
		scanf("%d",&a[i]);
	Qsort(0,N,a);
	for(i = 0;i < N;i++)
		printf("%d ",a[i]);
	getchar();
	getchar();
	return 1;
}
