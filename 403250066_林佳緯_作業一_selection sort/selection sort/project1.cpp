#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b);
void SelectionSort(int a[], int n);
int main()
{
	int n = 100;//陣列索引值
	int a[100];//至多X個資料
	SelectionSort(a, n);
	system("pause");
}
void SelectionSort(int a[], int n) 
{
	int i, j;
	int last = 2;
	int Min;
	FILE *fp;
	fp = fopen("input.txt", "r");//開檔案
	if (fp == NULL)
	{
		printf("開啟檔案失敗囉!");
		return;
	}
	for (i = 0; i < n ; i++)
	{
		//讀取檔案資料
		last=fscanf(fp, "%d", &a[i]);
		//當無法讀取時，last會是-1 因此可以判斷是否資料讀完了
		if (last == -1)
		{
			n = i;//把陣列索引值更改成 數字的總數。
			//如果數字只有5個 那n就會等於5
			break;
		}
	}
	fclose(fp);//關檔案
	fp = fopen("output.txt", "w");//開啟檔案
	if (fp == NULL)
	{
		printf("開啟檔案失敗囉!");
		return;
	}
	//開始selection sort
	for (i = 0; i < n - 1; i++)
	{
		Min = i;
		for (j = i + 1; j < n; j++) {
			if (a[j] < a[Min]) {//找到較小的元素
				Min = j;//把Min設成最小值陣列索引
			}
		}
		if (Min != i)//如果Min有更改
		{
			swap(&a[i], &a[Min]);//跟最小值做交換
		}
		fprintf(fp,"%d\n", a[i]);//寫入檔案
	}
	fprintf(fp, "%d\n", a[n-1]);//寫入檔案 5個數字的話 陣列索引值為0~4 因此要n-1
	fclose(fp);
	for (i = 0; i < n; i++)
	{
		printf("第%d個數字=%d\n", i+1, a[i]);//印出排序完得結果
	}
}
void swap(int *a, int *b)
{
	int tem = 0;
	tem = *a;
	*a = *b;
	*b = tem;
}
