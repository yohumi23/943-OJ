#include<bits/stdc++.h>
using namespace std;
const int inf = 999999;
const int N = 101;
struct MGraph{
	int vexnum;
	int arcs[N][N];
};

void Prim(MGraph G){
	int i, n = G.vexnum;
	vector<int> d(n);
	vector<bool> vis(n);
	for(i=1; i<n; ++i) d[i] = G.arcs[0][i];
	for(i=0; i<n; ++i) vis[i] = 0;
	vis[0] = 1;
	int ans = 0;
	for(int k=1; k<n; ++k){
		int j = 0, m = inf;
		for(i=0; i<n; ++i){
			if(!vis[i] && d[i]<m){
				m = d[i];
				j = i;
			}
		}
		vis[j] = 1;
		ans += m;
		for(i=0; i<n; ++i){
			if(!vis[i] && d[i]>G.arcs[j][i]){
				d[i] = G.arcs[j][i];
			}
		}
	}
	printf("%d\n", ans);
}

int main(void){
	int n;
	MGraph G;
	scanf("%d", &n);
	G.vexnum = n;
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			scanf("%d", &G.arcs[i][j]);
			if(G.arcs[i][j] == 0) G.arcs[i][j] = inf;
			if(i==j) G.arcs[i][j] = 0;
		}
	}
	Prim(G);
	return 0;
}

