#include<bits/stdc++.h>
using namespace std;
const int N = 51;
struct MGraph{
	int A, B, C;
	int arcs[N][N][N];
};
struct node{
	int x, y, z;//三维坐标
	int t;//时间 
};
bool vis[N][N][N]; 
int dx[] = {1, -1, 0, 0, 0, 0};
int dy[] = {0, 0, 1, -1, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};
//广度优先搜索
int bfs(MGraph G){
	queue<node> q;
	q.push({0, 0, 0, 0});//把起点入队
	memset(vis, 0, sizeof(vis));
	vis[0][0][0] = 1;//标记已访问 
	while(!q.empty()){//bfs搜索 
		node p = q.front();
		q.pop();
		if(p.x == G.A-1 && p.y == G.B-1 && p.z == G.C-1) return p.t;//到达终点
		for(int i=0; i<6; ++i){
			int nx = p.x + dx[i];
			int ny = p.y + dy[i];
			int nz = p.z + dz[i];
			if(nx>=0 && nx<G.A && ny>=0 && ny<G.B && nz>=0 && nz<G.C && G.arcs[nx][ny][nz] == 0 && vis[nx][ny][nz]==0 ){
				q.push({nx, ny, nz, p.t+1});//下一步的时间等于当前时间加1 
				vis[nx][ny][nz] = 1;//标记已经走过 
			}
		}
	} 
	return 9999999;//没有找到，就返回下一个 
} 
int main(void){
	int k;
	scanf("%d", &k);
	while(k--){//k组数据 
		MGraph G;
		int T;
		scanf("%d%d%d%d", &G.A, &G.B, &G.C, &T);
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

