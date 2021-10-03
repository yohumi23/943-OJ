/*
用dfs寻找所有s到t的路径 
*/ 
#include<bits/stdc++.h>
using namespace std;
const int N = 101;
struct MGraph{
	int vexnum;
	int arcs[N][N];
};
int vis[N];
int path[N], cnt = 0;
void dfs(MGraph G, int s, int t){
	vis[s] = 1;
	path[cnt++] = s;
	if(s==t){
		for(int i=0; i<cnt; ++i) printf("%d ", path[i]);
		putchar('\n');
		vis[s] = 0;
		cnt--;
		return;
	}
	for(int i=0; i<G.vexnum; ++i){
		if(!vis[i] && G.arcs[s][i]) dfs(G, i, t);
	}
	vis[s] = 0;
	cnt--;
}
int main(void){
	int n, m;
	MGraph G;
	memset(G.arcs, 0, sizeof(G.arcs));
	scanf("%d %d", &n, &m);
	G.vexnum = n;
	while(m--){
		int x, y;
		scanf("%d%d", &x, &y);
		G.arcs[x][y] = G.arcs[y][x] = 1;
	}
	dfs(G, 0, n-1);
	return 0;
}

