//练习4-2 对atof函数进行扩充,使它可以处理形如123.45е-6的科学表示法,其中,浮点数后面可能会紧跟一个e或E以及一个指数(可能有正负号)。

#define MAXLINE 1000

#include <ctype.h>
#include <stdio.h>

/* rudimentary calculator */
int main()
{
   double sum, atof(char []);
   char line[MAXLINE];
   int getline1(char line[], int max);

   while (getline1(line, MAXLINE) > 0)
	   printf("\t%g\n", atof(line));
   return 0;
}

/* getline:  get line into s, return length */
int getline1(char s[], int lim)
{
   int c, i;
   i = 0;
   while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
	   s[i++] = c;
   if (c == '\n')
	   s[i++] = c;
   s[i] = '\0';
   return i;
}

/* atof:  convert string s to double */
double atof(char s[])
{
   double val, power, en, encount = 1;
   int i, sign, sign1;
   for (i = 0; isspace(s[i]); i++)  /* skip white space */
	   ;
   sign = (s[i] == '-') ? -1 : 1;
   if (s[i] == '+' || s[i] == '-')
	   i++;
   for (val = 0.0; isdigit(s[i]); i++)
	   val = 10.0 * val + (s[i] - '0');
   if (s[i] == '.')
	   i++;
   for (power = 1.0; isdigit(s[i]); i++) {
	   val = 10.0 * val + (s[i] - '0');
	   power *= 10;
   }
   if(s[i] == 'e')
	   i++;
   sign1 = (s[i] == '-') ? -1 : 1;
   if(s[i] == '-' || s[i] == '+')
	   i++;
   for(en = 0.0; isdigit(s[i]); i++){
	   en = 10.0 * en + (s[i] - '0');
   }
   for(int j = 0; j < en; j++){
	   encount *= 10;
   }
   if(sign1 == -1){
	   encount = 1.0 / encount;
   }
   return (sign * val / power) * encount;
}