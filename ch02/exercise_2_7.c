//练习2-7 编写一个函数invert(x, p, n),该函数返回对×执行下列操作后的结·果值:将x中从第p位开始的n个(二进制)位求反(即, 1变成0, 0变成1), x的其余各位保持不变。
#include <stdio.h>
#include <stdlib.h>

int invert(int x, int p, int n);

int main()
{
	int x, p, n, r;
	char s[100];

	x = 0b11011011001110;
	p = 8;
	n = 5;
	
	r = invert(x, p, n);
	itoa(r, s, 2);
	printf("%s", s);
}

int invert(int x, int p, int n)
{
	int bitmask, y;
	bitmask = ~0 << p | (unsigned int)~0 >> (32 - (p - n));
	y = ~bitmask & x;
	x &= bitmask;
	return x | (~y & ~bitmask);
}