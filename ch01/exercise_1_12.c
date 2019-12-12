//练习1-12 编写一个程序,以每行一个单词的形式打印其输入。
#include <stdio.h>
#define IN   1  /* inside a word */
#define OUT  0  /* outside a word */
/* count lines, words, and characters in input */
main()
{
   int c, state;
   state = OUT;
   while ((c = getchar()) != EOF) {
	   if (c == ' ' || c == '\n' || c == '\t'){
		   if(state == IN){
			   state = OUT;
			   putchar('\n');
		   }
	   }
	   else{
		   state = IN;
		   putchar(c);
	   }
   }
}