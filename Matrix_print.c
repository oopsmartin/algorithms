#include <stdio.h>

// this function will print matrix sprially by clockwise order
// Be careful for the boundaries

void printClockwise(int a[][5], int column, int row, int start)
{
	int endX = column-1-start;
	int endY = row-1-start;
	// the first element is a[start][start]
	int i;
	
	// step 1 : print a line ->
	for(i=start;i<=endX;i++)
		printf("%d ",a[start][i]);
	printf("\n");

	// step 2 : print a column from top to bottom
	if(endY>start){
		for(i=start+1;i<=endY;i++)
			printf("%d ",a[i][endX]);
		printf("\n");
	}

	// step 3 : print a line  <-
	if(endX>start && endY>start){
		for(i=endX-1;i>=start;i--)
			printf("%d ",a[endY][i]);
		printf("\n");
	}

	// step 4 : print a column from bottom to top
	if(endX>start && endY>start+1){
		for(i=endY-1;i>start;i--)
			printf("%d ",a[i][start]);
		printf("\n");
	}
}

void printMartrix(int a[][5], int column, int row)
{
	
	int start = 0;

	while(column > start*2 && row > start*2)
	{
		printClockwise(a, column, row, start);
		start++;
		printf("start is %d\n",start);
	}
}

int main()
{
	int a[5][5] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};
	printMartrix(a,5,5);
	getchar();
	getchar();
	return 0;
}