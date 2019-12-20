//练习4-10 另一种方法是通过getline函数读入整个输入行,这种情况下可以不使用 getch与ungetch函数。请运用这一方法修改计算器程序。

#include <ctype.h>
#include <stdio.h>
#include <string.h>

#include "getline1.h"
#include "getop.h"

static char line[1000];
static int readIndex; 

/* getop:  get next character or numeric operand */
int getop(char s[])
{
   int i, c;
   
   if(line[readIndex] == '\0'){
	   if(getline1(line) == 0)
		   return EOF;
	   else
		   readIndex = 0;
   }
   
   i = 0;
   while ((s[0] = c = line[readIndex++]) == ' ' || c == '\t')
	   ;
   s[1] = '\0';
   if(islower(c)){
	   while(islower(s[++i] = c = line[readIndex++]));
	   s[i] = '\0';
	   if(c != EOF)
		   readIndex--;
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
	   if(!isdigit(s[++i] = c = line[readIndex++])){
			readIndex--;
			return '-'; 
	   }else{
		   s[0] = '-';
	   }
   }
   if (isdigit(c))    /* collect integer part */
	   while (isdigit(s[++i] = c = line[readIndex++]))
		  ;
   if (c == '.')      /* collect fraction part */
	   while (isdigit(s[++i] = c = line[readIndex++]))
		  ;
   s[i] = '\0';
   if (c != EOF)
	   readIndex--;
   return NUMBER;
}