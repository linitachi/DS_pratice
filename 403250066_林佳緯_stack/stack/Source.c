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
	printf("�п�J�A�n���઺�r��:");
	while (1) {
		push(stack, i);//��ϥΪ̿�J�@�Ӧr �Npush�i���|
		if (stack[i] == '\n')
			break;
		i++;
		if (i == 100) {//�H�K�ϥΪ̿�J�L�j�A������W�L�}�C�j�p������
			k = 1;
			break;
		}
	}
	if (k == 0)
		length = strlen(stack) - 1;//���r�ꪺ����
	else
		length = 100 - 1;
	printf("���઺�r��:");
	while (1)
	{
		pop(stack, length);//�}�l����(pop)
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
	if (stack[i] >= 'a'&&stack[i] <= 'z')//�P�_�O�_�ŦX�W�w �ŦX�W�w���~�L�X
		printf("%c", stack[i]);
	else if(stack[i] >= 'A'&&stack[i] <= 'Z')
		printf("%c", stack[i]);
}