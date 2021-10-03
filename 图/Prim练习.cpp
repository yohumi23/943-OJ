#include<bits/stdc++.h>
using namespace std;
const int N = 51;
const int inf = 99999;
struct MGraph{
	int vexnum;
	int arcs[N][N];
};
int Prim(MGraph G){
	int i, n = G.vexnum;
	int ans = 0;
	vector<int> d(n);
	vector<int> v(n);
	for(i=0; i<n; ++i) v[i] = 0;
	for(i=1; i<n; ++i) d[i] = G.arcs[0][i];
	v[0] = 1;
	for(int k=1; k<n; ++k){
		int j = 0, m = inf;
		for(i=0; i<n; ++i){
			if(!v[i] && d[i] < m){
				m = d[i];
				j = i;
			}
		}
		v[j] = 1;
		ans += m; 
		for(i=0; i<n; ++i){
			if(!v[i] && G.arcs[j][i] < d[i]){
				d[i] = G.arcs[j][i];
			}
		}
	}
	printf("%d\n", ans);
}

int main(){
	int n;
	MGraph G;
	scanf("%d", &n);
	G.vexnum = n;
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			scanf("%d", &G.arcs[i][j]);
			if(G.arcs[i][j]==0) G.arcs[i][j] = inf;
			if(i==j) G.arcs[i][j] = 0;
		}
	}
	Prim(G);
	
	return 0;
	
	
}
