//练习4-14 定义宏swap(t, x, y)以交换t类型的两个参数。(使用程序块结构会对你有所帮助。)
#include <stdio.h>
#define swap(t,x,y) {\
						t temp = x;\
						x = y;\
						y = temp;\
					}

int main()
{
	int x = 10, y = 5;
	swap(int, x, y);
	printf("x:%d y:%d",x,y);
}