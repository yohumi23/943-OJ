#include<bits/stdc++.h>
#define inf 999999
using namespace std;
const int N = 51;
struct MGraph{
	int vexnum;
	int arcs[N][N];
};
int vis[N];

int Dijkstra(MGraph G, int s){
	int i, n = G.vexnum;
	vector<int> dis(n);//距离向量 
	for(i=0; i<n; ++i){
		dis[i] = G.arcs[s][i];
	}
	vis[s] = 1; 
	for(int t = 1; t < n; ++t){//执行n-1次，即寻找剩余的n-1个结点的最短路径 
		int j, m = inf;
		for(i=0; i<n; ++i){
			if(!vis[i] && dis[i]<m){//找到最小的 
				j = i;
				m = dis[i];
			}
		} 
		if(m==inf){//没有找到最小路径，即当前节点出度为0 
			for(i=0; i<n; ++i){
				if(!vis[i]) dis[i] = -1;//题目规定：不存在从源点至相应顶点的路径，输出-1。 
			}
			break;//结束本次寻找 
		}
		vis[j] = 1;//j是当前选中的点
		//更新dis[] 
		//与Prim算法的唯一区别在更新的策略不同 
		for(i=0; i<n; ++i){
			if(!vis[i] && dis[i] > dis[j] + G.arcs[j][i])
				dis[i] = dis[j] + G.arcs[j][i];//更新操作 
		} 
	}
	for(i=0; i<n; ++i){
		if(s!=i)printf("%d ", dis[i]);
	}
	printf("\n");
} 
 
int main(void){
	MGraph G;
	int n, s;
	scanf("%d %d", &n, &s);
	G.vexnum = n;
	memset(vis, 0, sizeof(vis));
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			scanf("%d", &G.arcs[i][j]);
			if(G.arcs[i][j] == 0) G.arcs[i][j] = inf;
		}
	}
	Dijkstra(G, s);
	return 0;
}

