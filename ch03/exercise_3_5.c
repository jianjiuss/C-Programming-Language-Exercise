//练习3-5 编写函数itob (n, s, b),将整数n转换为以b为底的数,并将转换结果以字符的形式保存到字符串s中。例如, itob (n, s, 16)把整数n格式化成十六进制整数保存在s中。
#include <stdio.h>

void itob(int n, char s[], int b);
void reverse(char s[],int sSize);

int main()
{
	char s[1000];
	itob(34536456, s, 16);
	printf("%s", s);
}

void itob(int n, char s[], int b)
{
	int i = 0, residue, divisor = n;
	
	do{
		residue = divisor % b;
		divisor /= b;
		s[i++] = residue < 10 ? '0' + residue : 'A' + (residue - 10);
	}while(divisor != 0);
	
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