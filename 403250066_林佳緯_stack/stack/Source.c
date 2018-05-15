#include <stdio.h>
#include <stdlib.h>
void push(char stack[],int i);
void pop(char stack[],int i);
int main()
{
	char stack[100] = "";
	int i = 0;
	int k = 0;
	int length=0;
	printf("請輸入你要反轉的字串:");
	while (1) {
		push(stack, i);//當使用者輸入一個字 就push進堆疊
		if (stack[i] == '\n')
			break;
		i++;
		if (i == 100) {//以免使用者輸入過大，直接把超過陣列大小的忽略
			k = 1;
			break;
		}
	}
	if (k == 0)
		length = strlen(stack) - 1;//找到字串的長度
	else
		length = 100 - 1;
	printf("反轉的字串:");
	while (1)
	{
		pop(stack, length);//開始反轉(pop)
		length--;
		if (length ==-1)
			break;
	}
	printf("\n");
	system("pause");
}
void push(char stack[],int i)
{
	stack[i] = getchar();
}
void pop(char stack[],int i)
{
	if (stack[i] >= 'a'&&stack[i] <= 'z')//判斷是否符合規定 符合規定的才印出
		printf("%c", stack[i]);
	else if(stack[i] >= 'A'&&stack[i] <= 'Z')
		printf("%c", stack[i]);
}