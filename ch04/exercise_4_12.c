//练习4-12 运用printd函数的设计思想编写一个递归版本的itoa函数,即通过递归调用把整数转换为字符串。
#include <stdio.h>

int itoa(int n, char s[]);

int main()
{
	char s[1000];
	itoa(-2147483648, s);
	printf("%s", s);
}

/* itoa:  convert n to characters in s */
int itoa(int n, char s[])
{
   int i, sign, k, negative;
   i = 0;
   
   if(n == 0){
	   s[i++] = '0';
	   s[i] = '\0';
	   return i;
   }
   
   	if(n / 10 == 0){
		if(n < 0){
			s[i++] = '-';
			s[i++] = n * -1 + '0';
		}else{
			s[i++] = n + '0';
		}
		s[i] = '\0';
		return i;
	}

	k = n % 10;
	i = itoa(n / 10, s);
	s[i++] = (k > 0 ? k : -k) + '0';
	s[i] = '\0';
	return i;
}