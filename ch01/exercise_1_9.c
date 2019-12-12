//练习1-9 编写一个将输入复制到输出的程序,并将其中连续的多个空格用一个空格代替。

#include <stdio.h>

main()
{
	int c,lastIsSpace;
	
	while((c = getchar()) != EOF){
		if(c != ' '){
			lastIsSpace = 0;
			putchar(c);
		}else{
			if(!lastIsSpace){
				lastIsSpace = 1;
				putchar(c);
			}
		}
	}
}