// 练习2-1 编写一个程序以确定分别由signed及unsigned限定的char, short int与long类型变量的取值范围。采用打印标准头文件中的相应值以及直接计算两种方式实现。后一种方法的实现较困难一些,因为要确定各种浮点类型的取值范围。
#include <stdio.h>
#include <limits.h>

int main()
{
	printf("char: signed:%d-%d. unsigned:%d-%d.\n", SCHAR_MIN, SCHAR_MAX, 0, UCHAR_MAX);
	printf("short: signed:%d-%d. unsigned:%d-%d.\n", SHRT_MIN, SHRT_MAX, 0, USHRT_MAX);
	printf("int: signed:%d-%d. unsigned:%d-%u.\n", INT_MIN, INT_MAX, 0, UINT_MAX);
	printf("long: signed:%ld-%ld. unsigned:%d-%u.\n", LONG_MIN, LONG_MAX, 0, ULONG_MAX);
	
	printf("min signed char:%d\n", - (unsigned char) ~0 >> 1);
	printf("max signed char:%d\n", (unsigned char) ~0 >> 1);
	printf("max unsigned char:%d\n", (unsigned char) i);
	return 0;
}