//练习2-8 编写一个函数rightrot (x, n),该函数返回将x循环右移(即从最右端移出的位将从最左端移入) n (二进制)位后所得到的值。
#include <stdio.h>
#include <stdlib.h>

int rightrot(int x, int n);
int bitlen(unsigned x);

int main()
{
	int x, n, r;
	char s[100];

	x = 0b11011011001110;
	n = 5;
	
	r = rightrot(x, n);
	itoa(r, s, 2);
	printf("%s", s);
}

int bitlen(unsigned x)
{
	int l;
	for(l = 0; x; x >>= 1)
		l++;
	return l;
}

int rightrot(int x, int n)
{
	int bitmask, l, y;
	
	l = bitlen((unsigned)x);
	bitmask = ~0 << n;
	y = x & ~bitmask;
	x = (unsigned)x >> n;
	return x | (y << (l - n));
}