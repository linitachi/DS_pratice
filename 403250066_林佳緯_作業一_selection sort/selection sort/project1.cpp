#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b);
void SelectionSort(int a[], int n);
int main()
{
	int n = 100;//�}�C���ޭ�
	int a[100];//�ܦhX�Ӹ��
	SelectionSort(a, n);
	system("pause");
}
void SelectionSort(int a[], int n) 
{
	int i, j;
	int last = 2;
	int Min;
	FILE *fp;
	fp = fopen("input.txt", "r");//�}�ɮ�
	if (fp == NULL)
	{
		printf("�}���ɮץ����o!");
		return;
	}
	for (i = 0; i < n ; i++)
	{
		//Ū���ɮ׸��
		last=fscanf(fp, "%d", &a[i]);
		//��L�kŪ���ɡAlast�|�O-1 �]���i�H�P�_�O�_���Ū���F
		if (last == -1)
		{
			n = i;//��}�C���ޭȧ�令 �Ʀr���`�ơC
			//�p�G�Ʀr�u��5�� ��n�N�|����5
			break;
		}
	}
	fclose(fp);//���ɮ�
	fp = fopen("output.txt", "w");//�}���ɮ�
	if (fp == NULL)
	{
		printf("�}���ɮץ����o!");
		return;
	}
	//�}�lselection sort
	for (i = 0; i < n - 1; i++)
	{
		Min = i;
		for (j = i + 1; j < n; j++) {
			if (a[j] < a[Min]) {//�����p������
				Min = j;//��Min�]���̤p�Ȱ}�C����
			}
		}
		if (Min != i)//�p�GMin�����
		{
			swap(&a[i], &a[Min]);//��̤p�Ȱ��洫
		}
		fprintf(fp,"%d\n", a[i]);//�g�J�ɮ�
	}
	fprintf(fp, "%d\n", a[n-1]);//�g�J�ɮ� 5�ӼƦr���� �}�C���ޭȬ�0~4 �]���nn-1
	fclose(fp);
	for (i = 0; i < n; i++)
	{
		printf("��%d�ӼƦr=%d\n", i+1, a[i]);//�L�X�Ƨǧ��o���G
	}
}
void swap(int *a, int *b)
{
	int tem = 0;
	tem = *a;
	*a = *b;
	*b = tem;
}
