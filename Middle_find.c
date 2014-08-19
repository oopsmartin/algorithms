#include <stdio.h>

// this function will find the middle most appeared number in an array

int partition(int a[], int start, int end)
{
	int position = 0;
	int x = a[start];
	int i = start;
	int j = end; 
	while(i<j)
	{
		if(x<a[j])
			j--;
		else if(x>a[j]){
			a[i] = a[j];
			a[j] = x;
			i++;
		}
		else if(x<a[i]){
			a[j] = a[i];
			a[i] = x;
			j--;
		}
		else 
			i++;

	}
	return j;
}

int findMiddle(int* a, int start, int end, int n)
{
	int index;
	int middle = -1;
	
	index = partition(a, start, end);
	printf("index is %d\n",index);

	if(index==n/2){		
		middle = a[index];
	}
	else if(index>n/2){		
		end = index-1;
		return findMiddle(a, start, end, n);
	}
	else{		
		start = index+1;
		return findMiddle(a, start, end, n);
	}
	return middle;
}

int main()
{
	int i;
	int a[] = {1,2,3,2,2,2,5,4,2};
	int result = findMiddle(a, 0, 8, 9);	
	printf("middle is %d\n", result);
	getchar();
	getchar();
	return 0;
}