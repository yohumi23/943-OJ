#include<bits/stdc++.h>
using namespace std;
const int N = 101;
struct MGraph{
	int vexnum;
	int arcs[N][N];
}; 
int vis[N];//�������
int path[N], cnt = 0;
//�������������Ѱ�ҵ���s����t������·�� 
void dfs(MGraph G, int s, int t){
	vis[s] =  1;//��ǰ������ڱ�����
	path[cnt++] = s;//��¼��ǰ��
	if(s == t){//�Ѿ������յ� 
		for(int i = 0; i < cnt; ++i) printf("%d ", path[i]);//��path�е�����·�������� 
		printf("\n");
		vis[s] = 0;//û����仰������ֻ��һ��·��
		//����
		cnt--;
		return; 
	} 
	for(int i = 0; i < G.vexnum; ++i){//�����ڽӵ� 
		if(G.arcs[s][i] && !vis[i]) dfs(G, i, t);
	}
	vis[s] = 0;
	cnt--;//���� 
} 


int main(void){
	int n, m;
	//n���㣬m ����
	MGraph G;
	memset(G.arcs, 0, sizeof(G.arcs));
	scanf("%d %d", &n, &m);
	G.vexnum = n;
	while(m--){//����m���� 
		int x, y;
		scanf("%d%d", &x, &y);
		G.arcs[x][y] = 1; 
		G.arcs[y][x] = 1; 
	}
	dfs(G, 0, n-1);
	return 0;
}

