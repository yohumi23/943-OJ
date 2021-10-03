#include<bits/stdc++.h>
using namespace std;
const int N = 501;
const int inf = 999999;
struct MGraph{
	int vexnum;
	int arcs[N][N]; 
};

void Floyd(MGraph G){
	int n = G.vexnum;
	for(int k=1; k<=n; ++k){
		for(int i=1; i<=n; ++i){
			for(int j=1; j<=n; ++j){
				G.arcs[i][j] = min(G.arcs[i][j], G.arcs[i][k]+G.arcs[k][j]);
			}
		}
	}
}
int main(void){
	MGraph G;
	int n, m;//n是点数,m是路径数
	scanf("%d%d", &n, &m); 
	G.vexnum = n;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			if(i==j) G.arcs[i][j] = 0;
			else
				G.arcs[i][j] = inf;
		}
	}
	while(m--){
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		G.arcs[u][v] = G.arcs[v][u] = w;
	}
	Floyd(G);
	vector<int> dis(n+1);
	for(int i=1; i<=n; ++i){
		m = -999;
		for(int j=1; j<=n; ++j) m = max(m, G.arcs[i][j]);
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
	for(int i=1; i<=n; ++i){
		if(G.arcs[j][i] == inf){
			puts("What a pity!");
			break;
		}
	}
	printf("%d %d\n", j, m);
	return 0;
}

