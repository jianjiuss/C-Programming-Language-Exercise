#include <stdio.h>

void expand(char s1[], char s2[]);

int main()
{
	char s1[10] = "-1-6b-k";
	char s2[50];
	
	expand(s1, s2);
	printf("%s", s2);
}

void expand(char s1[], char s2[])
{
	char s;
	int i = 0, j = 0;
	while(s1[i] != '\0'){
		if(s1[i] != '-'){
			if(s == '\0'){
				s = s1[i];
			}else{
				char e = s1[i];
				for(char c = s; c <= e; c++){
					s2[j++] = c;
				}
				s = '\0';
			}
		}
		i++;
	}
	s2[j] = '\0';
}