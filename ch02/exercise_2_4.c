//squeeze (sl, s2),将字符串s1中任何与字符串s2中字符匹配的字符都删除。

#include <stdio.h>

void squeeze(char s[], char c[]);

int main()
{
	char s[] = "aaaaabcaaaaaabcaaaa";
	char c[] = "bca";
	
	squeeze(s, c);
	printf("%s", s);
	
	return 0;
}

/* squeeze:  delete all c from s */
void squeeze(char s1[], char s2[])
{
	int i, j, k, delete;
	k = 0;
	for (i = 0; s1[i] != '\0'; i++){
		for(j = 0; s2[j] != '\0'; j++)
			if(s2[j] == s1[i])
				break;
		if(s2[j] == '\0')
			s1[k++] = s1[i];
	}
	s1[k] = '\0';
}