#include<bits/stdc++.h>
using namespace std;
const int N = 101;
//深度优先搜索dfs
struct MGraph{
	int vexnum;
	int arcs[N][N];
}; 
bool vis[N];//标记访问数组
void dfs(MGraph G, int s){
	int i;
	vis[s] = 1;
	printf("%d ", s);
	for(i=0; i<G.vexnum; ++i){
		if(G.arcs[s][i]!=0 && !vis[i]) dfs(G, i);
	}
} 
void dfsTraval(MGraph G){
	memset(vis, 0, sizeof(vis));
	for(int i=0; i<G.vexnum; ++i){
		if(!vis[i]) dfs(G, i);
	}
}
int main(void){
	int n;
	MGraph G;
	scanf("%d", &n);
	G.vexnum = n;
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			scanf("%d", &G.arcs[i][j]);
		}
	} 
	dfsTraval(G);
	return 0;
}
/**
5
0 1 1 0 0
1 0 0 1 0
1 0 0 1 1
0 1 1 0 1
0 0 1 1 0

*/
