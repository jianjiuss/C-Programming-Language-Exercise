//练习2-6 编写一个函数setbits(x, p, n, y),该函数返回对x执行下列操作后·的结果值:将x中从第p位开始的n个(二进制)位设置为y中最右边n位的值, x的其余各位保持不变。

#include <stdio.h>
#include <stdlib.h>

int setbits(int x, int p, int n, int y);

int main()
{
	int x, p, n, y, r;
	char s[100];

	x = 0b11011011001110;
	p = 8;
	n = 5;
	y = 0b10100110000101;
	
	r = setbits(x, p, n, y);
	itoa(r, s, 2);
	printf("%s", s);
	
	return 0;
}

int setbits(int x, int p, int n, int y)
{
	int bitmask;
	bitmask = ~0 << p | (unsigned int)~0 >> (32 - (p - n));
	x &= bitmask;
	y = (y << (p - n)) & ~bitmask;
	return x | y;
}