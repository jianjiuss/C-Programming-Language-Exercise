//练习1-18 编写一个程序,删除每个输入行末尾的空格及制表符,并删除完全是空格的行。

#include <stdio.h>
#define MAXLINE 1000   /* maximum input line length */

int getline(char line[], int maxline);
int remove1(char s[], int len);

int main()
{
   int len;            
   int max;    
   char line[MAXLINE];
   char longest[MAXLINE];
   max = 0;
   while ((len = getline(line, MAXLINE)) > 0){
	   if(remove1(line, len - 2) >= 0)
		   printf("%s", line);
   }

   return 0;
}

int remove1(char s[], int len)
{
	while(len >= 0 && (s[len] == ' ' || s[len] == '\t'))
		len--;
	
	if(len >= 0){
		s[++len] = '\n';
		s[++len] = '\0';
	}
	
	return len;
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