//练习4-11 修改getop函数,使其不必使用ungetch函数。提示:可以使用一个 static类型的内部变量解决该问题。

#include <ctype.h>
#include <stdio.h>
#include <string.h>

#include "getch.h"
#include "getop.h"

/* getop:  get next character or numeric operand */
int getop(char s[])
{
   int i, c;
   static int lastc = 0;
   
   if(lastc == 0)
	   c = getch();
   else{
	   c = lastc;
	   lastc = 0;
   }
   
   i = 0;
   while ((s[0] = c) == ' ' || c == '\t')
	   c = getch();
   s[1] = '\0';
   if(islower(c)){
	   while(islower(s[++i] = c = getch()));
	   s[i] = '\0';
	   if(c != EOF)
		   ungetch(c);
	   if(strlen(s) <= 1)
		   return s[0];
	   else
		   return NAME;
   }
   
   if (!isdigit(c) && c != '.' && c != '-'){
		return c;
   }
   i = 0;
   if (c == '-'){
	   if(!isdigit(s[++i] = c = getch())){
			ungetch(c);
			return '-'; 
	   }else{
		   s[0] = '-';
	   }
   }
   if (isdigit(c))    /* collect integer part */
	   while (isdigit(s[++i] = c = getch()))
		  ;
   if (c == '.')      /* collect fraction part */
	   while (isdigit(s[++i] = c = getch()))
		  ;
   s[i] = '\0';
   if (c != EOF)
	   ungetch(c);
   return NUMBER;
}

//Exercise 4-7
void ungets(char s[])
{
	int i;
	for(i = 0; s[i] != '\0'; i++);
	while(i > 0)
		ungetch(s[--i]);
}