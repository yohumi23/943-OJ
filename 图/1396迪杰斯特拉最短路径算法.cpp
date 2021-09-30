#include<bits/stdc++.h>
using namespace std;
const int N = 51;
const int inf = 999999;
struct MGraph{
	int vexnum;
	int arcs[N][N];
};
int vis[N][N];

int Dijkstra(MGraph G, int s){
	int i, n = G.vexnum;
	vector<int> dis(n);//¾àÀëÏòÁ¿ 
	for(i=0; i<n; ++i){
		dis[i] = G.arcs[s][i];
	}
	vis[s] = 1; 
} 
int main(void){
	MGraph G;
	int n, s;
	scanf("%d %d", &n, &s);
	G.vexnum = n;
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			scanf("%d", &G.arcs[i][j]);
		}
	}
	DijKstra(G, s);
	return 0;
}

