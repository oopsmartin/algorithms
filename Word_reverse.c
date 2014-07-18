#include <stdio.h>

void reverse(char* input)
{
	char* ptr = input;// paceful pointer
	char* start = input;
	char* end = input;
	while(*ptr++ !='\0')
	{
		
		// split words by space
		if(*ptr ==' ' || *ptr == '\0')
		{
			printf("13\n");
			// end pointers to the end of a word
			
			end = ptr-1;
			
			printf("start is %c ",*start);
			printf("end is %c\n",*end);

			while(start < end)
			{
				
				char tmp = *start;								
				(*start) = (*end);				
				(*end) = tmp;				
				start++;
				end--;
				printf("hehe\n");
			}
			printf("%s\n",ptr);

			start = ptr+1;
			
		}

	}
	printf("26\n");
	start = input;
	end = ptr-2;
	
	while(start < end)
	{
		char tmp = *start;
		*start = *end;
		*end = tmp;
		start++;
		end--;
	}
	printf("38\n");
	
}

void testString(char * str)
{
	str[0] = '!';
	printf("now the str is %s\n", (*str));
}

int main()
{
	char str[]="what on earth is that";
	reverse(str);
	//testString(str);
	printf("%s\n", str);
	getchar();
	getchar();
}