#include <stdio.h>
#include <stdlib.h>

typedef struct node *treePointer;
typedef struct node {
	int data;
	treePointer left_child, right_child;
}BinaryTree;
treePointer add(int num, treePointer node);
int compare(int num, treePointer node);
int main()
{
	treePointer head = 0;
	treePointer a;
	int number[1000];
	int i, n = 0;
	int findValue = 0;
	printf("請至少輸入此七筆數字7, 20, 15, 3, 40, 14, 29(空格隔開,輸入0停止):");
	while (scanf_s("%d", &number[n]))
	{
		if (number[n] == 0)
			break;
		n++;
	}
	for(i=0;i<n;i++)
	{
		head =add(number[i],head);
	}
	printf("請輸入要找的任意值:");
	scanf_s("%d", &findValue);
	if(compare(findValue, head))
		printf("Yes!");
	else
		printf("No!");
	printf("\n");
	system("pause");
	return 0;
}
treePointer add(int num, treePointer node)
{
	treePointer new_node;
	treePointer current;
	treePointer parent;
	// 建立節點
	new_node = (BinaryTree*)malloc(sizeof(BinaryTree));
	new_node->data = num;
	new_node->left_child = 0;
	new_node->right_child = 0;
	if (node == 0)    // 目前無資料
	{
		return new_node;
	}
	else
	{
		current = node; //從頭新節點插入點
		parent = current;
		while (current != 0)
		{
			parent = current;       //找新節點之父節點
			if (current->data > num)
				current = current->left_child;    //往左找
			else
				current = current->right_child;   //往右找
		}
		if (parent->data > num)    //插入此父節點左邊或右邊
			parent->left_child = new_node;
		else
			parent->right_child = new_node;
	}
	return node;    // 回傳此樹
}

int compare(int num, treePointer node)
{
	treePointer temp=node;
	while (1)
	{
		if (temp == NULL)//當沒找到子節點 就跳出
			return 0;
		else if(temp->data==num)//找到此值
			return 1;
		else if (temp->data < num)//此值比根植大 因此繼續找右子樹
			temp = temp->right_child;
		else if (temp->data > num)//此值比根植小 因此繼續找左子樹
			temp = temp->left_child;	
	}
}