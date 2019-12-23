//练习3-4 在数的对二的补码表示中,我们编写的itoa函数不能处理最大的负数,即n等于-2^(字长-1)的情况。请解释其原因。修改该函数,使它在任何机器上运行时都能打印出正确的值。

#include <stdio.h>

void itoa(int n, char s[]);
void reverse(char s[],int sSize);

int main()
{
	char s[1000];
	itoa(-2147483648, s);
	printf("%s", s);
}

/* itoa:  convert n to characters in s */
void itoa(int n, char s[])
{
   int i, k, negative;
   i = 0;
   negative = n < 0;
   do {      /* generate digits in reverse order */
	   k = n % 10;
	   s[i++] = (k > 0 ? k : k * -1) + '0';  /* get next digit */
   } while ((n /= 10) != 0);    /* delete it */
   if (negative)
	   s[i++] = '-';
   s[i] = '\0';
   reverse(s, i);
}

void reverse(char s[],int sSize)
{
	for(int i = 0, j = sSize - 1; i < j; i++, j--){
		char temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}
}