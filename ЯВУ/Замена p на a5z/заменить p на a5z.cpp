#include <stdio.h>

#define MAXLINE 1000

int main(void)
{
	char line[MAXLINE];
	char res[MAXLINE];
	char* in_ptr = line;
	char* out_ptr = res;
	gets_s(line);
	while (*in_ptr != '\0')
	{
		if (*in_ptr == 'p')
		{
			*out_ptr++ = 'a';
			*out_ptr++ = '5';
			*out_ptr++ = 'z';
		}
		else
		{
			*out_ptr++ = *in_ptr;
		}
		in_ptr++;
	}
	*out_ptr = '\0';
	puts(res);
	return 0;
}




