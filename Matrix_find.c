#include <stdio.h>
#include <stdbool.h>

#define MAX 16

// find whether the target is in the matrix
// matrix is ascending from left to right and from top to bottom

bool find(int* matrix, int rows, int columns, int target)
{
	bool flag = false;
	int row = 0;
	int column = columns-1;
	if(matrix!=NULL){
		while(row<rows && column>=0){
			if(matrix[row*columns+column]==target){
				flag = true;
				break;
			}
			else if(matrix[row*columns+column]>target)
				column--;
			else
				row++;
		}
	}
	return flag;
}

int main()
{
	int matrix[MAX] = {1,2,8,9,2,4,9,12,4,7,10,13,6,8,11,15};
	if(find(matrix,4,4,7))
		printf("in\n");
	else
		printf("not in\n");
	getchar();
	getchar();
	return 0;
}