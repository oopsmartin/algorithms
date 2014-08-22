#include <stdio.h>

// count the number of number k appeared in array

// using binary find to get the first k and the last k appeared in the array

int getFirstK(int* a, int length, int k, int start, int end)
{	
	int middle;
	if(k<a[0] || k>a[length-1] || start>end)
		return -1;
	else{		
		middle = (start+end)/2;		
		if(a[middle]==k){
			if(middle==0 || (middle>0 && a[middle-1]<k))
				return middle;
			else {
				end = middle-1;
				return getFirstK(a, length, k, start, end);
			}
		}
		else if(a[middle]>k){
			if(end<1)
				return -1;
			else{
				end = middle-1;
				return getFirstK(a, length, k, start, end);
			}
		}
		else{			
				start = middle+1;
				return getFirstK(a, length, k, start, end);			
		}
	}
}

int getLastK(int* a, int length, int k, int start, int end)
{
	int middle;
	if(k<a[0] || k>a[length-1] || start>end)
		return -1;
	else{
		middle = (start+end)/2;
		if(a[middle]==k){
			if(middle==length-1 || (middle<length-1 && a[middle+1]>k))
				return middle;
			else{
				start = middle+1;
				return getLastK(a, length, k, start, end);
			}
		}
		else if(a[middle]<k){
			start = middle+1;
			return getLastK(a, length, k, start, end);
		}
		else{
			if(end<1)
				return -1;
			else{
				end = middle-1;
				return getLastK(a, length, k, start, end);
			}
		}
	}
}

int main(){
	int a[] = {1,2,2,2,5,6,7,8,9,10};
	int length = sizeof(a)/sizeof(int);
	int start = getFirstK(a, length, 2, 0, length-1);
	int end = getLastK(a, length, 2, 0, length-1);
	int count = 0;
	if(start==-1 || end==-1)
		count = -1;
	else
		count = end-start+1;
	printf("count is %d\n",count);
	getchar();
	getchar();
	return 0;
}