#include<bits/stdc++.h>
using namespace std;
const int N = 101;
struct LGraph{
	int vexnum;
	vector<int> vertices[N];
}; 
bool vis[N];
void bfs(LGraph G, int s){
	queue<int> q;
	q.push(s);
	vis[s] = 1;
	while(!q.empty()){
		//int p = q.top();
		int p = q.front();
		q.pop();
		printf("%d", p);
		for(int i=0; i<G.vertices[p].size(); ++i){
			if(!vis[G.vertices[p][i]]) {
				q.push(G.vertices[p][i]);
				vis[G.vertices[p][i]] = 1;
			}
		}
	}

}
void bfsTraval(LGraph G){
	memset(vis, 0, sizeof(vis));
	for(int i=0; i<G.vexnum; ++i){
		if(!vis[i]) bfs(G, i);
	}
}

int main(void){
	int n;
	return 0;
}

