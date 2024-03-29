#include <stdio.h>
#define BUFSIZE 100
//Exercise 4-8
//#define BUFSIZE 1

//Exercise 4-9
static int buf[BUFSIZE];    /* buffer for ungetch */
static int bufp = 0;         /* next free position in buf */
int getch(void)  /* get a (possibly pushed-back) character */
{
   return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c)   /* push character back on input */
{
   if (bufp >= BUFSIZE)
	   printf("ungetch: too many characters\n");
   else
	   buf[bufp++] = c;
}