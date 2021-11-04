#include<bits/stdc++.h>
using namespace std;
const int N = 50;
struct MGraph{
	int A, B, C;
	int arcs[N][N][N];
};
bool vis[N][N][N];
struct Node{
	int x, y, z, t;
};

int dx[] = {1, -1, 0, 0, 0, 0};
int dy[] = {0, 0, 1, -1, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};

int bfs(MGraph G){
	memset(vis, 0, sizeof(vis));
	queue<Node> q;
	q.push({0, 0, 0, 0});
	vis[0][0][0] = 1;
	while(!q.empty()){
		Node now = q.front();
		q.pop();
		if(now.x==G.A-1 && now.y==G.B-1 && now.z==G.C-1) return now.t;
		for(int i=0; i<6; ++i){
			int nx = now.x + dx[i];
			int ny = now.y + dy[i];
			int nz = now.z + dz[i];
			if(nx>=0 && nx<G.A && ny>=0 && ny<G.B && nz>=0 && nz<G.C && !G.arcs[nx][ny][nz] && !vis[nx][ny][nz]){
				q.push({nx, ny, nz, now.t+1});
				vis[nx][ny][nz] = 1;
			}
		}
	}
	return 9999;
}


int main(void){
	MGraph G;
	int n;
	scanf("%d", &n);
	while(n--){
		int A, B, C, T;
		scanf("%d%d%d%d", &A, &B, &C, &T);
		G.A = A; G.B = B; G.C = C; 
		for(int i=0; i<A; ++i){
			for(int j=0; j<B; ++j){
				for(int k=0; k<C; ++k){
					scanf("%d", &G.arcs[i][j][k]);
				} 
			}
		} 
		int time = bfs(G);
		if(time > T) printf("-1\n");
		else printf("%d\n", time);
	}
	
	return 0;
}

