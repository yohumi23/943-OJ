#include<bits/stdc++.h>
using namespace std;
int mp[5][5];
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, 1, -1, 0};
bool vis[5][5];
void dfs(int x, int y){
	vis[x][y] = 1;
	printf("(%d %d)\n", x, y);
	if(x==4 && y==4) exit(0);
	for(int i=0; i<4; ++i){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx>=0 && nx<5 && ny>=0 && ny<5 && !vis[nx][ny] && mp[nx][ny]==0){
			dfs(nx, ny);
		}
	}
	
}

void dfsTraval(){
	dfs(0, 0);
}
int main(void){
	for(int i=0; i<5; ++i){
		for(int j=0; j<5; ++j){
			scanf("%d", &mp[i][j]);
		} 
	}
	dfsTraval();
	return 0;
}

