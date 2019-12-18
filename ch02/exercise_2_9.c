//练习2-9 在求对二的补码时,表达式x&= (x-1)可以删除×中最右边值为1的一个二进制位。请解释这样做的道理。用这一方法重写bitcount函数,以加快其执行速度。
#include <stdio.h>

int bitcount(unsigned x);

int main()
{
	int x, n;
	char s[100];

	x = 0b11011011001110;
	
	n = bitcount((unsigned)x);
	printf("%d", n);
}

/* bitcount:  count 1 bits in x */
int bitcount(unsigned x)
{
   int b;
   for (b = 0; x != 0; x &= x - 1)
	   b++;
   return b;
}