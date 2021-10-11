#include<bits/stdc++.h>
#define inf 99999
using namespace std;
const int N = 101;
struct MGraph{
	int vexnum;
	int arcs[N][N];
};

void Prim(MGraph G){
	int i, n = G.vexnum;
	vector<int> d(n);
	vector<bool> v(n);
	for(i=0; i<n; ++i) d[i] = G.arcs[0][i];
	for(i=0; i<n; ++i) v[i] = 0;
	v[0] = 1;
	int ans = 0;
	for(int k=1; k<n; ++k){
		int m = inf, j = 0;
		for(i=0; i<n; ++i){
			if(!v[i] && d[i]<m){
				m = d[i];
				j = i;
			}
		}
		ans += m;
		v[j] = 1;
		//ans += m;
		for(i=0; i<n; ++i){
			if(!v[i] && d[i] > G.arcs[j][i]){
				d[i]  = G.arcs[j][i];
			}
		}
	}
	printf("%d\n", ans);
}
int main(void){
	int n, i, j;
	MGraph G;
	scanf("%d", &n);
	G.vexnum = n;
	for(i=0; i<n; ++i){
		for(j=0; j<n; ++j){
//			if(i==j) G.arcs[i][j] = 0;
//			else{
//				scanf("%d", &G.arcs[i][j]);
//				if(G.arcs[i][j] == 0) G.arcs[i][j] = inf;
//			}
			scanf("%d", &G.arcs[i][j]);
			if(G.arcs[i][j]==0) G.arcs[i][j] = inf;
			if(i==j) G.arcs[i][j] = 0;
		}
	}
	Prim(G);
	return 0;
}

