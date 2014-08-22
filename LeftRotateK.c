#include <stdio.h>

// ptr rotate k bit of an string
// e.g abcdefg (2)-> cdefgab

void ptrRotateK(char* str, int length, int k)
{
	int i;
	char* ptr = str;
	char* start = str;	
	char* end = str;

	if(k>length || str==NULL)
		return;
	else{		
		// firstly reverse ptr string and right string individually
		for(i=0;i<k/2;i++){
			char tmp = ptr[i];
			ptr[i] = ptr[k-1-i];
			ptr[k-1-i] = tmp;
		}
		printf("now ptr is %s\n",ptr);
		for(i=k;i<(length-k)/2+k;i++){
			char tmp = ptr[i];
			ptr[i] = ptr[length+k-1-i];
			ptr[length+k-1-i] = tmp;
		}		
		printf("2\n");
		// then reverse all char sequence		
		end = str+length-1;
		for(i=0;i<length/2;i++){
			char tmp = *start;
			*start = *end;
			*end = tmp;
			start++;
			end--;
		}
	}
}

int main()
{
	char a[] = {'a','b','c','d','e','f'};
	int length = sizeof(a)/sizeof(char);
	printf("length is %d\n",length);
	ptrRotateK(a,length,2);
	printf("%s\n",a);
	getchar();
	getchar();
	return 0;
}