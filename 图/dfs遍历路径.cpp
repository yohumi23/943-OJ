#include<bits/stdc++.h>
using namespace std;
const int N = 101;
struct MGraph{
	int vexnum;
	int arcs[N][N];
}; 
int vis[N];//标记数组
int path[N], cnt = 0;
//用深度优先搜索寻找到点s到点t的所有路径 
void dfs(MGraph G, int s, int t){
	vis[s] =  1;//当前结点正在被访问
	path[cnt++] = s;//记录当前点
	if(s == t){//已经到达终点 
		for(int i = 0; i < cnt; ++i) printf("%d ", path[i]);//把path中的所有路径结点输出 
		printf("\n");
		vis[s] = 0;//没有这句话，就是只找一条路径
		//回溯
		cnt--;
		return; 
	} 
	for(int i = 0; i < G.vexnum; ++i){//遍历邻接点 
		if(G.arcs[s][i] && !vis[i]) dfs(G, i, t);
	}
	vis[s] = 0;
	cnt--;//回溯 
} 


int main(void){
	int n, m;
	//n个点，m 条边
	MGraph G;
	memset(G.arcs, 0, sizeof(G.arcs));
	scanf("%d %d", &n, &m);
	G.vexnum = n;
	while(m--){//输入m条边 
		int x, y;
		scanf("%d%d", &x, &y);
		G.arcs[x][y] = 1; 
		G.arcs[y][x] = 1; 
	}
	dfs(G, 0, n-1);
	return 0;
}

