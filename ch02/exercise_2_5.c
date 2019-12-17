//练习2-5 编写函数any (s1, s2),将字符串a2中的任一字符在字符串s1中第一次 ,出现的位置作为结果返回。如果s1中不包含s2中的字符,则返回-1。(标准库函数strpbrk具有同样的功能,但它返回的是指向该位置的指针。)

#include <stdio.h>

int any(char s1[], char s2[]);

int main() {
	printf("any(\"hello jianjiuss!\", \"6j4\") -> %d\n", any("hello jianjiuss", "6j4"));
	printf("any(\"hello jianjiuss!\", \"yzx\") -> %d\n", any("hello jianjiuss", "yzx"));
	return 0;
}

int any(char s1[], char s2[])
{
	int i, j;

	for(i = 0; s1[i] != '\0'; i++){
		for(j = 0; s2[j] != '\0' && s2[j] != s1[i]; j++);
		if(s2[j] != '\0')
			return i;
	}
	
	return -1;
}