#include<bits/stdc++.h>
using namespace std;
const int N = 10000;
struct MGraph{
	int vexnum;
	int arcs[N][N];
};
struct node{
	int i;
	int wage;
};
bool vis[N];
void dfs(MGraph G){
	
	
	
	
	
	
}

int main(){
	MGraph G;
	scanf("%d %d", &n, &m);
	G.vexnum = n;
	memset(G.arcs, 0, sizeof(0));
	for(int i=0; i<m; ++i){
		int s, t;
		scanf("%d %d", &s, &t);
		G.arcs[t][s] = 1; 
	} 
	dfsTraval(G);
	
}
 
