#include <stdio.h>

#include "getch.h"

int main()
{
	int c1,c2;
	c1 = getch();
	putchar(c1);
	
	ungetch(c1);
	c1 = getch();
	putchar(c1);
	
	c2 = getch();
	putchar(c2);
	
	ungetch(c1);
	ungetch(c2);
}