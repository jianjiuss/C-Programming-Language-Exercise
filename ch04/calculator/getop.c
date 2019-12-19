#include <ctype.h>
#include <stdio.h>
#include <string.h>

#include "getch.h"
#include "getop.h"

/* getop:  get next character or numeric operand */
int getop(char s[])
{
   int i, c;
   
   i = 0;
   while ((s[0] = c = getch()) == ' ' || c == '\t')
	   ;
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