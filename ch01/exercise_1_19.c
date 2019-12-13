//练习1-19 编写函数reverse (s),将字符串s中的字符顺序颠倒过来。使用该函数编写一个程序,每次颠倒一个输入行中的字符顺序。

#include <stdio.h>
#define MAXLINE 1000   /* maximum input line length */

int getline(char line[], int maxline);
reverse(char s[], int len);

int main()
{
   int len;            /* current line length */
   char line[MAXLINE];    /* current input line */
   while ((len = getline(line, MAXLINE)) > 0){
		reverse(line, len - 2);
		printf("%s", line);
   }
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

reverse(char s[], int len)
{
	char temp;
	for(int i = 0, j = len; i < j; i++, j--)
	{
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}
}