//练习2-10 重新编写将大写字母转换为小写字母的函数lower,并用条件表达式替代其中的if-else结构。
#include <stdio.h>
char lower(char c);

int main() {
  char c;
  while ((c = getchar()) != EOF) {
    putchar(lower(c));
  }
}

char lower(char c) {
  return 'A' <= c && c <= 'Z' ? c - 'A' + 'a' : c;
}