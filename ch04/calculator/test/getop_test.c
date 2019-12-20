#include <stdio.h>

#include "getop.h"

int main()
{
	char s[100];
	getop(s);
	printf("%s", s);
	ungets(s);
	getop(s);
	printf("%s", s);
	getop(s);
	printf("%s", s);
}