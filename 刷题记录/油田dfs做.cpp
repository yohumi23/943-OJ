#include<bits/stdc++.h>
using namespace std;

/**
错误原因：虽然堆内定义了n,m，但是系统栈内的n,m没有删除！！！！！！！！！！ 

*/ 
const int N = 101;
char mp[N][N];
int n, m;

bool vis[N][N];
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {1, 0, -1, 1, -1, 1, 0, -1};
void dfs(int x, int y){
//	vis[x][y] = 1;
//	for(int i=0; i<8; ++i){
//		int nx = x + dx[i];
//		int ny = y + dy[i];
//		if(nx>=0 && nx<n && ny>=0 && ny<m && !vis[nx][ny] && mp[nx][ny] == '@'){
//			dfs(nx, ny);
//		}
//	}
	vis[x][y] = 1;
	for(int i=0; i<8; ++i){
		int nowx = x + dx[i];
		int nowy = y + dy[i];
		if(nowx >= 0 && nowx < n && nowy >= 0 && nowy < m && !vis[nowx][nowy] && mp[nowx][nowy] == '@'){
			dfs(nowx, nowy);
		}
	}	
	
	
	
	
} 

void dfsTraval(){
//	int cnt = 0;
//	memset(vis, 0, sizeof(vis));
//	for(int i=0; i<n; ++n){
//		for(int j=0; j<m; ++j){
//			if(!vis[i][j] && mp[i][j] == '@'){
//				dfs(i, j);
//				cnt++;
//			}
//		}
//	}
//	printf("%d\n", cnt);

	int ans = 0;
	memset(vis, 0, sizeof(vis));
	for(int i=0; i<n; ++i){
		for(int j=0; j<m; ++j){
			if(!vis[i][j] && mp[i][j] == '@'){
				dfs(i, j);
				ans++;
			}
		}
	}
	printf("%d\n", ans);
}
//int main(void){
//	int n, m, i;//重复定义了！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！ 
//	while(~scanf("%d %d", &n, &m)){
//		if(n==0 && m==0) break;
//		for(i = 0; i < n; ++i){
//			scanf("%s", mp[i]);
//		}
//		dfsTraval();
//	}
//	return 0;
//}
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

