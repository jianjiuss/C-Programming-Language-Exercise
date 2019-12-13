//练习1-17 编写一个程序,打印长度大于80个字符的所有输入行。

#include <stdio.h>
#define MAXLINE 1000   /* maximum input line length */

int getline(char line[], int maxline);

int main()
{
   int len;            /* current line length */
   char line[MAXLINE];    /* current input line */
   while ((len = getline(line, MAXLINE)) > 0)
	   if(len > 80)
		printf("%5d %s", len, line);
   return 0;
}
/* getline:  read a line into s, return length  */
int getline(char s[],int lim)
{
   int c, i;
   for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
	   s[i] = c;
   if (c == '\n') {
	   s[i] = c;
	   ++i;
   }
   s[i] = '\0';
   return i;
}
