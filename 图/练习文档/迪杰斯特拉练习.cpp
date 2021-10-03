#include<bits/stdc++.h>
using namespace std;
const int N = 51;
const int inf = 9999999;
struct MGraph{
	int vexnum;
	int arcs[N][N];
};

void Dijkstra(MGraph G, int s){
	int i, n = G.vexnum;
	vector<int> d(n);
	vector<bool> vis(n);
	for(i=0; i<n; ++i) d[i] = G.arcs[s][i];
	for(i=0; i<n; ++i) vis[i] = 0;
	vis[s] = 1;
	for(int k=1; k<n; ++k){
		int j, m = inf;
		for(i=0; i<n; ++i){
			if(!vis[i] && d[i] < m){
				m = d[i];
				j = i;
			}
		}
		//vis[j] = 1;
		
//		if(m==inf){
//			for(i=0; i<n; ++i){
//				if(!vis[i]) d[i] = -1; //到剩下的没访问点的距离赋值为-1，即达不到。这一步很关键！！！！！！ 
//			}
//			break;
//		}
		vis[j] = 1;
		for(i=0; i<n; ++i){
			if(!vis[i] && d[i] > G.arcs[j][i] + d[j]){
				d[i] = G.arcs[j][i] + d[j];
			}
		}
	}
	for(i=0; i<n; ++i){
		
		if(d[i] == inf) d[i] = -1;
		if(s != i) printf("%d ", d[i]);
	}
	printf("\n");
}
int main(void){
	int n, s;
	MGraph G;
	scanf("%d%d", &n, &s);
	G.vexnum = n;
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			scanf("%d", &G.arcs[i][j]);
			if(G.arcs[i][j]==0) G.arcs[i][j] = inf;
		}
	}
	Dijkstra(G, s);
	return 0;
}

