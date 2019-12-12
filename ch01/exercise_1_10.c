//练习1-10 编写一个将输入复制到输出的程序,并将其中的制表符替换为\t,把回退符替换为\b,把反斜杠替按为\\。这样可以将制表符和回退符以可见的方式显示出来。
#include <stdio.h>
#include <conio.h>

main()
{
	int c;
	
	//getchar()在缓冲流做了处理打不出回退符
	//while((c = getchar()) != EOF)
	while((c = _getch()) != EOF){
		if(c == '\t'){
			putchar('\\');
			putchar('t');
		}else if(c == '\b'){
			putchar('\\');
			putchar('b');
		}else{
			putchar(c);
		}
	}
}