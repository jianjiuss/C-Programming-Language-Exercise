#include <stdio.h>
#include <string.h>

int main()
{
	int strindex(char s[], char t[]);
	
	char s[] = "abcsfdsfrgdrgthtjd";
	char t[] = "frgdr";
	int i;
	i = strindex(s, t);
	
	printf("%d", i);
	return 0;
}

int strindex(char s[], char t[])
{
	int slen = strlen(s);
	int tlen = strlen(t);
	
	for(int i = slen - 1; i >= 0; i--){
		for(int j = tlen - 1, k = i; t[j] == s[k]; j--, k--){
			if(j == 0){
				return k;
			}
		}
	}
	
	return -1;
}