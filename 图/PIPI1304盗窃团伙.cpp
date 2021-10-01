#include<bits/stdc++.h>
#define inf 10000000
using namespace std;
const int N = 501;

struct MGraph{
	int vexnum;
	int arcs[N][N];
}; 

int Floyd(MGraph G){
	int n = G.vexnum;
	for(int k=1; k<=n; ++k){//当前考虑的中转点 
		for(int i=1; i<=n; ++i){
			for(int j=1; j<=n; ++j){
				G.arcs[i][j] = min(G.arcs[i][j], G.arcs[i][k] + G.arcs[k][j]);
				//以k为中转进行更新两个点之间的最短距离 
			}
		}
	}
}
int main(){
	MGraph G;
	int n, m;
	int u, v, w;
	scanf("%d%d", &n, &m);
	G.vexnum = n;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			if(i==j) G.arcs[i][j] == 0;
			else{
				G.arcs[i][j] = inf;
			}
		}
	}	
	for(int j=1; j<=m; ++j){
		scanf("%d%d%d", &u, &v, &w);		
		G.arcs[u][v] = G.arcs[v][u] = w;
	}
	Floyd(G);
	vector<int> dis(n+1);//记录每个门店到最远门店的距离
	for(int i=1; i<=n; ++i){
		m = 0;
		for(int j=1; j<=n; ++j) m= max(m, G.arcs[i][j]);
		dis[i] = m;
	} 
	m = inf;
	int j = 0;
	for(int i=1; i<=n; ++i){
		 if(dis[i] < m){
		 	m = dis[i];
		 	j = i;
		 }
	} 
//	if(m==inf) puts("What a pity!");
//	else{
//		printf("%d %d\n", j, m);
//	} 
	for(int i=1; i<=n; ++i){
		if(G.arcs[j][i] == inf){
			puts("What a pity!");
			break;
		}
	}
	printf("%d %d\n", j, m);
	return 0;
	
	
} 
