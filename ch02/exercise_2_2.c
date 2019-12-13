//练习2-2环语句。在不使用运算符&&或||的条件下编写一个与上面的for循环语句等价的循

#include <stdio.h>

int main()
{
	int c, i = 0, lim = 1000;
	char s[];
	while(true)
	{
		if(i >= lim - 1)
			break;
		if((c = getchar()) == '\n')
			break;
		if(c == EOF)
			break;
		s[i++] = c;
	}
	
	return 0;
}