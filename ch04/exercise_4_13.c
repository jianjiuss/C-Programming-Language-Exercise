//练习4-13 编写一个递归版本的reverse (s)函数,以将字符串s倒置。
#include <stdio.h>
#include <string.h>

void reverse(char[], int, int);

int main()
{
	char s[] = "abcdefghijk";
	reverse(s, 0, strlen(s) - 1);
	printf("%s", s);
}

void reverse(char s[], int left, int right)
{
	int temp;
	
	if(left >= right)
		return;
	
	temp = s[left];
	s[left] = s[right];
	s[right] = temp;
	
	reverse(s, ++left, --right);
}