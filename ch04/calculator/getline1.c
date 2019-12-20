#include <stdio.h>

int getline1(char s[])
{
	static int c;
	int i;
	
	if(c == EOF)
		return 0;
	
	i = 0;
	while((c = getchar()) != '\n' && c != EOF)
		s[i++] = c;
	if(c == '\n')
		s[i++] = c;
	s[i] = '\0';
	
	return i;
}