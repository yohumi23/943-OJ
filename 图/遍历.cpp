#include<bits/stdc++.h>
using namespace std;
const int N = 100;
struct MGraph{
	int vexnum;
	int arcs[N][N]; 
}; 

struct LGraph{
	int vexnum;
	vector<int> vertices[N];
};
bool vis[N];

//深度优先搜索
//邻接矩阵 
void dfs(MGraph G, int x){//x是访问的当前结点 
	printf("%d ", x);//处理当前结点，和题目需求有关，
	//如cnt++，去计算访问点数，如果cnt==N，则为连通图 
	vis[x] = 1;
	for(int i = 0; i < G.vexnum; ++i){
		if(G.arcs[x][i] && !vis[i]) dfs(G, i);
	} 
}
//调用dfs
void desTraval(MGraph G){
	memset(vis, 0, sizeof(vis));//对访问数组初始化 
	for(int i = 0; i < G.vexnum; ++i){
		if(!vis[i]) dfs(G, i);//如果没有被访问就对i进行深度优先遍历 ，确保所有的顶点全部遍历到 
	}
} 

//广度优先搜素
//使用邻接矩阵 
void bfs(LGraph G, int x){
	queue<int> q;
	q.push(x);//将第一个点入队
	vis[x] = 1;
	while(!q.empty()) {
		int p = q.front();//取出队首 
		printf("%d ", p);//将当前顶点进行访问操作
		q.pop();//出队 
		for(int i = 0; i < G.vertices[p].size(); ++i) {
			int y = G.vertices[p][i];
			if(!vis[y]){
				q.push(y);
				vis[i] = 1;//入队时标记为访问，避免重复入队 
			}
		}
	}
}

void bfsTraval (LGraph G){
	memset(vis, 0, sizeof(vis));//初始化
	for(int i = 0; i < G.vexnum; ++i){
		if(!vis[i]) bfs(G, i);
	}
}
int main(void){

	return 0;
}

