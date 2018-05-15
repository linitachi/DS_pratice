/* The author of this software is Kuan Jen Lin, FJU-EE.  Copyright (c) 2010 by
* Kuan Jen Lin. The program was designed for "Data structure" course.
*/
/*************** Notes  ******************************************/
/* Stack contains character, unlike texbook program, which contains precedence item */
/* token is a character, not a precedence item */
/* use getPrecedence() to get token's precedence */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_STACK_SIZE 101
/* in-stack precedence */
int isp[] = { 0, 19, 12, 12, 13, 13, 13, 0 };
/* incoming precedence  */
int icp[] = { 20, 19, 12, 12, 13, 13, 13, 0 };


//char infix_exp[MAX_STACK_SIZE] = "5+(4/2)*(8-1)-9";
char infix_exp[MAX_STACK_SIZE] = "";
char postfix_exp[MAX_STACK_SIZE] = "\0";

/* global stack */
char Stack[MAX_STACK_SIZE];
int Top = -1;
/* Push elemnt to stack */
void push(char item) {
	if (Top >= MAX_STACK_SIZE - 1) {
		printf("STACK is full\n");
		exit(1);
	}
	Stack[++Top] = item;
}
/* Pop element from stack */
char pop() {
	if (Top == -1) {
		printf("STACK is empty\n");
		exit(1);
	}
	return Stack[Top--];
}
typedef enum { lparen, rparen, plus, minus, times, divide, mod, eos, operand } precedence;
// return Token's precendence
precedence getPrecedence(char token) {
	switch (token) {
	case  '(': return lparen;
	case  ')': return rparen;
	case  '+': return plus;
	case  '-': return minus;
	case  '/': return divide;
	case  '*': return times;
	case  '%': return mod;
	case  '\0': return eos;
	default: return operand;
	}
}

void check_exp(char x[]) {
	int i = 0;
	int sdigit = 0;
	while (x[i] != '\0') {
		if (x[i] >= '0' && x[i] <= '9')
			if (sdigit) 
			{ 
				printf("Cannot accept double-digit operand\n"); 
				system("pause");
				exit(1);
			}
			else sdigit = 1;
		else if (x[i] == '(' || x[i] == ')' || x[i] == '+' ||
			x[i] == '-' || x[i] == '*' || x[i] == '/' || x[i] == '%')
			sdigit = 0;
		else {
			printf("Error input expression\n");
			system("pause");
			exit(1);
		}
		i++;
	}
}

void str_attach(char y[], char x) {

	int i = 0;
	char tmp;

	for (tmp = y[i]; tmp != '\0'; tmp = y[++i]);
	y[i++] = x;
	y[i] = '\0';
	return;
}

void postfix(void) {
	char token, tmpc;
	int i = 0;
	push('\0');
	for (token = infix_exp[i]; token != '\0'; token = infix_exp[++i]) {
		if (token >= '0' && token <= '9') { // a single-digit operand
			str_attach(postfix_exp, token);
		}
		else if (token == ')') {
			while ((tmpc = pop()) != '(')
				str_attach(postfix_exp, tmpc);
		}
		else {

			while (isp[getPrecedence(Stack[Top])] >= icp[getPrecedence(token)])
				str_attach(postfix_exp, pop());
			push(token);
		}
	}
	do {
		token = pop();
		str_attach(postfix_exp, token);
	} while (token != '\0');
}

double calculate(char op, double p1, double p2) {
	switch (op) {
	case '+': return p1 + p2;
	case '-': return p1 - p2;
	case '*': return p1 * p2;
	case '/': return p1 / p2;
	}
}
float eval_postfix(char postfix_exp[])
{
	double stack[MAX_STACK_SIZE];
	char tofloat[2] = { '\0' };
	int top, i;
	for (top = 0, i = 0; postfix_exp[i] != '\0'; i++)//開始把後序式放進stack
	{
		switch (postfix_exp[i]) {
		case '+'://遇到運算子就把在堆疊最上面的兩個運算元 做計算，再丟入堆疊裡面。
		case '-':
		case '*':
		case '/':
			stack[top - 2] = calculate (postfix_exp[i], stack[top - 2], stack[top - 1]);
			top--;
			break;
		default:
			tofloat[0] = postfix_exp[i];//為了轉換成float
			stack[top] = atof(tofloat);//把運算元丟進堆疊
			top = top + 1;
			break;
		}
	}
	return stack[0];
}
main() {
	printf("Please input an infix-expression (不能輸入兩位數以上的數字)\n");//提示使用者輸入
	gets(infix_exp);//取得使用者輸入的字串
	check_exp(infix_exp);//檢查是否合乎規則
	postfix();//開始做運算
	/*******************
	Your code;  evaluate a postfix expression  printf("%d", eval_postfix(postfix_exp));
	Note: the stack used in eval_postfic should be integer or float type, not char type
	************************/
	printf("\n後序式:%s\n", postfix_exp);
	printf("\n運算結果:%f\n\n", eval_postfix(postfix_exp));
	system("pause");
}


