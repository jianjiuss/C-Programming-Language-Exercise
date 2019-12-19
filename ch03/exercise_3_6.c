//练习3-6 修改itoa函数,使得该函数可以接收三个参数。其中,第三个参数为最小字段宽度。为了保证转换后所得的结果至少具有第三个参数指定的最小宽度,在必要时应在所得结果的左边填充一定的空格。
#include <stdio.h>

void itob(int n, char s[], int l);
void reverse(char s[],int sSize);

int main()
{
	char s[1000];
	itob(34536456, s, 9);
	printf("%s", s);
}

void itob(int n, char s[], int l)
{
   int i, sign, k, negative;
   i = 0;
   negative = n < 0;
   do {      /* generate digits in reverse order */
	   k = n % 10;
	   s[i++] = (k > 0 ? k : k * -1) + '0';  /* get next digit */
   } while ((n /= 10) != 0);    /* delete it */
   if (negative)
	   s[i++] = '-';
   while(i < l)
	   s[i++] = ' ';
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