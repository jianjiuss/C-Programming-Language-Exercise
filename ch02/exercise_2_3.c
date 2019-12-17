//练习2-3 编写函数htoi (s),把由十六进制数字组成的字符串(包含可选的前缀0x或0X)转换为与之等价的整型值。字符串中允许包含的数字包括: 0~9.a~f以及A~F.

#include <stdio.h>
#include <stdlib.h>

int htoi(char s[]);

int main()
{	
	unsigned long result;
	char *c, *s;
	s = c = (char*)malloc(sizeof(char) * 100);
	while((*s++ = getchar()) != EOF);
	
	result = htoi(c);
	printf("%u", result);

	free(c);
	return 0;
}

int htoi(char s[])
{
	int hexdigital, i, inhex, digit;
	unsigned long result;
	
	i = 0;
	result = 0;
	digit = 0;
	
	if(s[i] == '0'){
		i++;
		if(s[i] == 'X' || s[i] == 'x')
			i++;
	}
	
	inhex = 1;
	for(; inhex; i++){
		if(s[i] >= '0' && s[i] <= '9'){
			hexdigital = s[i] - '0';
		}else if(s[i] >= 'a' && s[i] <= 'f'){
			hexdigital = s[i] - 'a' + 10;
		}else if(s[i] >= 'A' && s[i] <= 'F'){
			hexdigital = s[i] - 'A' + 10;
		}else{
			inhex = 0;
		}
		
		if(inhex){
			result = result * 16 + hexdigital;
			digit++;
		}
	}
	
	return result;
}