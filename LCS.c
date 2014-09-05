#include <stdio.h>
#include <stdbool.h>
#define MAX 255

// find out the maximum length of common sequencial substring of two strings

// if strA[i]==strB[j], then a[i][j] should be assigned to its previous element plus 1
// in the diagonal line ie a[i-1][j-1]

int a[MAX][MAX];

int getLCS(char*, char*, int, int);
int bigger(int, int);

int getLCS(char* strA, char* strB, int lengthA, int lengthB)
{
	int i,j;
	int commonLength = 0;
	int max = 0;
	if(strA==NULL || strB==NULL)
		return ;

	for(i=0;i<lengthA;i++)
		a[i][0] = 0;
	for(j=0;j<lengthB;j++)
		a[0][j] = 0;

	for(i=0;i<lengthA;i++){
		for(j=0;j<lengthB;j++){
			if(strA[i]==strB[j]){
				if(i>=1 && j>=1)
					a[i][j] = a[i-1][j-1]+1;
				else 
					a[i][j]	= 1;
			}
			if(max<a[i][j])
				max = a[i][j];
		}
	}
	return max;
}

int main()
{
	int i,j;
	char strA[]= {'g','c','g','c','a','a','t','g','c'};
	char strB[]= {'g','a','t','a','a','g','c','t'};
	int sizeA = sizeof(strA)/sizeof(char);
	int sizeB = sizeof(strB)/sizeof(char);
	
	int result = getLCS(strA, strB, sizeA, sizeB);	
	for(i=0;i<sizeA;i++){
		for(j=0;j<sizeB;j++){
			printf("%d ",a[i][j]);			
		}
		printf("\n");
	}
	printf("\n");
	printf("maximum sequencial result is %d\n",result);
	
	getchar();
	getchar();
	return 0;
}