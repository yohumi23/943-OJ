#include<bits/stdc++.h>
using namespace std;
const int N = 101;
struct edge{
	int x, y;
	int w;
};
int fa[N];
int get(int x){
	while(x != fa[x]) x = fa[x];
	return x;
}
void Kruskal(vector<edge> e, int n){
	for(int i=1; i<=n; ++i) fa[i] = i;
	int ans = 0;
	for(int i=0; i<e.size(); ++i){
		int x = e[i].x;
		int y = e[i].y;
		int fx = get(fa[x]);
		int fy = get(fa[y]);
		if(fx != fy){
			ans += e[i].w;
			fa[fx] = fy;
		}
	}
	printf("%d\n", ans);
}
int main(void){
	int n, m;
	while(~scanf("%d", &n)){
		if(n==0) break;
		m = n*(n-1)/2;
		vector<edge> e(m);
		for(int i=0; i<m; ++i){
			scanf("%d%d%d", &e[i].x, &e[i].y, &e[i].w);
			int x;
			scanf("%d", &x);
			if(x==1) e[i].w = 0;
		}
		sort(e.begin(), e.end(), [](edge a, edge b)->bool{return a.w<b.w;});
		Kruskal(e, n);
	}
	return 0;
}

