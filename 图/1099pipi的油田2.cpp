#include<bits/stdc++.h>
using namespace std;
const int N =101;
bool vis[N][N];
int m, n;
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {0, 1, -1, 1, -1, 0, 1, -1};
char mp[N][N];//地图
void dfs(int x, int y){//当前访问到x,y点 
	vis[x][y] = 1;
	for(int i = 0; i < 8; ++i){
		int nx = x + dx[i];
		int ny = y + dy[i];
		//得到的新坐标
		if(nx>=0 && nx<m && ny>=0 && ny<n && !vis[nx][ny]  &&  mp[nx][ny] == '@' ) {
			//先判断边界范围
			dfs(nx, ny); //搜索相邻的油田 
		}
	} 
} 
void dfsTraval(){
	int i, j, cnt = 0;
	memset(vis, 0, sizeof(vis));//标记数组初始化不能忘
	for(i = 0; i < m; ++i){
		for(j = 0; j < n; ++j){
			if(!vis[i][j] && mp[i][j]=='@'){
				dfs(i, j);//跳出说明当前连通图遍历完毕 
				cnt++;
			}
		}
	}
	printf("%d\n", cnt);
}

int main(void){
	int i;
	while(~scanf("%d%d", &m, &n)){
		if(n==0&&m==0) break;
		for(i = 0; i < m; ++i){
			scanf("%s", mp[i]);
		}
		dfsTraval();
	
	
	}
	return 0;
}

