/*
错误原因：
1.标记数组应该列成三维
2.看清输入
3.明确入队前标记
4.看清return，如果成功要return，失败也要return 

*/
#include<bits/stdc++.h>
using namespace std;
const int N= 51;
int dx[] = {1, -1, 0, 0, 0, 0};
int dy[] = {0, 0, 1, -1, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};
struct MGraph{
	int A, B, C;
	int arcs[N][N][N];
};
struct node{
	int x, y, z, t;
};
bool vis[N][N][N];
int bfs(MGraph G){
	int i;
	memset(vis, 0, sizeof(vis));
	queue <node> q;
	q.push({0, 0, 0, 0});
	vis[0][0][0] = 1;
	while(!q.empty()){
		node p = q.front();
		q.pop();
//		if(p.x==A-1 && p.y==B-1 && p.z==C-1) return p.t + 1;
		if(p.x==A-1 && p.y==B-1 && p.z==C-1) return p.t;
		for(i=0; i<6; ++i){
			int nx = p.x + dx[i];
			int ny = p.y + dy[i];
			int nz = p.z + dz[i];
			if(nx>=0 && nx<A && ny>=0 && ny<G.B && nz>=0 && nz<C && !G.arcs[nx][ny][nz] && !vis[nx][ny][nz]){
				q.push({nx, ny, nz, p.t+1});
				vis[nx][ny][nz] = 1;
			}
		}
		return 9999999; 
	}
}



int main(void){
	MGraph  G;
	int k;
	scanf("%d", &k);
	while(k--){
		int A, B, C, T;
		scanf("%d %d %d %d", &G.A, &G.B, &G.C, &T);
		for(int i=0; i<G.A; ++i){
			for(int j=0; j<G.B; ++j){
				for(int k=0; k<G.C; ++k){
					scanf("%d", &G.arcs[i][j][k]);
				}
			}
		} 
		int time = bfs(G);
		if(time<=T) printf("%d\n", time);
		else printf("-1\n");	
	}

	return 0;
}

