#include<stdio.h>
#include <stdlib.h>
#define vertices 6
void dijkstra(int G[vertices][vertices], int start, int end);
void readfile(int G[vertices][vertices]);
int findPathSmall(int path[], int out[]);
int main()
{
	int G[vertices][vertices], end, starting;
	readfile(G);
	printf("403250066 �L�νn �q���q�q�|\n");
	printf("��J�_�I:");
	do
	{
		scanf_s("%d", &starting);
	} while (starting > vertices||starting<0);
	printf("��J���I:");
	do
	{
		scanf_s("%d", &end);
	} while (end > vertices||starting<0);
	dijkstra(G, starting-1, end-1);
	system("pause");
	return 0;
}

void dijkstra(int G[vertices][vertices], int start, int end)
{
	int i;
	int path[vertices] = { 999,999,999,999,999,999 };
	int out[vertices] = { 0 };
	int node;
	int list[vertices] = { 0 };
	int truePath[vertices+1]= { 0 };
	int k = 0;
	int p = 2;
	int tp[vertices+1];
	k = end;
	node = start;
	path[start] = 0;
	printf("���|:");
	while (1) 
	{
		for (i = 0; i < vertices; i++)
		{
			if (out[i] == 1)//��X�L�F�A�]�����U�@���I
				continue;
			if (path[i] > (path[node]+G[node][i])&& G[node][i]>0)//����|����n�����k�ɡA�ܧ��I���Z��
			{
				path[i] = path[node]+ G[node][i];
				truePath[i] = node+1;//��s�̵u���e�@���I
			}
		}
		out[node] = 1;//��X���I
		node = findPathSmall(path, out);//��U�@�ӿ�X���I
		
		if (node == end)
		{
			printf(" �̵u�Z����:%d\n",path[end]);
			break;
		}
	}
	while (truePath[k] != 0)
	{
		tp[p] = truePath[k];
		p++;
		k = truePath[k]-1;
	}
	tp[1] = end+1;
	printf("���|��:");
	for (int i = p - 1; i > 1; i--)
	{
		printf(" %d >", tp[i]);
	}
	printf(" %d \n", tp[1]);
}
void readfile(int G[vertices][vertices])
{
	int i = 0;
	int j = 0;
	int last = 1;
	int tem = 0;
	FILE *fp;
	errno_t err;

	//initial
	for (i = 0; i < vertices; i++)
		for (j = 0; j < vertices; j++)
			G[i][j] = 0;

	err=fopen_s(&fp,"ShortestPathMap.txt", "r");//�}�ɮ�
	if (err != 0)
	{
		printf("�}���ɮץ����o!\n");
		return;
	}
	//Ū���ɮ׸��
	while (1)
	{
		last = fscanf_s(fp, "%d", &tem);//Ū�Ĥ@�� �_�l��m
		last = fscanf_s(fp, "%d",&i);//Ū�ĤG�� �쪺��m
		last = fscanf_s(fp, "%d", &G[tem - 1][i - 1]);//�Z��
		if (last != 1)//��L�kŪ���ɡAlast�|�O-1 �]���i�H�P�_�O�_���Ū���F
			break;
	}
	for (i = 0; i < vertices; i++)
		for (j = 0; j < vertices; j++)
			G[j][i] = G[i][j];//�]���O�L��V �ҥH1��2 2�]�i�H��1
}
int findPathSmall(int path[], int out[])
{
	int i;
	int min = 999;
	int nextout;
	for (i = 0; i < vertices; i++)//��X�٨S��X�L���I �A�Z���̤p�� ��X
	{
		if (out[i] == 0)
		{
			if (min > path[i])
			{
				min = path[i];
				nextout = i;
			}
		}
	}
	return nextout;
}
