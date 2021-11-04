#include<bits/stdc++.h>
using namespace std;
/*
注意到在这个过程中，每次处理的位置所对应的距离是严格递增的，因此一旦找到终点，当时的距离就是最短距
同样基于这个原因，搜索可移动到的位置所使用的判断条件中不仅仅是不碰墙壁、不超过边界，
还有一个就是没有到达过，因为如果已经到达了这个位置，这说明已经有更短的路径到达这个位置，
这次到达这个位置的路径是更差的，不可能得到更好的最终解。
————————————————
版权声明：本文为CSDN博主「_Jason_ZHANG」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/Jason_Ranger/article/details/50768661

*/
const int N = 10;
int maze[N][N];
bool vis[N][N];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
struct node{
	int x, y;
};
//记录当前结点的上一个结点 
struct Road{
	int x, y;
}road[N][N];

void dfs(int x, int y){
	if(x==-1 && y==-1) return;
	dfs(road[x][y].x, road[x][y].y);
	printf("(%d, %d)\n", x, y); 
}
int bfs(){
	memset(vis, 0, sizeof(vis));
	queue<node> q;
	q.push({0, 0});
	vis[0][0] = 1;
	road[0][0].x = -1;
	road[0][0].y = -1;
	while(!q.empty()){
		node now = q.front(); q.pop();
		if(now.x==4 && now.y==4){
			dfs(4, 4);
			return 0;
		}
		node next; 
		for(int i=0; i<4; ++i){
			int nx = now.x + dx[i];
			int ny = now.y + dy[i];
			if(nx<0 || nx>=5 || ny<0 || ny>=5 || maze[nx][ny] || vis[nx][ny]) continue;
			next.x = nx, next.y = ny;
			vis[nx][ny] = 1;
			q.push(next);
			road[nx][ny].x = now.x;
			road[nx][ny].y = now.y;
		}
	}
}
int main(void){
	for(int i=0; i<5; ++i){
		for(int j=0; j<5; ++j){
			scanf("%d", &maze[i][j]);
		}
	}
	bfs();
	return 0;
}
