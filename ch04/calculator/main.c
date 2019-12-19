#include <stdio.h>
#include <stdlib.h>  /* for  atof() */
#include <math.h>
#include <string.h>

#include "getop.h"
#include "stack.h"

#define MAXOP 100  /* max size of operand or operator */

void mathfnc(char*);

/* reverse Polish calculator */
int main()
{
	int type;
	double op1,op2;
	char s[MAXOP];
	while ((type = getop(s)) != EOF) {
		switch (type) {
			case NUMBER:
			   push(atof(s));
			   break;
			case NAME:
			   mathfnc(s);
			   break;
			case '+':
			   push(pop() + pop());
			   break;
			case '*':
			   push(pop() * pop());
			   break;
			case '-':
			   op2 = pop();
			   push(pop() - op2);
			   break;
		   //Exercise 4-3
			case '%':
			   op2 = pop();
			   if(op2 != 0.0)
				   push(fmod(pop(), op2));
			   else
				   printf("error: zero divisor\n");
			   break;
			case '/':
			   op2 = pop();
			   if (op2 != 0.0)
				   push(pop() / op2);
			   else
				   printf("error: zero divisor\n");
			   break;
		   //Exercise 4-4
			case '?':
				op2 = pop();
				printf("\t%.8g\n", op2);
				push(op2);
				break;
			case 'c':
				clear();
				break;
			case 'd':
				op2 = pop();
				push(op2);
				push(op2);
				break;
			case 's':
				op1 = pop();
				op2 = pop();
				push(op1);
				push(op2);
				break;
		   case '\n':
			   printf("\t%.8g\n", pop());
			   break;
		   default:
			   printf("error: unknown command %s\n", s);
			   break;
	   }
	}
	return 0;
}

//Exercise 4-5
void mathfnc(char s[])
{
	int op2;
	if(strcmp(s, "sin") == 0)
		push(sin(pop()));
	else if(strcmp(s, "exp") == 0)
		push(exp(pop()));
	else if(strcmp(s, "pow") == 0){
		op2 = pop();
		push(pow(pop(), op2));
	}else
		printf("error: unknown command %s\n", s);
}