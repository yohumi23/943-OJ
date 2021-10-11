/*
define 不用加分号 
*/
#include<bits/stdc++.h>
using namespace std;
//Prim
#define inf 9999
const int N = 150;
bool vis[N]; 
struct MGraph{
	int vexnum;
	int arcs[N][N];
}; 
void Prim(MGraph G){
	memset(vis, 0, sizeof(vis));
	int n = G.vexnum, i;
	int ans = 0; 
	vector<int> d(n+1);
	vis[1] = 1;
	for(int i=1; i<=n; ++i){
		d[i] = G.arcs[1][i];
	}
	for(int k=1; k<n; ++k){
		int min = inf;
		int  j = 0;
		for(i=1; i<=n; ++i){
			if(!vis[i] && d[i] < min){
				min = d[i];
				j = i;
			}
		}
		//vis[j] = 1;
		ans += min;
		vis[j] = 1;
		for(i=1; i<=n; ++i){
			if(!vis[i] && d[i] >  G.arcs[j][i]){
				d[i] = G.arcs[j][i] ;
			}
		}
	}
	printf("%d\n", ans);

}
int main(void){
	MGraph G;
	int n, m;
	while(~scanf("%d", &n))	{
		if(n==0) break;
		G.vexnum = n;
		for(int i=1; i<=n; ++i){
			for(int j=1; j<=n; ++j){
				G.arcs[i][j]  = inf;
			}
		}
		m = n*(n-1) / 2;
		for(int i=0; i<m; ++i){
			int u, v, w, s;
			scanf("%d %d %d %d", &u, &v, &w, &s);
			if(s){
				G.arcs[u][v] = G.arcs[v][u] = 0; 
			}else{
				G.arcs[u][v] = G.arcs[u][v] = w;
			}
		}
		Prim(G);
	}
	return 0;
}

