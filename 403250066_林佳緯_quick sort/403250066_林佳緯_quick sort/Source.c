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
	printf("403250066 �q���q�q�| �L�νn\n");
	printf("���Ƨǫe �@��%d�ӼƦr:",N);
	for (i = 0; i < N; i++)
	{
		if (i % 10 == 0)
			printf("\n");
		printf("%d ", number[i]);
	}
	QuickSort(number,0,N-1);
	printf("\n\nQuickSort���� �@��%d�ӼƦr:", N);
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

	err = fopen_s(&fp, "data.txt", "r");//�}�ɮ�
	if (err != 0)
	{
		printf("�}���ɮץ����o!\n");
		return;
	}
	//Ū���ɮ׸��
	while (1)
	{
		last = fscanf_s(fp, "%d", &number[i]);
		i++;
		if (last != 1)//��L�kŪ���ɡAlast�|�O-1 �]���i�H�P�_�O�_���Ū���F
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
			// �V�k��p��Pivot���ƭȪ���m
			while (i + 1 < MAX && number[++i] < number[left]);
			// �V����j��Pivot���ƭȪ���m
			while (j - 1 > -1 && number[--j] > number[left]);

			// �Yi,j����m��e
			//�N��d�򤺡APivot�k��w�L��Pivot�p���ƭ�
			//�N��d�򤺡APivot����w�L��Pivot�j���ƭ�            
			if (i >= j)
				break;
			// �N��Pivot�j���ƭȴ���k��A��Pivot�p���ƭȴ��쥪��
			swap(number, i, j);
		}
		swap(number, left, j);    // �NPivot���줤��
		QuickSort(number, left, j - 1);    // �索�l��C�i��ֳt�Ƨ�
		QuickSort(number, j + 1, right);   // ��k�l��C�i��ֳt�Ƨ�
	}
}
void swap(int number[] ,int i, int j)
{
	int tmp = 0;
	tmp = number[i];
	number[i] = number[j];
	number[j] = tmp;
}
