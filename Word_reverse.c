#include <stdio.h>

void reverse(char* input)
{
	char* ptr = input;// paceful pointer
	int start = 0;
	int end = 0;
	int count = 0;
	while(*ptr++ !='\0')
	{
		end++;
		count++;
		// split words by space
		if(*ptr ==' ')
		{
			printf("13\n");
			end--;// end pointers to the end of a word

			while(start < end)
			{
				printf("ha\n");
				char tmp = input[start];
				input[start] = input[end];
				input[end] = tmp;
				start++;
				end--;
				printf("hehe\n");
			}
			
		}

	}
	printf("26\n");
	start = 0;
	end = count-2;
	
	while(start < end)
	{
		char tmp = input[start];
		input[start] = input[end];
		input[end] = tmp;
		start++;
		end--;
	}
	printf("38\n");
}

int main()
{
	char* str="what on earth is that";
	reverse(str);
	printf("%s\n", str);
	getchar();
	getchar();
}