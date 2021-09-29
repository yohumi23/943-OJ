#include<bits/stdc++.h>
using namespace std;
const int N = 101;

struct edge{//边结点 
	int x, y;//端点
	int w;//权值
};
int fa[N];//定义并查集
int get(int x){//找父亲 
	if(x==fa[x]) return x;
	return fa[x] = get(fa[x]);
} 
void Kruskal(vector<edge> e, int n){//假设边结点已经排好序 
	for(int i = 1; i <= n; ++i) fa[i] = i;//初始化并查集
	int ans = 0;
	for(int i = 0; i < e.size(); ++i){
		int fx = get(e[i].x);
		int fy = get(e[i].y);
		if(fx != fy){//这两个端点没有连通，需要合并 
			ans += e[i].w;
			fa[fx] = fy;
		}
	} 
	printf("%d\n", ans);
}
int main(void){
	int i, n;
	while(~scanf("%d", &n)) {
		if(n==0) break;
		int m= n*(n-1)/2;//边的数量 
		vector<edge> e(m);
		for(i = 0; i < m; ++i){
			scanf("%d%d%d", &e[i].x, &e[i].y, &e[i].w);
			int p;
			scanf("%d",&p);
			if(p==1) e[i].w = 0;//免费修建 	
		}
		sort(e.begin(), e.end(), [](edge a, edge b)->bool{return a.w<b.w;});
		//考试时只需写sort(e.begin(), e.end());再加个按权值对边结点进行排序
		//或者默认是排好序的 
		Kruskal(e, n);
	}
	
	return 0;
}

