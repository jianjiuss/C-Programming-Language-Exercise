//练习1-8 编写一个统计空格、制表符与换行符个数的程序

#include <stdio.h>

/* count lines in input */
main()
{
   int c, nl, tabCount, spaceCount;
   nl = tabCount = spaceCount = 0;
   while ((c = getchar()) != EOF)
	   if (c == '\n')
		   ++nl;
	   else if(c == ' ')
		   ++spaceCount;
	   else if(c == '\t')
		   ++tabCount;
   printf("%d\n%d\n%d\n", nl, spaceCount, tabCount);
}