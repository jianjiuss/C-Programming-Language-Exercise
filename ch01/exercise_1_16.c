//练习1-16 修改打印最长文本行的程序的主程序main,使之可以打印任意长度的输入行的长度,并尽可能多地打印文本。

#include <stdio.h>
#define MAXLINE 1000   /* maximum input line length */

int getline(char line[], int maxline);

int main()
{
   int len;            /* current line length */
   char line[MAXLINE];    /* current input line */
   while ((len = getline(line, MAXLINE)) > 0)
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
