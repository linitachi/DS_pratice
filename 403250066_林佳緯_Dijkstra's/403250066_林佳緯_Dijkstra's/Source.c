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
	printf("403250066 林佳緯 電機電通四\n");
	printf("輸入起點:");
	do
	{
		scanf_s("%d", &starting);
	} while (starting > vertices||starting<0);
	printf("輸入終點:");
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
	printf("路徑:");
	while (1) 
	{
		for (i = 0; i < vertices; i++)
		{
			if (out[i] == 1)//輸出過了，因此換下一個點
				continue;
			if (path[i] > (path[node]+G[node][i])&& G[node][i]>0)//當路徑有更好的走法時，變更點的距離
			{
				path[i] = path[node]+ G[node][i];
				truePath[i] = node+1;//更新最短的前一個點
			}
		}
		out[node] = 1;//輸出此點
		node = findPathSmall(path, out);//找下一個輸出的點
		
		if (node == end)
		{
			printf(" 最短距離值:%d\n",path[end]);
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
	printf("路徑為:");
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

	err=fopen_s(&fp,"ShortestPathMap.txt", "r");//開檔案
	if (err != 0)
	{
		printf("開啟檔案失敗囉!\n");
		return;
	}
	//讀取檔案資料
	while (1)
	{
		last = fscanf_s(fp, "%d", &tem);//讀第一格 起始位置
		last = fscanf_s(fp, "%d",&i);//讀第二格 到的位置
		last = fscanf_s(fp, "%d", &G[tem - 1][i - 1]);//距離
		if (last != 1)//當無法讀取時，last會是-1 因此可以判斷是否資料讀完了
			break;
	}
	for (i = 0; i < vertices; i++)
		for (j = 0; j < vertices; j++)
			G[j][i] = G[i][j];//因為是無方向 所以1到2 2也可以到1
}
int findPathSmall(int path[], int out[])
{
	int i;
	int min = 999;
	int nextout;
	for (i = 0; i < vertices; i++)//找出還沒輸出過的點 ，距離最小的 輸出
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
