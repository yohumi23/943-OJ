#include<bits/stdc++.h>
using namespace std;
const int N = 51;
struct node{
	int x, y, z;
	int t;
};
bool vis[N][N][N];
struct MGraph{
	int A, B, C;
	int arcs[N][N][N];
};
int dx[] = {1, -1, 0, 0, 0, 0};
int dy[] = {0, 0, 1, -1, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1}; 
int bfs(MGraph G){
	queue<node> q;
	q.push({0, 0, 0, 0});
	memset(vis, 0, sizeof(vis));
	vis[0][0][0] = 1;
	while(!q.empty()){
		node p = q.front();
		q.pop();
		if(p.x == G.A-1 && p.y == G.B-1 && p.z == G.C-1) return p.t;
		for(int i=0; i<6; ++i){
			int nx = p.x + dx[i];
			int ny = p.y + dy[i];
			int nz = p.z + dz[i];
			if(nx>=0 && nx<G.A && ny>=0 && ny<G.B && nz>=0 && nz<G.C && !vis[nx][ny][nz] && !G.arcs[nx][ny][nz]){
				q.push({nx, ny, nz, p.t+1});
				vis[nx][ny][nz] = 1;
			}
		}
	}
	return 9999;
	
}

int main(){
	int k, T;
	MGraph G;
	scanf("%d", &k);
	while(k--){
		scanf("%d%d%d%d", &G.A, &G.B, &G.C, &T);
		for(int i=0; i<G.A; ++i){
			for(int j=0; j<G.B; ++j){
				for(int k=0; k<G.C; ++k){
					scanf("%d", &G.arcs[i][j][k]);
				}
			}
		}
		int time = bfs(G);
		if (time > T) puts("-1");
		else cout << time << endl;
		
		
	}
	
	return 0;
}
