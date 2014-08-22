#include <stdio.h>

void reverse(char* input)
{
	char* ptr = input;// paceful pointer
	char* start = input;
	char* end = input;
	while(*ptr++ !='\0')
	{		
		// split words by space
		// *ptr=='\0' is to handle the last word
		if(*ptr ==' ' || *ptr == '\0')
		{
			// end pointers to the end of a word			
			end = ptr-1;
			while(start < end)
			{				
				char tmp = *start;								
				(*start) = (*end);				
				(*end) = tmp;				
				start++;
				end--;				
			}
			start = ptr+1;			
		}
	}	
	start = input;
	end = ptr-2;// minus '\0'	
	while(start < end)
	{
		char tmp = *start;
		*start = *end;
		*end = tmp;
		start++;
		end--;
	}	
}

void testString(char * str)
{
	str[0] = '!';
	printf("now the str is %s\n", (*str));
}

int main()
{
	// str must be an array
	// because arrays are in heap which are changable
	// while pointers are in stack that are unchangable!!!
	char str[]="what on earth is that";
	reverse(str);
	//testString(str);
	printf("%s\n", str);
	getchar();
	getchar();
}