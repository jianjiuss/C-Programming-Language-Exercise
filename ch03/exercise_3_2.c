//练习3-2 编写一个函数escape (s, t),将字符串t复制到字符串s中,并在复制过程中将换行符、制表符等不可见字符分别转换为\n、\t等相应的可见的转义字符序列。要求使用swich语句。再编写一个具有相反功能的函数,在复制过程中将转义字符序列转换为实际字符。

#include <stdio.h>
#include <stdlib.h>

void escape(char* s, char* t);

int main()
{
	char* t = "hello	jian";
	char* s = malloc(sizeof(char) * 20);
	
	escape(s, t);
	printf("%s", s);
}

void escape(char* s, char* t)
{
	while(*t != '\0'){
		switch(*t){
			case '\t':
				*s++ = '\\';
				*s = 't';
				break;
			case '\n':
				*s++ = '\\';
				*s = 'n';
				break;
			default:
				*s = *t;
				break;
		}
		t++;
		s++;
	}
	*s = '\0';
}