#include<bits/stdc++.h> 
#define inf 99999
using namespace std;
const int N = 101;

struct MGraph{
	int vexnum;//点数 
	int arcs[N][N];//邻接矩阵 
};

struct LGraph{
	int vexnum;//点数 
	vector<int> vertices[N];//邻接表 
};

//普利姆算法 
void Prim(MGraph G){
	int i, n = G.vexnum;//j代表 
	vector<int> d(n);//代表当前集合到剩余点的距离
	vector<int> v(n);//标记访问数组 
	for(i = 1; i < n; ++i) d[i] = G.arcs[0][i];//初始时当前集合，（此时集合只有0）
	v[0] = 1;//避免一个点多次进入当前集合 
	int ans = 0; 
	for(int k = 1; k < n; ++k){
		int j = 0, m = inf;//j代表寻找的边的端点，m代表当前最小花费 
		for(i = 0; i < n; ++i){
			if(!v[i] && d[i] < m){
				m = d[i];//m会越来越小，直到达到最小值跳出，同时记录最近点和最小距离 
				j = i;//记录距离当前集合距离最小的点 
			}
		}
		ans += m;//选中该边，增加花费
		v[j] = 1;//标记已经访问
		//需要更新当前集合到其他点的最小距离 
		for(i = 0; i < n; ++i){
			if(!v[i] && d[i] > G.arcs[j][i]){
				d[i] = G.arcs[j][i];
			}
		} 
	} 
	printf("%d", ans);
}
int main(){
	MGraph G;
	int i, j, n;
	scanf("%d", &n);
	G.vexnum = n;
	for(i = 0; i < n; ++i){
		for(j = 0; j < n; ++j){
			scanf("%d", &G.arcs[i][j]);
			if(G.arcs[i][j]==0) G.arcs[i][j] = inf;
		}
	}	
	Prim(G);
	
	return 0;
}
