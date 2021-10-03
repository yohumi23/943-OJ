#include<bits/stdc++.h>
using namespace std;
const int N = 31;
int n, m;
char mp[N][N];
bool vis[N][N];
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {1, 0, -1, 1, -1, 1, 0, -1};
void dfs(int x, int y){
	vis[x][y] = 1;
	for(int i=0; i<8; ++i){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx>=0 && nx<n && ny>=0 && ny<m && !vis[nx][ny] && mp[nx][ny]=='@'){
			dfs(nx, ny);
		}
	}
}

void dfsTraval(){
	int ans = 0;
	memset(vis, 0,sizeof(vis));
	for(int i=0; i<n; ++i){
		for(int j=0; j<m; ++j){
			if(!vis[i][j] && mp[i][j]=='@'){
				dfs(i, j);
				ans++;
			}
		}
	}
	printf("%d\n", ans);
}
int main(void){
	while(~scanf("%d%d", &n, &m)){
		if(n==0 && m==0) break;
		for(int i=0; i<n; ++i){
			scanf("%s", mp[i]);
		}
		dfsTraval();
	}
	return 0;
}

