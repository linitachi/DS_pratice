#include<stdio.h>
#include <stdlib.h>
#define MAX 100
int readfile(int number[MAX]);
void QuickSort(int number[MAX], int left, int right);
void swap(int number[],int a, int b);
int main()
{
	int number[MAX] = { 0 };
	int i = 0;
	int N;
	N=readfile(number);
	printf("403250066 電機電通四 林佳緯\n");
	printf("未排序前 共有%d個數字:",N);
	for (i = 0; i < N; i++)
	{
		if (i % 10 == 0)
			printf("\n");
		printf("%d ", number[i]);
	}
	QuickSort(number,0,N-1);
	printf("\n\nQuickSort完成 共有%d個數字:", N);
	for (i = 0; i < N; i++)
	{
		if (i % 10 == 0)
			printf("\n");
		printf("%d ", number[i]);
	}
	printf("\n");
	system("pause");
	return 0;

}
int readfile(int number[MAX])
{
	int i = 0;
	int last = 1;
	FILE *fp;
	errno_t err;

	err = fopen_s(&fp, "data.txt", "r");//開檔案
	if (err != 0)
	{
		printf("開啟檔案失敗囉!\n");
		return;
	}
	//讀取檔案資料
	while (1)
	{
		last = fscanf_s(fp, "%d", &number[i]);
		i++;
		if (last != 1)//當無法讀取時，last會是-1 因此可以判斷是否資料讀完了
			return i-1;
	}
}
void QuickSort(int number[MAX],int left,int right)
{
	int i = 0;
	int j = 0;
	if (left < right) 
	{
		i = left;
		j = right + 1;
		while (1)
		{
			// 向右找小於Pivot的數值的位置
			while (i + 1 < MAX && number[++i] < number[left]);
			// 向左找大於Pivot的數值的位置
			while (j - 1 > -1 && number[--j] > number[left]);

			// 若i,j的位置交叉
			//代表範圍內，Pivot右邊已無比Pivot小的數值
			//代表範圍內，Pivot左邊已無比Pivot大的數值            
			if (i >= j)
				break;
			// 將比Pivot大的數值換到右邊，比Pivot小的數值換到左邊
			swap(number, i, j);
		}
		swap(number, left, j);    // 將Pivot移到中間
		QuickSort(number, left, j - 1);    // 對左子串列進行快速排序
		QuickSort(number, j + 1, right);   // 對右子串列進行快速排序
	}
}
void swap(int number[] ,int i, int j)
{
	int tmp = 0;
	tmp = number[i];
	number[i] = number[j];
	number[j] = tmp;
}
